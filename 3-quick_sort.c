#include "sort.h"

/**
* lomuto - the Lomuto partition scheme for quicksort algorithm
*
* @a: an Array to sort
* @l: the lowest index of array
* @h: the highest index of array
*
* Return: the index of pivot
*/

int lomuto(int *a, int l, int h)
{
	int p, i, j, t;
	static int size, k;

	if (k == 0)
		size = h + 1, k++;
	p = a[h];
	i = l;
	for (j = l; j < h; j++)
	{
		if (a[j] <= p)
		{
			if (i != j)
			{
				t = a[i];
				a[i] = a[j];
				a[j] = t;
				print_array(a, size);
			}
			i++;
		}
	}
	if (i != h)
	{
		t = a[i];
		a[i] = a[h];
		a[h] = t;
		print_array(a, size);
	}

	return (i);
}

/**
* qs - recursive function
*
* @a: array to sort
* @l: lowest index
* @h: highest index
*/

void qs(int *a, int l, int h)
{
	int p;

	if (l < h)
	{
		p = lomuto(a, l, h);
		qs(a, l, p - 1);
		qs(a, p + 1, h);
	}
}


/**
* quick_sort - it sorts array using quicksort algorithm
* @array: an rray to sort
* @size: the size of array to sort
*/

void quick_sort(int *array, size_t size)
{
	if (size < 2)
		return;

	qs(array, 0, size - 1);
}
