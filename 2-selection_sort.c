#include "sort.h"
/**
 * swap_int- function that swaps two integers
 * @a: integer a
 * @b: integer b
 */
void swap_int(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
/**
 * selection_sort - a fucntion that sorts an array of integers in ascending
 * order using selection sort algorithm
 * @array: array of integers
 * @size: number of elements in array
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, min;

	if (!array || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		min = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min])
				min = j;
		}
		swap_int(&array[min], &array[i]);
		print_array(array, size);
	}
}
