#include <iostream>
#include <cmath>

void SS(int k, ...){
	int *ptr = &k; //настроили указатель на параметр k
	for (; k != 0; k--){
		int num = *(++ptr);
		int DEC = 0, i = 0;
		while(num){
			DEC += (num % 10)*pow(8, i);
			num /= 10;
			i++;
		}
		std::cout << DEC << " ";
	}
}

int main(){
	setlocale(LC_ALL, "Rus");
	std::cout << "\nИз 8-ой СС в 10-ую(3, 8, 6, 11) = ";
	SS(3, 8, 6, 11); //переводит в 10-ную систему счисления
	std::cout << "\nИз 8-ой СС в 10-ую(4, 21, 233, 3, 12) = ";
	SS(4, 21, 233, 3, 12);
}