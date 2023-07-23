#include "sort.h"

#define UP 0
#define DOWN 1

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
 * _merge - merge bitonic sequence inside array of integer
 * @array: array of integers
 * @size: size of the array
 * @first: The first index of the lenuence in array to sort.
 * @len: size of the lenuence to sort.
 * @d: direction to sort in.
 */
void _merge(int *array, size_t size, size_t first, size_t len,
		char d)
{
	size_t idx, half_len = len / 2;

	if (len > 1)
	{
		for (idx = first; idx < first + half_len; idx++)
		{
			if ((d == UP && array[idx] > array[idx + half_len]) ||
			    (d == DOWN && array[idx] < array[idx + half_len]))
				swap(array + idx, array + idx + half_len);
		}
		_merge(array, size, first, half_len, d);
		_merge(array, size, first + half_len, half_len, d);
	}
}

/**
 * _sequence - change array of integers into a bitonic sequence
 * @array: array of integers
 * @size: size of the array
 * @first: first index of a block of the sequence
 * @len: size of the block
 * @d: The direction to sort the bitonic lenuence block in.
 */
void _sequence(int *array, size_t size, size_t first, size_t len, char d)
{
	size_t dv = len / 2;
	char *str = (d == UP) ? "UP" : "DOWN";

	if (len > 1)
	{
		printf("Merging [%lu/%lu] (%s):\n", len, size, str);
		print_array(array + first, len);

		_sequence(array, size, first, dv, UP);
		_sequence(array, size, first + dv, dv, DOWN);
		_merge(array, size, first, len, d);

		printf("Result [%lu/%lu] (%s):\n", len, size, str);
		print_array(array + first, len);
	}
}

/**
 * bitonic_sort - Sort an array of integers
 * @array: array of integers.
 * @size: size of the array.
 */
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	_sequence(array, size, 0, size, UP);
}
