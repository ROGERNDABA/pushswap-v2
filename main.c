#include <global.h>
#include <push_swap.h>

void simple_print(t_checker *t_c){
	printf("\033[31mstack a : ");
	for (size_t i = 0; i < t_c->size_a; i++)
		printf(" %d", t_c->s_a[i]);
	printf("\033[32m\nstack b : ");
	for (size_t i = 0; i < t_c->size_b; i++)
		printf(" %d", t_c->s_b[i]);
	printf("\033[0m\n\n");
}

int	dist(int *arr, int size, int value)
{
	int		i;

	i = -1;
	while (++i < size)
		if (arr[i] == value)
			break;
	if (i == size)
		return (1);
	return ((i >= (size/2)) ? 1 : 0);
}

void	find_alt(int *arr, int size, int *vals)
{
	int		i;

	i = -1;
	while (++i < size)
	{
		if (arr[i] == vals[0])
			if (i > 0)
				vals[0] = arr[i - 1];
	}
	i = size;
	while (--i > -1)
	{
		if (arr[i] == vals[1])
			if (i < size - 1)
				vals[1] = arr[i + 1];
	}
}

void	ps_proccess1(t_checker *t_c, int *new_arr, int size)
{
	int		*alt;

	alt = (int *)malloc(sizeof(int) * 2);
	alt[0] = t_c->s_a[0];
	alt[1] = t_c->s_a[t_c->size_a - 1];
	find_alt(new_arr, size, &(*alt));
}

void algo_3(t_checker *t_c)
{
	int		*new_arr;
	int		size;
	int		best;

	copy_arr(&new_arr, t_c->s_a, t_c->size_a);
	size = t_c->size_a;
	insertion_sort(&new_arr, t_c->size_a);
	if (!check_sorted(*t_c))
	{
		if (dist(t_c->s_a, t_c->size_a, new_arr[t_c->size_a / 2]))
			while (*(t_c->s_a) != t_c->size_a / 2)
				rra(&(*t_c), 1);
		else
			while (*(t_c->s_a) != t_c->size_a / 2)
				ra(&(*t_c), 1);
		ra(&(*t_c), 1);
		while (t_c->size_a > 1)
			pb(&(*t_c), 1);
		ps_proccess1(&(*t_c), new_arr, size);
	}
}

int main(int ac, char **av)
{
	t_checker	t_c;

	if (ac > 1)
	{
		normalize_argv(&ac, &av);
		t_c.size_a = ac;
		t_c.size_b = 0;
		build_stacks(&t_c, &av, ac);
		algo_3(&t_c);
		simple_print(&t_c);
		free_double_arr((void ***)&av);
		free(t_c.s_a);
		free(t_c.s_b);
	}
	return 0;
}
