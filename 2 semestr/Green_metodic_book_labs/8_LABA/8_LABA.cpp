#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;

int n;
FILE* file;
bool existsf = false;
char surname[255];
char numautoc[255];

struct Owner {
    char f[255];
    char i[255];
    char o[255];
    char numauto[255];
    char techpas[255];
    char gai[255];
};

Owner owner1;
Owner owner2;

void ShowFile() {
    if ((file = fopen("Owners.txt", "rb")) == NULL) {
        cout << "Ошибка чтения файлов\n";
    }
    else {
        int k = 0;
        while (!feof(file) && k < n) {
            Owner Owner;
            fread(&Owner, sizeof(Owner), 1, file);
            cout << "ФИО: " << Owner.f << ' ' << Owner.i << ' ' << Owner.o << ' ' << '\n';
            cout << "Номер авто: " << Owner.numauto << '\n';
            cout << "Номер техпаспорта: " << Owner.techpas << '\n';
            cout << "Отделение регистрации ГАИ: " << Owner.gai << '\n';
            cout << "_______________________________________________________________\n";
            k++;
        }
        fclose(file);
    }
}

void Add2Cur() {
    FILE* file1;
    FILE* file2;
    if (((file1 = fopen("Owners.txt", "rb")) == NULL) || ((file2 = fopen("tmp.txt", "wb")) == NULL)) {
        cout << "Ошибка чтения файлов\n";
    }
    else {
        int k = 0;
        int nums = n;
        while (!feof(file1) && k < nums) {
            Owner Owner;
            fread(&Owner, sizeof(Owner), 1, file1);
            if (!existsf) {
                if (!strcmp(surname, Owner.f)) {
                    existsf = true;
                    fwrite(&owner1, sizeof(Owner), 1, file2);
                    fwrite(&owner2, sizeof(Owner), 1, file2);
                    n += 2;
                }
                fwrite(&Owner, sizeof(Owner), 1, file2);
            }
            else {
                fwrite(&Owner, sizeof(Owner), 1, file2);
            }
            k++;
        }
        fclose(file1);
        fclose(file2);
        remove("Owners.txt");
        rename("tmp.txt", "Owners.txt");
    }
}

void AddOwner() {
    system("cls");
    Owner newowner;
    cout << "Как зовут владельца (ФИО)?\n";
    cin >> newowner.f;
    cin >> newowner.i;
    cin >> newowner.o;
    cout << "Номер автомобиля:\n";
    cin.get();
    cin.getline(newowner.numauto, 255);
    cout << "Номер техпаспорта:\n";
    cin.getline(newowner.techpas, 255);
    cout << "Отделение регистрации ГАИ:\n";
    cin.getline(newowner.gai, 255);
    cout << '\n';
    fwrite(&newowner, sizeof(Owner), 1, file);
}

void CreateOwner2() {
    system("cls");
    cout << "Как зовут владельца (фИО)?\n";
    cin >> owner2.f;
    cin >> owner2.i;
    cin >> owner2.o;
    cout << "Номер автомобиля:\n";
    cin.get();
    cin.getline(owner2.numauto, 255);
    cout << "Номер техпаспорта:\n";
    cin.getline(owner2.techpas, 255);
    cout << "Отделение регистрации ГАИ:\n";
    cin.getline(owner2.gai, 255);
    cout << '\n';
}

void CreateOwner1() {
    system("cls");
    cout << "Как зовут владельца (фИО)?\n";
    cin >> owner1.f;
    cin >> owner1.i;
    cin >> owner1.o;
    cout << "Номер автомобиля:\n";
    cin.get();
    cin.getline(owner1.numauto, 255);
    cout << "Номер техпаспорта:\n";
    cin.getline(owner1.techpas, 255);
    cout << "Отделение регистрации ГАИ:\n";
    cin.getline(owner1.gai, 255);
    cout << '\n';
}

void DelNumAuto() {
    FILE* file1;
    FILE* file2;
    if (((file1 = fopen("Owners.txt", "rb")) == NULL) || ((file2 = fopen("tmp.txt", "wb")) == NULL)) {
        cout << "Ошибка чтения файлов\n";
    }
    else {
        int nums = n;
        int k = 0;
        while (!feof(file1) && k < nums) {
            Owner owner;
            fread(&owner, sizeof(owner), 1, file1);
            if (!strcmp(numautoc, owner.numauto)) {
                n--;
            }
            else {
                fwrite(&owner, sizeof(owner), 1, file2);
            }
            k++;
        }
        fclose(file1);
        fclose(file2);
        remove("Owners.txt");
        rename("tmp.txt", "Owners.txt");
    }
}

int main() {
    system("chcp 1251>NULL");
    int a;
    while (true) {
        cout << "Введите номер команды:\n1. Создать новый список владелецев\n2. Добавить Владелеца\n3. Добавить двух владельцев перед указанной фамилией\n4. Удалить владелеца с заданным номером авто\n5. Показать список владелецев\n";
        cin >> a;
        switch (a) {
        case 1:
            system("cls");
            cout << "Введите количество владельцев: ";
            cin >> n;
            if ((file = fopen("Owners.txt", "wb")) == NULL) {
                cout << "Ошибка чтения файлов\n";
            }
            else {
                for (int i = 0; i < n; i++) {
                    AddOwner();
                }
                fclose(file);
            }
            break;
        case 2:
            if (n) {
                if ((file = fopen("Owners.txt", "ab")) == NULL) {
                    cout << "Ошибка чтения файлов\n";
                }
                else {
                    n += 1;
                    AddOwner();
                    fclose(file);
                }
            }
            else {
                system("cls");
                cout << "Не возможно добавить владельца в пустой список\n";
            }
            break;
        case 3:
            system("cls");
            if (n) {
                existsf = false;
                cout << "Введите фамилию: ";
                cin >> surname;
                CreateOwner1();
                CreateOwner2();
                Add2Cur();
                if (!existsf) {
                    cout << "Владелец с данной фамилией не найден\n";
                }
            }
            else {
                cout << "Невозможно добавить владельцев в пустой список\n";
            }
            break;
        case 4:
            system("cls");
            if (n > 0) {
                cout << "Введите номер авто:\n";
                cin >> numautoc;
                DelNumAuto();
            }
            else {
                cout << "Выполнение данной команды невозможно, добавьте владельцев!\n";
            }
            break;
        default:
            system("cls");
            if (n > 0) {
                ShowFile();
            }
            else {
                cout << "Список владельцев пуст!\n";
            }
        }
    }
    return 0;
}