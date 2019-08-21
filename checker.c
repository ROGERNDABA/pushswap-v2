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
			simple_printf(B_RED"Error\n"RESET);
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
	while (ft_isblank(tmp[++i]))
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

void init_moves(t_moves **tmp)
{
	*tmp = (t_moves *)malloc(sizeof(t_moves) * 11);
	(*tmp + 0)->move_ptr = &sa;
	(*tmp + 0)->name = "sa";
	(*tmp + 1)->move_ptr = &sb;
	(*tmp + 1)->name = "sb";
	(*tmp + 2)->move_ptr = &ss;
	(*tmp + 2)->name = "ss";
	(*tmp + 3)->move_ptr = &pa;
	(*tmp + 3)->name = "pa";
	(*tmp + 4)->move_ptr = &pb;
	(*tmp + 4)->name = "pb";
	(*tmp + 5)->move_ptr = &ra;
	(*tmp + 5)->name = "ra";
	(*tmp + 6)->move_ptr = &rb;
	(*tmp + 6)->name = "rb";
	(*tmp + 7)->move_ptr = &rr;
	(*tmp + 7)->name = "rr";
	(*tmp + 8)->move_ptr = &rra;
	(*tmp + 8)->name = "rra";
	(*tmp + 9)->move_ptr = &rrb;
	(*tmp + 9)->name = "rrb";
	(*tmp + 10)->move_ptr = &rrr;
	(*tmp + 10)->name = "rrr";
}


int		make_move(char *str, t_moves *tmp, t_checker **t_c)
{
	int		i;

	i = -1;
	while (++i < 11)
	{
		if (!ft_strcmp(str, (tmp + i)->name))
		{
			(tmp + i)->move_ptr(&(**t_c), 0);
			return (1);
		}
	}
	return (0);
}

void proccess_input(char *line, t_checker *t_c)
{
	t_moves		*m;

	init_moves(&m);
	if (!make_move(line, m, &t_c))
	{
		free(t_c->s_a);
		free(t_c->s_b);
		free(m);
		simple_printf(B_RED"Error\n"RESET);
		exit(EXIT_FAILURE);
	}
	free(m);
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
	free_double_arr((void ***)&av);
	simple_print(&t_c);
	while (get_next_line(0, &line))
	{
		trim(&line);
		proccess_input(line, &t_c);
		free(line);
		simple_print(&t_c);
		// break;
	}
	printf("lol\n");
	free(t_c.s_a);
	free(t_c.s_b);
	// while(1) {}
	return 0;
}
