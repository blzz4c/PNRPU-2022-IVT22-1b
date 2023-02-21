#include <iostream>
#include <string>
using namespace std;

int main()
{
	system("chcp 1251 > NULL");
	string d = "0123456789";
	string s1, s3;
	s3 = "";
	cout << "Введите строку: ";
	getline(cin, s1);
	s1 = ' ' + s1;
	int i;
	i = 0;
	while (i < s1.length()) {
		if (s1[i] == ' ') {
			int j = i + 1;
			int t = 0;
			while (s1[j] != ' ' && j < s1.length()) {
				t += d.find(s1[j]) != std::string::npos ? 1 : 0;
				j++;
			}
			if (t > 0) {
				s3 += s1.substr(i + 1, j - i - 1) + ' ';
			}
			i = j;
		}
		else {
			i++;
		}
	}
	cout << s3.erase(s3.length()-1, 1) << endl;
}