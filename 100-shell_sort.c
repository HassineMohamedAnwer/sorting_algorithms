#include "sort.h"

/**
 * knuth_sequence - knuth sequence
 * @size: array's size
 * Return: maximum gap
 */

size_t knuth_sequence(size_t size)
{
	size_t g = 1;

	while (g < size)
		g = (3 * g) + 1;
	if (g >= size)
		g = (g - 1) / 3;

	return (g);
}

/**
 * shell_sort - sorts using the Shell sort algorithm, using the Knuth sequence
 * @array: array
 * @size: size
 * Return: void
 */

void shell_sort(int *array, size_t size)
{
	size_t g = 0, i, j;
	int t;

	g = knuth_sequence(size);
	while (g > 0)
	{
		for (i = g; i < size; i++)
		{
			t = array[i];

			for (j = i; j >= g && array[j - g] > t; j = j - g)
				array[j] = array[j - g];

			array[j] = t;
		}
		print_array(array, size);
		g = (g - 1) / 3;
	}
}
