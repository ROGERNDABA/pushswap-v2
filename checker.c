#include <libft.h>
#include <stdio.h>

void	free_double_arr(void ***arr)
{
	char	**tmp_arr;
	int		i;

	tmp_arr = (char **)*arr;
	i = -1;
	while (tmp_arr[++i])
		ft_strdel(&tmp_arr[i]);
	free(tmp_arr);
}

void	normalize_argv(int ac, char ***av) {
	char	**tmp_av;
	char	**split;
	char	*new_av;
	int		i;

	tmp_av = *av;
	new_av = (char *)malloc(65535);
	i = 0;
	while (++i < ac) {
		new_av = ft_strcat(new_av, " ");
		new_av = ft_strcat(new_av, tmp_av[i]);
	}
	*av = ft_strsplit(new_av, ' ');
	free(new_av);
}

void build_stacks(int **stack_a, int **stack_b, char ***av, int ac) {
	int		i;
	char	**tmp_av;
	int		val;

	i = -1;
	tmp_av = *av;
	*stack_a = (int *)malloc(sizeof(int) * ac);
	*stack_b = (int *)malloc(sizeof(int) * ac);
	while (tmp_av[++i])
	{
		val = ft_atoi(tmp_av[i]);
		if (val == 0 && ft_strcmp(tmp_av[i], "0"))
		{
			free_double_arr((void ***)&(*av));
			free(*stack_a);
			free(*stack_b);
			printf("nan\n");
			exit(EXIT_FAILURE);
		}
		else
			*(*stack_a + i) = val;
	}
}


int main(int ac, char **av)
{
	normalize_argv(ac, &av);
	ac--;
	int *a;
	int *b;

	build_stacks(&a, &b, &av, ac);
	printf("ac = %d\n", ac);
	for (size_t i = 0; i < ac; i++)
	{
		printf("---> %d|\n", a[i]);
	}
	free_double_arr((void ***)&av);
	free(a);
	free(b);

	// int *stack_a = (int *)malloc(sizeof(int) * 10);
	/* code */
	return 0;
}
