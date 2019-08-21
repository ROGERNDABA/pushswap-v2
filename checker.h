/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Roger Ndaba <rogerndaba@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 11:04:08 by Roger Ndaba       #+#    #+#             */
/*   Updated: 2019/08/21 12:21:19 by Roger Ndaba      ###   ########.fr       */
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

void			sa(t_checker *t_c);
void			sb(t_checker *t_c);
void			ss(t_checker *t_c);
void			pa(t_checker *t_c);
void			pb(t_checker *t_c);
void			ra(t_checker *t_c);
void			rb(t_checker *t_c);
void			rr(t_checker *t_c);
void			rra(t_checker *t_c);
void			rrb(t_checker *t_c);
void			rrr(t_checker *t_c);

#endif //CHECKER_H
