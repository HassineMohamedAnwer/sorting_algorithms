#include "sort.h"

/**
 * selection_sort - check the code
 * @array: array
 * @size: size of array
 * Return: none
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, jMin;
	int x;

	for (i = 0; i < size - 1; i++)
	{
		/* find the min element in the unsorted a[i .. aLength-1] */

		/* assume the min is the first element */
		jMin = i;
		/* test against elements after i to find the smallest */
		for (j = i + 1; j < size; j++)
		{
		/* if this element is less, then it is the new minimum */
			if (array[j] < array[jMin])
		/* found new minimum; remember its index */
				jMin = j;
		}

		if (jMin != i)
		{
			x = array[jMin];
			array[jMin] = array[i];
			array[i] = x;
			print_array(array, size);
		}
	}
}

