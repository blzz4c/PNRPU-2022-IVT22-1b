//метод открытой адресации
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <cstring>
#include <ctime>
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

struct Node {
    Human human;
    Node* next;
};

struct LinkedList {
    Node* last, *current, *head;
};

LinkedList* m = new LinkedList;

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
    LinkedList* t = new LinkedList[n]{};
    int collision = 0;
    for (int k = 0; k < n; k++) {
        change_value(date, d[rand_num()]);
        int l = get_key();
        bool occupied = t[l].head != NULL;
        t[l].current = t[l].head;
        if (occupied) {
            while (t[l].current->next != NULL) {
                t[l].current = t[l].current->next;
            }
        }
        Node* q = new Node;
        change_value(q->human.fio, f[rand_num()] + ' ' + i[rand_num()] + ' ' + o[rand_num()]);
        change_value(q->human.dateofbirth, date);//работает :)
        change_value(q->human.number, p[rand_num()]);
        if (occupied) {
            collision++;
            t[l].current->next = q;
            t[l].current->next->next = NULL;
        }
        else {
            t[l].head = q;
            t[l].head->next = NULL;
        }
    }
    delete[] m;
    m = t;
    cout << "Хеш-таблица создана! " << "Коллизий: " << collision << '\n';
}

void del_person() {//DeleteFromHash
    if (n) {
        cout << "Введите дату: ";
        cin.getline(date, 255);
        cin >> date;
        for (int k = 0; k < n; k++) {
            m[k].current = m[k].head;
            while (m[k].current != NULL) {
                if (!strcmp(m[k].current->human.dateofbirth, date)) {
                    change_value(m[k].current->human.fio, "NULL");
                    change_value(m[k].current->human.dateofbirth, "NULL");
                    change_value(m[k].current->human.number, "NULL");
                }
                m[k].current = m[k].current->next;
            }
        }
    }
    else {
        cout << "Хеш-таблица пуста!\n";
    }
}

void find_person() {//FindIntoHash
    if (n) {
        cin.get();
        cout << "Введите дату: ";
        cin.getline(date, 255);
        int l = get_key();
        int k = 0;
        for (int k = 0; k < n; k++) {
            m[l].current = m[l].head;
            while (m[l].current != NULL) {
                if (!strcmp(m[l].current->human.dateofbirth, date)) {
                    cout << l + 1 << '\n';
                    return;
                }
                m[l].current = m[l].current->next;
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
    Node* q = new Node;
    change_value(q->human.fio, f[rand_num()] + ' ' + i[rand_num()] + ' ' + o[rand_num()]);//
    change_value(q->human.dateofbirth, d[rand_num()]);
    change_value(q->human.number, p[rand_num()]);
    if (l > n) {
        LinkedList* t = new LinkedList[l]{};
        for (int k = 0; k < n; k++) {
            t[k] = m[k];
        }
        delete[] m;
        m = t;
        n = l;
        q->next = NULL;
        m[l - 1].head = q;
    }
    else if (m[l - 1].head != NULL && strcmp(m[l - 1].head->human.fio, "NULL")) {
        m[l - 1].current = m[l - 1].head;
        while (m[l - 1].current->next != NULL && strcmp(m[l - 1].current->next->human.fio, "NULL")) {
            m[l - 1].current = m[l - 1].current->next;
        }
        if (m[l - 1].current->next == NULL) {
            q->next = NULL;
        }
        else {
            q->next = m[l - 1].current->next->next;
        }
        m[l - 1].current->next = q;
    }
    else {
        if (m[l - 1].head == NULL) {
            q->next = NULL;
            m[l - 1].head = q;
        }
        else {
            q->next = m[l - 1].head->next;
            m[l - 1].head = q;
        }
    }
}

void show_hash() {
    if (n) {
        for (int k = 0; k < n; k++) {
            if (m[k].head != NULL) {
                cout << "Ключ " << k << ":\n";
                m[k].current = m[k].head;
                while (m[k].current != NULL) {
                    cout << m[k].current->human.fio << ' ' << m[k].current->human.dateofbirth << ' ' << m[k].current->human.number << '\n';
                    m[k].current = m[k].current->next;
                }
            }
        }
        cout << "-------------------------------\n";
    }
    else {
        cout << "Хеш-таблица пуста!\n";
    }
}

void write_hash() {
    if (n) {
        file = fopen("Hash.txt", "wb");
        fwrite(&n, sizeof(n), 1, file);
        char space = ' ';
        char newline = 'h';
        fwrite(&newline, sizeof(newline), 1, file);
        for (int k = 0; k < n; k++) {
            m[k].current = m[k].head;
            while (m[k].current != NULL) {
                fwrite(&space, sizeof(space), 1, file);
                fwrite(&m[k].current->human, sizeof(Human), 1, file);
                m[k].current = m[k].current->next;
            }
            fwrite(&newline, sizeof(newline), 1, file);
        }
        fclose(file);
    }
    else {
        cout << "Хеш-таблица пуста, операция не возможна!\n";
    }
}

void read_hash() {
    if ((file = fopen("Hash.txt", "rb")) == NULL) {
        cout << "Ошибка чтения файла\n";
    }
    else if (!feof(file)) {
        fread(&n, sizeof(n), 1, file);
        LinkedList* t = new LinkedList[n]{};
        char c;
        fread(&c, sizeof(c), 1, file);
        for (int k = 0; k < n; k++) {
            fread(&c, sizeof(c), 1, file);
            if (c == ' ') {
                Node* q = new Node;
                fread(&q->human, sizeof(Human), 1, file);
                t[k].current = t[k].head = q;
                t[k].current->next = NULL;
                fread(&c, sizeof(c), 1, file);
                while (c != 'h') {
                    Node* q = new Node;
                    fread(&q->human, sizeof(Human), 1, file);
                    t[k].current->next = q;
                    t[k].current = t[k].current->next;
                    t[k].current->next = NULL;
                    fread(&c, sizeof(c), 1, file);
                }
            }
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

int main() {
    srand(time(NULL));
    setlocale(LC_ALL, "Rus");
    int a;
    while(true) {
        cout << "Выберите номер команды:\n" <<
        "1. Создать Хеш-таблицу\n" <<
        "2. Показать Хеш-таблицу\n" <<
        "3. Удалить из Хеш-таблицы человека с выбранной датой рождения\n" <<
        "4. Восстановить Хеш-таблицу из файла\n" <<
        "5. Найти номер человека в Хеш-таблице по дате рождения\n" <<
        "6. Записать Хеш-таблицу в файл\n" <<
        "7. Добавить человека в Хеш-таблицу\n";
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