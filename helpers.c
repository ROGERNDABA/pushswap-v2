#include <push_swap.h>

void copy_arr(int **dest, int *src, int size)
{
	int		i;

	i = -1;
	*dest = (int *)malloc(sizeof(int) * size);
	while (++i < size)
		(*dest)[i] = src[i];
}