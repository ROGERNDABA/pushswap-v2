#include <stdio.h>
#include <checker.h>

void simple_print(t_checker *t_c){
	printf("\033[31mstack a : ");
	for (size_t i = 0; i < t_c->size_a; i++)
		printf(" %d", t_c->s_a[i]);
	printf("\033[32m\nstack b : ");
	for (size_t i = 0; i < t_c->size_b; i++)
		printf(" %d", t_c->s_b[i]);
	printf("\033[0m\n\n");
}

void print_stacks(t_checker *t_c)
{
	int		i;
	int		j;

	i = 0;
	ft_putstr("\033[34mstack a \033[31m|");
	ft_putstr(" \033[32mstack b\n\033[31m-----------------\033[0m\n");
	while ( i < t_c->size_a || i < t_c->size_b)
	{
		j = -1;
		ft_putstr("\033[34m ");
		while (++j < (6 - ft_numlen(t_c->s_a[i])))
			ft_putchar(' ');
		if (i < t_c->size_a)
			ft_putnbr(t_c->s_a[i]);
		ft_putstr("\033[31m | \033[32m");
		if (i < t_c->size_b)
			ft_putnbr(t_c->s_b[i]);
		ft_putstr("\n\033[0m");
		i++;
	}
	ft_putchar('\n');
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
			t_c->s_a[i] = val;
	}
}

void trim(char **str)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	tmp = *str;
	while (ft_isblank(tmp[i]))
		i++;
	if (ft_isblank(tmp[0]))
	{
		j = -1;
		i--;
		while (ft_isprint(tmp[++i]))
			tmp[++j] = tmp[i];
		tmp[j + 1] = '\0';
		while (ft_isblank(tmp[j]))
			j--;
		tmp[++j] = '\0';
		*str = tmp;
	}
}

int		proccess_input(char *line, t_checker *t_c)
{
	if (!ft_strcmp("sa", line))
		sa(&(*t_c), 0);
	else if (!ft_strcmp("sb", line))
		sb(&(*t_c), 0);
	else if (!ft_strcmp("ss", line))
		ss(&(*t_c), 0);
	else if (!ft_strcmp("pa", line))
		pa(&(*t_c), 0);
	else if (!ft_strcmp("pb", line))
		pb(&(*t_c), 0);
	else if (!ft_strcmp("ra", line))
		ra(&(*t_c), 0);
	else if (!ft_strcmp("rb", line))
		rb(&(*t_c), 0);
	else if (!ft_strcmp("rr", line))
		rr(&(*t_c), 0);
	else if (!ft_strcmp("rra", line))
		rra(&(*t_c), 0);
	else if (!ft_strcmp("rrb", line))
		rrb(&(*t_c), 0);
	else if (!ft_strcmp("rrr", line))
		rrr(&(*t_c), 0);
	else
		return (0);
	return (1);
}


int main(int ac, char **av)
{
	t_checker	t_c;
	char		*line;
	int			line_nbr;

	normalize_argv(&ac, &av);
	t_c.size_a = ac;
	t_c.size_b = 0;
	line_nbr = 0;
	build_stacks(&t_c, &av, ac);
	simple_print(&t_c);
	while (get_next_line(1, &line))
	{
		trim(&line);
		if (!proccess_input(line, &t_c))
		{
			simple_printf("Line %d: Invalid instruction\n", ++line_nbr);
			break;
		}
		simple_print(&t_c);
		free(line);
	}

	free_double_arr((void ***)&av);
	free(t_c.s_a);
	free(t_c.s_b);
	return 0;
}