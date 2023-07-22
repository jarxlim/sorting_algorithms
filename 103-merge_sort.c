#include "sort.h"

/**
 * sort_sub - sort a subarray of integers.
 * @subarr: A subarray  to sort.
 * @buffer: A buffer to store the subarray.
 * @front: The front index.
 * @middle: The mid index.
 * @back: The back index.
 */
void sort_sub(int *subarr, int *buffer, size_t front, size_t middle,
		size_t back)
{
	size_t i, j, k = 0;

	printf("Merging...\n[left]: ");
	print_array(subarr + front, middle - front);

	printf("[right]: ");
	print_array(subarr + middle, back - middle);

	for (i = front, j = middle; i < middle && j < back; k++)
		buffer[k] = (subarr[i] < subarr[j]) ? subarr[i++] : subarr[j++];
	for (; i < middle; i++)
		buffer[k++] = subarr[i];
	for (; j < back; j++)
		buffer[k++] = subarr[j];
	for (i = front, k = 0; i < back; i++)
		subarr[i] = buffer[k++];

	printf("[Done]: ");
	print_array(subarr + front, back - front);
}

/**
 * sort_recursion - Implement the merge sort algorithm through recursion.
 * @subarr: A subarray of an array of integers to sort.
 * @buffer: A buffer to store the sorted result.
 * @front: The front index of the subarray.
 * @back: The back index of the subarray.
 */
void sort_recursion(int *subarr, int *buffer, size_t front, size_t back)
{
	size_t middle;

	if (back - front > 1)
	{
		middle = front + (back - front) / 2;
		sort_recursion(subarr, buffer, front, middle);
		sort_recursion(subarr, buffer, middle, back);
		sort_sub(subarr, buffer, front, middle, back);
	}
}

/**
 * merge_sort - Sort an array of integers
 * @array: Array of integers.
 * @size: size of the array.
 */
void merge_sort(int *array, size_t size)
{
	int *buffer;

	if (array == NULL || size < 2)
		return;

	buffer = malloc(sizeof(int) * size);
	if (buffer == NULL)
		return;

	sort_recursion(array, buffer, 0, size);

	free(buffer);
}
