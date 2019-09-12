/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmdaba <rogerndaba@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 19:08:27 by rmdaba            #+#    #+#             */
/*   Updated: 2019/09/12 21:40:44 by rmdaba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <global.h>
#include <push_swap.h>

void simple_print(t_checker *t_c)
{
	printf("\033[31mstack a : ");
	for (size_t i = 0; i < t_c->size_a; i++)
		printf(" %d", t_c->s_a[i]);
	printf("\033[32m\nstack b : ");
	for (size_t i = 0; i < t_c->size_b; i++)
		printf(" %d", t_c->s_b[i]);
	printf("\033[0m\n\n");
}

int lowest(int *arr, int size)
{
	int i;
	int n;

	i = -1;
	n = arr[0];
	while (++i < size)
		if (arr[i] < n)
			n = arr[i];
	return (n);
}

int highest(int *arr, int size)
{
	int i;
	int n;

	i = -1;
	n = arr[0];
	while (++i < size)
		if (arr[i] > n)
			n = arr[i];
	return (n);
}

void get_factor(t_checker *t_c)
{
	if (t_c->size_a <= 100)
		t_c->ftc = 3;
	else if (t_c->size_a <= 200)
		t_c->ftc = 4;
	else if (t_c->size_a <= 500)
		t_c->ftc = 10;
	else
		t_c->ftc = 15;
}

int in_chunk(t_checker *t_c, int val)
{
	int i;

	i = -1;
	while (++i < t_c->size / t_c->ftc)
		if (t_c->srtd[i] == val)
			return (1);
	return (0);
}


int		dist(int *arr, int size, int val)
{
	int		i;

	i = -1;
	while (++i < size)
		if (arr[i] == val)
			break;
	return ((i < size / 2) ? i : size - i);
}

int		side(int *arr, int size, int val)
{
	int		i;

	i = -1;
	while (++i < size)
		if (arr[i] == val)
			break;
	return ((i < size / 2) ? 0 : 1);
}

void do_low(t_checker *t_c, int low)
{
	while (*(t_c->s_b) != low)
		rb(&(*t_c), 1);
	pa(&(*t_c), 1);
	ra(&(*t_c), 1);
}

void do_low_r(t_checker *t_c, int low)
{
	while (*(t_c->s_b) != low)
		rrb(&(*t_c), 1);
	pa(&(*t_c), 1);
	ra(&(*t_c), 1);
}

void do_high(t_checker *t_c, int high)
{
	while (*(t_c->s_b) != high)
		rb(&(*t_c), 1);
	pa(&(*t_c), 1);
	if (t_c->s_a[0] > t_c->s_a[1])
		sa(&(*t_c), 1);
}

void do_high_r(t_checker *t_c, int high)
{
	while (*(t_c->s_b) != high)
		rrb(&(*t_c), 1);
	pa(&(*t_c), 1);
	if (t_c->s_a[0] > t_c->s_a[1])
		sa(&(*t_c), 1);
}

int is_next(int *arr, int size, int i1, int i2)
{
	int		i;

	i = -1;
	while (++i < size)
	{
		if (arr[i] == i1)
			break;
	}
	return ((arr[i + 1] == i2) ? 1 : 0);
}

void do_next(t_checker *t_c)
{
	int		i1;
	int		i2;

	i1 = t_c->s_a[t_c->size_a - 1];
	i2 = t_c->s_a[0];
	while (is_next(t_c->srtd, t_c->size, i1, i2))
	{
		ra(&(*t_c), 1);
		i1 = t_c->s_a[t_c->size_a - 1];
		i2 = t_c->s_a[0];
	}
	// simple_print(t_c);
}

void step_1_1(t_checker *t_c)
{
	int		l;
	int		ld;
	int		h;
	int		hd;

	l = lowest(t_c->s_b, t_c->size_b);
	ld = dist(t_c->s_b, t_c->size_b, l);
	h = highest(t_c->s_b, t_c->size_b);
	hd = dist(t_c->s_b, t_c->size_b, h);
	if (ld <= hd)
	{
		if (!side(t_c->s_b, t_c->size_b, l))
			do_low(&(*t_c), l);
		else
			do_low_r(&(*t_c), l);
	}
	else
		if (!side(t_c->s_b, t_c->size_b, l))
			do_high(&(*t_c), h);
		else
			do_high_r(&(*t_c), h);
// simple_print(t_c);
	if (t_c->size_b > 0)
		step_1_1(&(*t_c));
	else
		do_next(&(*t_c));
}

void step_1(t_checker *t_c)
{
	static int track;

	if (!check_sorted(*t_c))
	{
		while (t_c->size_b < t_c->size / t_c->ftc)
		{
			if (in_chunk(&(*t_c), *t_c->s_a))
				pb(&(*t_c), 1);
			else
				ra(&(*t_c), 1);
			// simple_print(&(*t_c));
		}
		step_1_1(&(*t_c));
		// simple_print(&(*t_c));
	}
	else
	{
		printf("sorted!\n");
	}
}

int main(int ac, char **av)
{
	t_checker t_c;

	if (ac > 1)
	{
		normalize_argv(&ac, &av);
		t_c.size_a = ac;
		t_c.size_b = 0;
		build_stacks(&t_c, &av, ac);
		get_factor(&t_c);

		step_1(&t_c);
		free_double_arr((void ***)&av);
		free(t_c.s_a);
		free(t_c.s_b);
	}
	return 0;
}
