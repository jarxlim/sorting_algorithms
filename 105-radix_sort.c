#include "sort.h"

#include "sort.h"

/**
 * max_value - function that gets the maximum value in an array
 * @array: array of integers
 * @size: size of array
 * Return: the maximum value in the array
 */
int max_value(int *array, int size)
{
	int maximum = array[0], idx;

	for (idx = 1; idx < size; idx++)
	{
		if (array[idx] > maximum)
			maximum = array[idx];
	}
	return (maximum);
}

/**
 * _count - Sort the signnificant digits in array of integers
 * @array: array of integers.
 * @size: size of the array.
 * @sign: significant digit to sort on.
 * @buffer: buffer to store the sorted array.
 */
void _count(int *array, size_t size, int sign, int *buffer)
{
	int count[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	size_t index;

	for (index = 0; index < size; index++)
		count[(array[index] / sign) % 10] += 1;

	for (index = 0; index < 10; index++)
		count[index] += count[index - 1];

	for (index = size - 1; (int)index >= 0; index--)
	{
		buffer[count[(array[index] / sign) % 10] - 1] = array[index];
		count[(array[index] / sign) % 10] -= 1;
	}

	for (index = 0; index < size; index++)
		array[index] = buffer[index];
}

/**
 * radix_sort - Sort an array of integers in ascending
 * @array: array of integers.
 * @size: size of the array.
 */
void radix_sort(int *array, size_t size)
{
	int maximum, sign, *buffer;

	if (array == NULL || size < 2)
		return;

	buffer = malloc(sizeof(int) * size);
	if (buffer == NULL)
		return;

	maximum = max_value(array, size);
	for (sign = 1; maximum / sign > 0; sign *= 10)
	{
		_count(array, size, sign, buffer);
		print_array(array, size);
	}

	free(buffer);
}
