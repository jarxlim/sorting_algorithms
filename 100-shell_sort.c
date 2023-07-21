#include "sort.h"
/**
 * swap - Swap two integers in an array.
 * @x: first integer to swap.
 * @y: second integer to swap.
 */
void swap(int *x, int *y)
{
	int temp = *x;

	*x = *y;
	*y = temp;
}

/**
 * shell_sort - Sort an array of integers in ascending shell sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 */
void shell_sort(int *array, size_t size)
{
	size_t spread, i, j;

	if (array == NULL || size < 2)
		return;

	for (spread = 1; spread < (size / 3);)
		spread = spread * 3 + 1;

	for (; spread >= 1; spread /= 3)
	{
		for (i = spread; i < size; i++)
		{
			j = i;
			while (j >= spread && array[j - spread] > array[j])
			{
				swap(array + j, array + (j - spread));
				j -= spread;
			}
		}
		print_array(array, size);
	}
}
