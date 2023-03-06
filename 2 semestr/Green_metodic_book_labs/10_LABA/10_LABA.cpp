#include <iostream>
#include <string>
using namespace std;

int main() { // генерация и вывод
	setlocale(LC_ALL, "RUS");
	int size;
	cout << "Введите размер массива: " << endl;
	cin >> size;
	string* arr = new string[size];
	for (int i = 0; i < size; i++) {
		arr[i] = (char)('1' + i);
	}
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;

	int n, k;
	cout << "Введите индекс строки с которой хотите начать удаление: ";
	cin >> n;
	cout << "Введите количество удаляемых строк: ";
	cin >> k;
	string* tmp = new string[size];
	for (int i = 0; i < size; i++) {
		if (i < n || i >= n + k) {
			tmp[i] = arr[i];
		}
	}
	for (int i = n; i < size - k; i++) {
		if (n + k < size) {
			tmp[i] = arr[n + k];
			n++;
		}
	}
	arr = tmp;
	for (int i = 0; i < size - k; i++) {
		cout << arr[i] << " ";
	}
	delete[] arr;
	return 0;
}