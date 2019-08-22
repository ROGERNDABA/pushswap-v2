#include <push_swap.h>

void copy_arr(int **dest, int *src, int size)
{
	int		i;

	i = -1;
	*dest = (int *)malloc(sizeof(int) * size);
	while (++i < size)
		(*dest)[i] = src[i];
}

int		check_sorted(t_checker t_c)
{
	int		*new_arr;
	int		i;

	if (t_c.size_b > 0)
		return (0);
	i = -1;
	new_arr = (int *)malloc(sizeof(int) * t_c.size_a);
	while (++i < t_c.size_a)
		new_arr[i] = t_c.s_a[i];
	insertion_sort(&new_arr, t_c.size_a);
	while (--i > -1)
		if (new_arr[i] != t_c.s_a[i])
		{
			free(new_arr);
			return (0);
		}
	return (1);
}
