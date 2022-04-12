#include "sort.h"
/**
 * _swap - function to swap elements
 * @array: array
 * @a: 1st elmnt
 * @b: 2nd elmnt
 * Return: void
 */

void _swap(int **array, ssize_t a, ssize_t b)
{
	int t = (*array)[a];

	(*array)[a] = (*array)[b];
	(*array)[b] = t;
}

/**
 * partition - function to find the partition position
 * @array: array
 * @low: lowest index
 * @high: highest index
 * @size: array's size
 * Return: return the partition point
 */
size_t partition(int *array, ssize_t low, ssize_t high, size_t size)
{
	int pivot = array[high];
	ssize_t i = low, j;

	for (j = low; j < high; j++)
	{
		if (array[j] <= pivot)
		{
			if (i != j)
			{
				_swap(&array, i, j);
				print_array(array, size);
			}
			i++;
		}
	}
	if (array[high] < array[i])
	{
		_swap(&array, i, high);
		print_array(array, size);
	}

	return (i);
}

/**
 * _quick_sort - partitions the array, then sorts each partition
 *
 * @array: the array to sort
 * @low: the lowest index of the partition to sort
 * @high: the highest index of the partition to sort
 * @size: size of the array
 */

void _quick_sort(int *array, ssize_t low, ssize_t high, size_t size)
{
	ssize_t pivot;

	if (low < high)
	{
		pivot = partition(array, low, high, size);
		_quick_sort(array, low, pivot - 1, size);
		_quick_sort(array, pivot + 1, high, size);
	}
}



/**
 * quick_sort - find the pivot element such that
 * elements smaller than pivot are on left of pivot
 * elements greater than pivot are on right of pivot
 * @array: the array of integers
 * @size: the size of the array
 */

void quick_sort(int *array, size_t size)
{
	ssize_t low = 0;
	ssize_t high = (size - 1);

	if (!array || size < 2)
		return;

	_quick_sort(array, low, high, size);
}
