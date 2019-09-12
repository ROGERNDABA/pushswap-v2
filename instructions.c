/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmdaba <rogerndaba@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 11:02:13 by rmdaba            #+#    #+#             */
/*   Updated: 2019/09/12 21:05:25 by rmdaba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <checker.h>

void	sa(t_checker *t_c, int flag)
{
	int		tmp;

	if (t_c->size_a > 1)
	{
		tmp = t_c->s_a[0];
		t_c->s_a[0] = t_c->s_a[1];
		t_c->s_a[1] = tmp;
	}
	if (flag)
		ft_putstr("sa\n");
}

void	sb(t_checker *t_c, int flag)
{
	int		tmp;

	if (t_c->size_b > 1)
	{
		tmp = t_c->s_b[0];
		t_c->s_b[0] = t_c->s_b[1];
		t_c->s_b[1] = tmp;
	}
	if (flag)
		ft_putstr("sb\n");
}

void	ss(t_checker *t_c, int flag)
{
	sa(&(*t_c), 0);
	sb(&(*t_c), 0);
	if (flag)
		ft_putstr("ss\n");
}

void	pa(t_checker *t_c, int flag)
{
	int		i;

	if (t_c->size_b > 0)
	{
		i = t_c->size_a + 1;
		while (--i > 0)
			t_c->s_a[i] = t_c->s_a[i - 1];
		t_c->s_a[0] = t_c->s_b[0];
		t_c->size_a++;
		t_c->size_b--;
		i = -1;
		while (++i < t_c->size_b)
			t_c->s_b[i] = t_c->s_b[i + 1];
	}
	if (flag)
		ft_putstr("pa\n");
}

void	pb(t_checker *t_c, int flag)
{
	int		i;

	if (t_c->size_a > 0)
	{
		i = t_c->size_b + 1;
		while (--i > 0)
			t_c->s_b[i] = t_c->s_b[i - 1];
		t_c->s_b[0] = t_c->s_a[0];
		t_c->size_b++;
		t_c->size_a--;
		i = -1;
		while (++i < t_c->size_a)
			t_c->s_a[i] = t_c->s_a[i + 1];
	}
	if (flag)
		ft_putstr("pb\n");
}

void	ra(t_checker *t_c, int flag)
{
	int		tmp;
	int		i;

	i = -1;
	if (t_c->size_a > 1)
	{
		tmp = t_c->s_a[0];
		while (++i < t_c->size_a - 1)
			t_c->s_a[i] = t_c->s_a[i + 1];
		t_c->s_a[i] = tmp;
	}
	if (flag)
		ft_putstr("ra\n");
}

void	rb(t_checker *t_c, int flag)
{
	int		tmp;
	int		i;

	i = -1;
	if (t_c->size_b > 1)
	{
		tmp = t_c->s_b[0];
		while (++i < t_c->size_b - 1)
			t_c->s_b[i] = t_c->s_b[i + 1];
		t_c->s_b[i] = tmp;
	}
	if (flag)
		ft_putstr("rb\n");
}

void	rr(t_checker *t_c, int flag)
{
	ra(&(*t_c), 0);
	rb(&(*t_c), 0);
	if (flag)
		ft_putstr("rr\n");
}

void	rra(t_checker *t_c, int flag)
{
	int		tmp;
	int		i;

	i = t_c->size_a;
	if (t_c->size_a > 1)
	{
		tmp = t_c->s_a[i - 1];
		while (--i > 0)
			t_c->s_a[i] = t_c->s_a[i - 1];
		t_c->s_a[0] = tmp;
	}
	if (flag)
		ft_putstr("rra\n");
}

void	rrb(t_checker *t_c, int flag)
{
	int		tmp;
	int		i;

	i = t_c->size_b;
	if (t_c->size_b > 1)
	{
		tmp = t_c->s_b[i - 1];
		while (--i > 0)
			t_c->s_b[i] = t_c->s_b[i - 1];
		t_c->s_b[0] = tmp;
	}
	if (flag)
		ft_putstr("rrb\n");
}

void	rrr(t_checker *t_c, int flag)
{
	rra(&(*t_c), 0);
	rrb(&(*t_c), 0);
	if (flag)
		ft_putstr("rrr\n");
}
