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
 * _partition - order a subset of an array of integers
 * @array: array of integers.
 * @size: size of the array.
 * @start: starting index of the subset
 * @end: ending index of the subset
 * Return: final partition index.
 */
int _partition(int *array, size_t size, int start, int end)
{
	int point, top, bottom;

	point = array[end];
	for (top = start - 1, bottom = end + 1; above < below;)
	{
		do {
			top++;
		} while (array[top] < point);
		do {
			bottom--;
		} while (array[bottom] > point);

		if (top < bottom)
		{
			swap(array + top, array + bottom);
			print_array(array, size);
		}
	}

	return (top);
}

/**
 * sort_hoare - uses the quicksort algorithm through recursion.
 * @array: array of integers
 * @size: size of the array
 * @start: starting index of the array
 * @end: end of index of the array
 */
void sort_hoare(int *array, size_t size, int start, int end)
{
	int p;

	if (end - start > 0)
	{
		p = _partition(array, size, start, end);
		sort_hoare(array, size, start, p - 1);
		sort_hoare(array, size, p, end);
	}
}

/**
 * quick_sort_hoare - Sort an array of integers in ascending order
 * @array: array of integers
 * @size: size of the array
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	sort_hoare(array, size, 0, size - 1);
}
