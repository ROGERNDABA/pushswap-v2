/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Roger Ndaba <rogerndaba@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 11:04:08 by Roger Ndaba       #+#    #+#             */
/*   Updated: 2019/08/21 13:31:49 by Roger Ndaba      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

#include <libft.h>
#include <stdio.h>

typedef struct	s_checker
{
	int			*s_a;
	int			*s_b;
	int			size_a;
	int			size_b;
}				t_checker;

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

#endif //CHECKER_H
