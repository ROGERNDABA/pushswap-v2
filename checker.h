/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmdaba <rogerndaba@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 11:04:08 by rmdaba            #+#    #+#             */
/*   Updated: 2019/09/12 20:22:04 by rmdaba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <libft.h>
# include <stdio.h>

typedef struct	s_checker
{
	int			*s_a;
	int			*s_b;
	int			size_a;
	int			size_b;
	int			ftc;
	int			size;
	int			*srtd;
}				t_checker;

typedef void	(*t_move_ptr)(t_checker *, int);

typedef	struct	s_moves
{
	char		*name;
	t_move_ptr	move_ptr;
}				t_moves;

void			sa(t_checker *t_c, int flag);
void			sb(t_checker *t_c, int flag);
void			ss(t_checker *t_c, int flag);
void			pa(t_checker *t_c, int flag);
void			pb(t_checker *t_c, int flag);
void			ra(t_checker *t_c, int flag);
void			rb(t_checker *t_c, int flag);
void			rr(t_checker *t_c, int flag);
void			rra(t_checker *t_c, int flag);
void			rrb(t_checker *t_c, int flag);
void			rrr(t_checker *t_c, int flag);

#endif
