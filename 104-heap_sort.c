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
 * tree_to_heap - change a binary tree into a complete binary heap.
 * @array: An array of integers
 * @size: size of the array
 * @b: The index of the base
 * @r: The root node
 */
void tree_to_heap(int *array, size_t size, size_t b, size_t r)
{
	size_t i, j, k;

	i = 2 * r + 1;
	j = 2 * r + 2;
	k = r;

	if (i < b && array[i] > array[k])
		k = i;
	if (j < b && array[j] > array[k])
		k = j;

	if (k != r)
	{
		swap(array + r, array + k);
		print_array(array, size);
		tree_to_heap(array, size, b, k);
	}
}

/**
 * heap_sort - Sort an array of integers in ascending
 * @array: An array of integers.
 * @size: The size of the array.
 */
void heap_sort(int *array, size_t size)
{
	int i;

	if (array == NULL || size < 2)
		return;

	for (i = (size / 2) - 1; i >= 0; i--)
		tree_to_heap(array, size, size, i);

	for (i = size - 1; i > 0; i--)
	{
		swap(array, array + i);
		print_array(array, size);
		tree_to_heap(array, size, i, 0);
	}
}
