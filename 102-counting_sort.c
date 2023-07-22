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
 * counting_sort - sorts an array of integers using counting sort algortihhm
 * @array: array of integers
 * @size: size of the array
 */

void counting_sort(int *array, size_t size)
{
	int *counter, *sorter, max, i;

	if (array == NULL || size < 2)
		return;

	sorter = malloc(sizeof(int) * size);
	if (sorter == NULL)
		return;
	max = max_value(array, size);
	counter = malloc(sizeof(int) * (max + 1));
	if (counter == NULL)
	{
		free(sorter);
		return;
	}

	for (i = 0; i < (max + 1); i++)
		counter[i] = 0;
	for (i = 0; i < (int)size; i++)
		counter[array[i]] += 1;
	for (i = 0; i < (max + 1); i++)
		counter[i] += counter[i - 1];
	print_array(counter, max + 1);

	for (i = 0; i < (int)size; i++)
	{
		sorter[counter[array[i]] - 1] = array[i];
		counter[array[i]] -= 1;
	}

	for (i = 0; i < (int)size; i++)
		array[i] = sorter[i];

	free(sorter);
	free(counter);
}
