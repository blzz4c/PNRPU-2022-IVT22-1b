//метод открытой адресации
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <cstring>
#include <ctime>
#include <fstream>
using namespace std;

string f[5] = { "Подъянов", "Васильев", "Молотов", "Ленин", "Тарасов" };
string i[5] = { "Роман", "Илья", "Артём", "Сергей", "Марат" };
string o[5] = { "Павлович", "Денисович", "Андреевич", "Глебович", "Николаевич" };
string d[5] = { "22.09.04", "12.08.00", "01.03.03", "07.09.03", "03.09.01" };
string p[5] = { "678344", "583937", "583974", "930052", "143525" };
int n = 0;
char date[255];
FILE* file;

struct Human {
    char fio[255];
    char dateofbirth[255];
    char number[255];
};

Human* m = new Human;

void change_value(char* c, string r) {
    for (int k = 0; k < r.length(); k++) {
        c[k] = r[k];
    }
    c[r.length()] = '\0';
}

int rand_num() {
    return rand() % 5;
}

int get_key() {
    double key = 0;
    for (int k = 0; k < 9; k += 3) {
        string s = "";
        s += date[k];
        s += date[k + 1];
        key += stoi(s);
    }
    key *= 0.75;
    key -= (int)key;
    return (int)(n * key);
}

void create_hash() {
    cout << "Введите количество элементов: ";
    cin >> n;
    Human* t = new Human[n]{};
    int collision = 0;
    for (int k = 0; k < n; k++) {
        change_value(date, d[rand_num()]);
        int l = get_key();
        if (t[l].fio[0] != NULL) {
            collision++;
        }
        while(t[l].fio[0] != NULL) {
            l = (l + 1) % n;
        }
        change_value(t[l].fio, f[rand_num()] + ' ' + i[rand_num()] + ' ' + o[rand_num()]);
        change_value(t[l].dateofbirth, date);
        change_value(t[l].number, p[rand_num()]);
    }
    delete[] m;
    m = t;
    cout << "Хеш-таблица создана! " << "Коллизий: " << collision << '\n';
}

void show_hash() {
    if (n) {
        for (int k = 0; k < n; k++) {
            cout << m[k].fio << ' ' << m[k].dateofbirth << ' ' << m[k].number << '\n';
        }
        cout << "-------------------------------\n";
    }
    else {
        cout << "Хеш-таблица пуста!\n";
    }
}

void del_person() {
    if (n) {
        cout << "Введите дату: ";
        cin.getline(date, 255);
        cin >> date;
        for (int k = 0; k < n; k++) {
            if (!strcmp(m[k].dateofbirth, date)) {
                change_value(m[k].fio, "NULL");
                change_value(m[k].dateofbirth, "NULL");
                change_value(m[k].number, "NULL");
            }
        }
    }
    else {
        cout << "Хеш-таблица пуста!\n";
    }
}

void find_person() {
    if (n) {
        cin.get();
        cout << "Введите дату: ";
        cin.getline(date, 255);
        int l = get_key();
        for (int k = 0; k < n; k++) {
            if (!strcmp(m[l].dateofbirth, date)) {
                cout << l + 1 << '\n';
                return;
            }
            l = (l + 1) % n;
        }
        cout << "-1\n";
    }
    else {
        cout << "Хеш-таблица пуста, операция не возможна!\n";
    }
}

void add_person() {
    int l;
    cout << "Введите номер нового элемента: ";
    cin >> l;
    if ((l <= n && strcmp(m[l - 1].dateofbirth, "NULL")) || l > n) {
        Human* t = new Human[n >= l ? n + 1 : l];
        for (int k = 0; k < l - 1 && k < n; k++) {
            t[k] = m[k];
        }
        for (int k = l; k <= n; k++) {
            t[k] = m[k - 1];
        }
        for (int k = n; k < l; k++) {
            change_value(t[k].fio, "NULL");
            change_value(t[k].dateofbirth, "NULL");
            change_value(t[k].number, "NULL");
        }
        n = n >= l ? n + 1 : l;
        delete[] m;
        m = t;
    }
    change_value(m[l - 1].fio, f[rand_num()] + ' ' + i[rand_num()] + ' ' + o[rand_num()]);
    change_value(m[l - 1].dateofbirth, d[rand_num()]);
    change_value(m[l - 1].number, p[rand_num()]);

}

void read_hash() {
    if ((file = fopen("Hash.txt", "rb")) == NULL) {
        cout << "Ошибка чтения файла\n";
    }
    else if (!feof(file)) {
        fread(&n, sizeof(n), 1, file);
        Human* t = new Human[n];
        for (int k = 0; k < n; k++) {
            fread(&t[k], sizeof(Human), 1, file);
        }
        delete[] m;
        m = t;
        fclose(file);
    }
    else {
        cout << "Файл пуст, операция не возможна!\n";
        fclose(file);
    }
}

void write_hash() {
    if (n) {
        file = fopen("Hash.txt", "wb");
        fwrite(&n, sizeof(n), 1, file);
        for (int k = 0; k < n; k++) {
            fwrite(&m[k], sizeof(Human), 1, file);
        }
        fclose(file);
    }
    else {
        cout << "Хеш-таблица пуста, операция не возможна!\n";
    }
}

int main() {
    srand(time(NULL));
    setlocale(LC_ALL, "Rus");
    int a;
    while(true) {
        cout << "Выберите номер команды:\n1. Создать Хеш-таблицу\n2. Показать Хеш-таблицу\n3. Удалить из Хеш-таблицы человека с выбранной датой рождения\n4. Восстановить Хеш-таблицу из файла\n5. Найти номер человека в Хеш-таблице по дате рождения\n6. Записать Хеш-таблицу в файл\n7. Добавить человека в Хеш-таблицу\n";
        cin >> a;
        system("cls");
        switch (a) {
        case(1):
            create_hash();
            break;
        case(2):
            show_hash();
            break;
        case(3):
            del_person();
            break;
        case(4):
            read_hash();
            break;
        case(5):
            find_person();
            break;
        case(6):
            write_hash();
            break;
        default:
            add_person();
        }
    }
    return 0;
}