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


void	get_factor(t_checker *t_c)
{
	if (t_c->size_a <= 200)
		t_c->ftc = 5;
	else if (t_c->size_a <= 500)
		t_c->ftc = 10;
	else
		t_c->ftc = 15;
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
		get_factor(&t_c);
		// algo_3(&t_c);
		for (int i = 0; i < t_c.size_a; i++)
		{
			printf("%d ", t_c.srtd[i]);
		}

		// simple_print(&t_c);
		free_double_arr((void ***)&av);
		free(t_c.s_a);
		free(t_c.s_b);
	}
	return 0;
}
