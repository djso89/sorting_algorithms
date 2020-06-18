#include "sort.h"
/**
 * lomuto - partition scheme
 * @array: array of integers
 * @size: size of an array
 * @low: lowest index of array
 * @high: highest of index of array
 * Return: index of pivot number
 */
int lomuto(int *array, size_t size, int low, int high)
{
	int i, j, temp;
	int pivot = array[high];

	i = low - 1;
	for (j = low; j <= high - 1; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			if ( i != j)
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
				print_array(array, size);
			}
		}
	}
	if (i + 1 != high)
	{
		temp = array[i + 1];
		array[i + 1] = array[high];
		array[high] = temp;
		print_array(array, size);
	}
	return (i + 1);
}
/**
 * quick_sort_h - helper function for quick_sort
 * @array: array of integers
 * @size: size of array
 * @low: lowest index
 * @high: highest index
 */
void quick_sort_h(int *array, size_t size, int low, int high)
{
	int pivot = 0;

	if (low < high)
	{
		pivot = lomuto(array, size, low, high);
		quick_sort_h(array, size, low, pivot - 1);
		quick_sort_h(array, size, pivot + 1, high);
	}
}
/**
 * quick_sort - function that sorts an array using quick sort
 * @array: array of integers
 * @size: size of array
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	quick_sort_h(array, size, 0, size - 1);
}
