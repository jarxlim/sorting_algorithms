#include "sort.h"
#include <stdio.h>

/**
 * lomuto_partition - partitions the array by selecting last element as pivot
 * @array: the unsorted array
 * @low: the lowest index of the lomuto_partition to sort
 * @high: the highest index of the lomuto_partition to sort
 * @size: size of the unsorted array
 * Return: index position of the partioned element
 */

int lomuto_partition(int *array, int low, int high, size_t size)
{
	int temp, pivot;
	int i, j;

	pivot = array[high];
	i = low - 1;

	for (j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			if (i != j)
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
				print_array(array, size);
			}
		}
	}
	if (array[high] < array[i + 1])
	{
		temp = array[i + 1];
		array[i + 1] = array[high];
		array[high] = temp;
		print_array(array, size);
	}
	return (i + 1);
}

/**
 * quicksort - sorts each lomuto_partition of the array of integers
 * @array: array/partion of array to be sorted
 * @low: lowest index of the partion to sort
 * @high: highest index of the lomuto_partition to sort
 * @size: size of the array
 * Return: void
 */

void quicksort(int *array, int low, int high, size_t size)
{
	int pivot;

	if (low < high)
	{
		pivot = lomuto_partition(array, low, high, size);

		quicksort(array, low, pivot - 1, size);
		quicksort(array, pivot + 1, high, size);
	}
}

/**
 * quick_sort - sorts an array of integers in ascending order using the Quick
 * @array: unsorted array to be sorted
 * @size: size of the array
 * Return: void
 */

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	quicksort(array, 0, size - 1, size);
}
