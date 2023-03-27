#include <iostream>
#include <string>
using namespace std;

string sub, s;

int KMP() {
	int* t = new int[sub.length()] {};
	int k = 0;
	for (int i = 1; i < sub.length(); i++) {
		while (k > 0 && sub[i] != sub[k]) {
			k = t[k - 1];
		}
		if (sub[i] == sub[k]) {
			k++;
		}
		t[i] = k;
	}
	k = 0;
	for (int i = sub.length(); i < s.length(); i++) {
		while (k > 0 && sub[k] != s[i]) {
			k = t[k - 1];
		}
		k++;
		if (k == sub.length()) {
			return i - sub.length() + 1;
		}
	}
	return -1;
}

int BM() {
    unsigned int shift[256];
    for (int i = 0; i < 256; i++) {
        shift[i] = sub.length();
    }
    for (int i = sub.length() - 2; i >= 0; i--) {
        if (shift[sub[i] + 128] == sub.length()) {
            shift[sub[i] + 128] = sub.length() - 1 - i;
        }
    }
    int ei = sub.length() - 1;
    while (ei < s.length()) {
        bool find = true;
        for (int i = sub.length() - 1; i >= 0 && find; i--) {
            if (s[ei - sub.length() + 1 + i] != sub[i]) {
                ei += shift[s[ei - sub.length() + 1 + i] +128];
                find = false;
            }
        }
        if (find) {
            return ei - sub.length() + 1;
        }
    }
    return -1;
}

int main() {
	system("chcp 1251 > Null");
	cout << "Введите строку, в которой требуется найти образ: ";
	cin >> s;
	cout << "Введите образ: ";
	cin >> sub;
	cout << KMP();
	return 0;
}