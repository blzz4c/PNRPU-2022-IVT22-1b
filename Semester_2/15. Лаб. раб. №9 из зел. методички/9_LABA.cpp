#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void createFile() {
    ofstream fout("F1.txt");

    int n;
    string s;

    cout << "Введите количество строк: ";
    cin >> n;

    cin.get();
    for (int i = 0; i < n; i++) {
        getline(cin, s);
        fout << s << endl;
    }
    fout.close();
}

void copyFile() { //correct
    string s;
    int amountW;

    ifstream fin("F1.txt");
    ofstream fout("F2.txt");

    while (!fin.eof()) {
        getline(fin, s);
        if (s[0] != ' ') {
            amountW = 1;
        }
        else {
            amountW = 0;
        }
        for (int i = 0; i < s.length() && amountW < 3; i++) { 
            if (s[i] == ' ' && s[i + 1] != ' ') {
                amountW += 1;
            }
        }
        if (amountW > 2) {
            fout << s << endl;
        }
    }
    fin.close();
    fout.close();
}

void printFile(const char* filename) {
    ifstream fin(filename);
    string s;
    while (fin >> s) {
        cout << s << ' ';
        if (fin.get() == '\n') {
            cout << endl;
        }
    }
    fin.close();
}

void numW() {
    ifstream fin("F1.txt");
    string s;
    int numW = 0; //количество слов всего
    int wordK = 0; //номер слова на кириллице в котором больше всего гласных
    int wordL = 0; //номер слова на латинице в котором больше всего гласных
    int amountK = 0;
    int amountL = 0;
    int maxK = 0;
    int maxL = 0;

    while (getline(fin, s)) {
        
        if (s[0] != ' ') {
            numW += 1;
        }
        amountK = 0;
        amountL = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == 'а' || s[i] == 'я' || s[i] == 'у' || s[i] == 'ю' || s[i] == 'о' || s[i] == 'е' || s[i] == 'ё' || s[i] == 'э' || s[i] == 'и' || s[i] == 'ы' || s[i] == 'А' || s[i] == 'Я' || s[i] == 'У' || s[i] == 'Ю' || s[i] == 'О' || s[i] == 'Е' || s[i] == 'Ё' || s[i] == 'Э' || s[i] == 'И' || s[i] == 'Ы') {
                amountK += 1;
            }
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'y' || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U' || s[i] == 'Y') {
                amountL += 1;
            }
            if (amountK > maxK) {
                maxK = amountK;
                wordK = numW;
            }
            if (amountL > maxL) {
                maxL = amountL;
                wordL = numW;
            }
            if (s[i] == ' ' && s[i + 1] != ' ') {
                numW += 1;
                amountK = 0;
                amountL = 0;
            }
        }
    }
    cout << "номер слова на кириллице в котором больше всего гласных: " << wordK << "\n";
    cout << "номер слова на латинице в котором больше всего гласных: " << wordL << "\n\n";
    fin.close();
}

int main()
{
    system("chcp 1251>NULL");
    createFile();
    copyFile();
    numW();
    printFile("F1.txt");
    cout << endl;
    printFile("F2.txt");
}