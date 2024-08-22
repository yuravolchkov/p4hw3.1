#include <iostream>
#include "merge.h"




int main()
{
	setlocale(LC_ALL, "Russian"); // задать русский текст
	std::system("chcp 1251"); // настроить кодировку консоли
	std::system("cls"); // очистить экран

	int array_size1 = 10, array_size2=15, array_size3=18;
	int* array1 = new int [array_size1] {3, 43, 38, 29, 18, 72, 57, 61, 2, 33};
	int* array2 = new int[array_size2] {88, 91, 87, 59, 53, 49, 29, 16, 4, 27, 28, 89, 2, 25, 74};
	int* array3 = new int[array_size3] {24, 66, 20, 79, 30, 16, 19, 62, 94, 59, 0, 7, 59, 90, 84, 60, 95, 62};

	merge_sort(array1, array_size1);
	delete[] array1;

	merge_sort(array2, array_size2);
	delete[] array2;
	
	merge_sort(array3, array_size3);
	delete[] array3;
	
	std::cout << std::endl;
	return 31;
}