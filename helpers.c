/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmdaba <rogerndaba@gmil.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 19:09:03 by rmdaba            #+#    #+#             */
/*   Updated: 2019/09/10 19:09:04 by rmdaba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void copy_arr(int **dest, int *src, int size)
{
	int		i;

	i = -1;
	*dest = (int *)malloc(sizeof(int) * size);
	while (++i < size)
		(*dest)[i] = src[i];
}

int		check_sorted(t_checker t_c)
{
	int		i;

	if (t_c.size_b > 0)
		return (0);
	i = -1;
	while (++i < t_c.size_a)
		if (t_c.srtd[i] != t_c.s_a[i])
			return (0);
	return (1);
}
