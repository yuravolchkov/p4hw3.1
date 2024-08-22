#include <iostream>
#include "merge.h"

void merge_sort(int* arr, int size)
{

	std::cout << "\n\nИсходный массив: ";
	for (int i = 0; i < size; i++)
	{
		std::cout << arr[i];
		if (i + 1 < size)
		{
			std::cout << " ";
		}
	}

	// spliting 

	int first_half = size / 2, second_half = size - first_half;
	int* first_part = new int[first_half] {0};
	int* second_part = new int[second_half] {0};

	for (int i = 0; i < second_half; i++)
	{
		if (i < first_half)
		{
			first_part[i] = arr[i];
		}
		second_part[i] = arr[i + first_half];
	}

	// sorting
	int swap;
	for (int j = 0; j < second_half; j++)
	{
		for (int i = 0; i < second_half - 1; i++)
		{
			if (i< first_half - 1 && first_part[i] > first_part[i + 1])
			{
				swap = first_part[i];
				first_part[i] = first_part[i + 1];
				first_part[i + 1] = swap;
			}
			if (second_part[i] > second_part[i + 1])
			{
				swap = second_part[i];
				second_part[i] = second_part[i + 1];
				second_part[i + 1] = swap;
			}
		}
	}

	//merge
	int first_part_counter = 0, second_part_counter = 0;

	for (int i = 0; i < size; i++)
	{
		//std::cout << "\n" << i << " " << first_part_counter << " " << second_part_counter ;
		if (first_part_counter < first_half && second_part_counter < second_half)
		{
			if (first_part[first_part_counter] <= second_part[second_part_counter])
			{
				arr[i] = first_part[first_part_counter];
				first_part_counter = first_part_counter + 1;
			}
			else if (first_part[first_part_counter] > second_part[second_part_counter])
			{
				arr[i] = second_part[second_part_counter];
				second_part_counter = second_part_counter + 1;
			}
		}
		else if (second_part_counter == second_half)
		{
			arr[i] = first_part[first_part_counter];
			first_part_counter = first_part_counter + 1;
		}

		else if (first_part_counter == first_half)
		{
			arr[i] = second_part[second_part_counter];
			second_part_counter = second_part_counter + 1;
		}
	}

	std::cout << "\nОтсортированный массив: ";
	for (int i = 0; i < size; i++)
	{
		std::cout << arr[i];
		if (i + 1 < size)
		{
			std::cout << " ";
		}
	}
	delete[] first_part;
	delete[] second_part;

}