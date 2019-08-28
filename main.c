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

int lowest(int *arr, int size)
{
	int		i;
	int		n;

	i = -1;
	n = arr[0];
	while (++i < size)
		if (arr[i] < n)
			n = arr[i];
	return (n);
}


int highest(int *arr, int size)
{
	int		i;
	int		n;

	i = -1;
	n = arr[0];
	while (++i < size)
		if (arr[i] > n)
			n = arr[i];
	return (n);
}

void	find_alt(int *arr, t_checker *t_c, int size, int *vals)
{
	int		i;
	int		low;
	int		high;

	i = -1;
	low = lowest(t_c->s_b, t_c->size_b);
	high = highest(t_c->s_b, t_c->size_b);
	while (++i < size)
	{
		if (arr[i] == vals[0])
			vals[0] = (i > 0) ? arr[i - 1] : low;
	}
	i = size;
	while (--i > -1)
	{
		if (arr[i] == vals[1])
			vals[1] = (i < size - 1) ? arr[i + 1] : high;
	}
}

int		closest(int *arr, int size, int *vals)
{
	int		n1;
	int		n2;
	int		i;

	// printf("%d  ++++  %d\n", vals[0], vals[1]);
	i = -1;
	while (++i < size)
		if (arr[i] == vals[0])
		{
			if (i >= size / 2)
				n1 = size - i;
			else
				n1 = i;
		}
		else if (arr[i] == vals[1])
		{
			if (i >= size / 2)
				n2 = size - i;
			else
				n2 = i;
		}
	return ((n1 < n2) ? vals[0] : vals[1]);
}

void	ps_proccess1(t_checker *t_c, int *new_arr, int size)
{
	int		*alt;
	int		close;

	alt = (int *)malloc(sizeof(int) * 2);
	while (t_c->size_b > 1)
	{
		alt[0] = t_c->s_a[0];
		alt[1] = t_c->s_a[t_c->size_a - 1];
		find_alt(new_arr, &(*t_c), size, &(*alt));
		if (dist(t_c->s_b, t_c->size_b, close))
		{
			while (t_c->s_b[0] != close)
			{
				rrb(&(*t_c), 1);
				// find_alt(new_arr, &(*t_c), size, &(*alt));
				close = closest(t_c->s_b, t_c->size_b, alt);
				// for (size_t i = 0; i < size; i++)
				// {
				// 	printf(" %d", new_arr[i]);
				// }

				printf("\n--------------> %d\n", close);
				// exit(1);
				// simple_print(t_c);

			}
			pa(&(*t_c), 1);
			if (t_c->s_a[0] > t_c->s_a[1])
				ra(&(*t_c), 1);
		}
		else
		{
			while (t_c->s_b[0] != close)

				rb(&(*t_c), 1);
			pa(&(*t_c), 1);
			if (t_c->s_a[0] > t_c->s_a[1])
				ra(&(*t_c), 1);
			// printf("--------------> %d\n", close);
			// simple_print(t_c);
		}
	}
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
		{
			if (t_c->s_a[0] > new_arr[size / 2])
				pb(&(*t_c), 1);
			else
			{
				pb(&(*t_c), 1);
				rb(&(*t_c), 1);
			}
		}
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
		// simple_print(&t_c);
		free_double_arr((void ***)&av);
		free(t_c.s_a);
		free(t_c.s_b);
	}
	return 0;
}
