#include <libft.h>
#include <stdio.h>

typedef struct	s_checker
{
	int			*s_a;
	int			*s_b;
	int			size;
}				t_checker;



void print_stacks(int *stack_a, int *stack_b)
{
	int		i;
	int		size;

	i = -1;

	ft_putstr("\033[34mstack a \033[31m|");
	ft_putstr(" \033[32mstack b\n\033[31m-----------------\033[0m\n");
	// while ()
	// {
	// 	/* code */
	// }

}


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

void	normalize_argv(int *ac, char ***av)
{
	char	**tmp_av;
	char	**split;
	char	*new_av;
	int		i;

	tmp_av = *av;
	new_av = (char *)malloc(65535);
	i = 0;
	while (++i < *ac) {
		new_av = ft_strcat(new_av, " ");
		if (!ft_strncmp(tmp_av[i], "-", 1) && !ft_isdigit(tmp_av[i][1])) {
			continue;
		} else {
			new_av = ft_strcat(new_av, tmp_av[i]);
		}
	}
	*av = ft_strsplit(new_av, ' ');
	tmp_av = *av;
	i = 0;
	while (tmp_av[i])
		i++;
	*ac = i;
	free(new_av);
}

void build_stacks(t_checker *t_c, char ***av, int ac) {
	int		i;
	char	**tmp_av;
	int		val;

	i = -1;
	tmp_av = *av;
	t_c->s_a = (int *)malloc(sizeof(int) * ac);
	t_c->s_b = (int *)malloc(sizeof(int) * ac);
	while (tmp_av[++i])
	{
		val = ft_atoi(tmp_av[i]);
		if (val == 0 && ft_strcmp(tmp_av[i], "0"))
		{
			free_double_arr((void ***)&(*av));
			free(t_c->s_a);
			free(t_c->s_b);
			ft_putstr("\033[31mArguments must be integers\033[0m\n");
			exit(EXIT_FAILURE);
		}
		else
		{
			t_c->s_a[i] = val;
		}
	}
	t_c->size = ac;
}


int main(int ac, char **av)
{
	normalize_argv(&ac, &av);

	t_checker t_c;

	build_stacks(&t_c, &av, ac);
	printf("ac = %d\n", ac);
	// print_stacks(stack_a, stack_b);
	for (size_t i = 0; i < ac; i++)
	{
		printf("---> %d|\n", t_c.s_b[i]);
	}
	free_double_arr((void ***)&av);


	// free(stack_a);
	// free(stack_b);
	return 0;
}
