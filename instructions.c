/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Roger Ndaba <rogerndaba@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 11:02:13 by Roger Ndaba       #+#    #+#             */
/*   Updated: 2019/08/21 12:21:11 by Roger Ndaba      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <checker.h>

void	sa(t_checker *t_c)
{
	int		tmp;

	if (t_c->size_a > 1)
	{
		tmp = t_c->s_a[0];
		t_c->s_a[0] = t_c->s_a[1];
		t_c->s_a[1] = tmp;
	}
}

void	sb(t_checker *t_c)
{
	int		tmp;

	if (t_c->size_b > 1)
	{
		tmp = t_c->s_b[0];
		t_c->s_b[0] = t_c->s_b[1];
		t_c->s_b[1] = tmp;
	}
}

void	ss(t_checker *t_c)
{
	sa(&(*t_c));
	sb(&(*t_c));
}

void	pa(t_checker *t_c)
{
	int		i;

	if (t_c->size_b > 0)
	{
		i = t_c->size_a + 2;
		while (--i > 0)
			t_c->s_a[i] = t_c->s_a[i - 1];
		t_c->s_a[0] = t_c->s_b[0];
		t_c->size_a++;
		t_c->size_b--;
		i = -1;
		while (++i < t_c->size_b)
			t_c->s_b[i] = t_c->s_b[i + 1];
	}
}

void	pb(t_checker *t_c)
{
	int		i;

	if (t_c->size_a > 0)
	{
		i = t_c->size_b + 2;
		while (--i > 0)
			t_c->s_b[i] = t_c->s_b[i - 1];
		t_c->s_b[0] = t_c->s_a[0];
		t_c->size_b++;
		t_c->size_a--;
		i = -1;
		while (++i < t_c->size_a)
			t_c->s_a[i] = t_c->s_a[i + 1];
	}
}

void	ra(t_checker *t_c)
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
}

void	rb(t_checker *t_c)
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
}

void	rr(t_checker *t_c)
{
	ra(&(*t_c));
	rb(&(*t_c));
}

void	rra(t_checker *t_c)
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
}

void	rrb(t_checker *t_c)
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
}

void	rrr(t_checker *t_c)
{
	rra(&(*t_c));
	rrb(&(*t_c));
}