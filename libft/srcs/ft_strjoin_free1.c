/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmdaba <rogerndaba@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 13:44:29 by rmdaba            #+#    #+#             */
/*   Updated: 2019/08/21 15:02:44 by rmdaba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/libft.h"

char	*ft_strjoin_free1(char *s1, const char *s2)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	if ((tmp = ft_strnew(ft_strlen(s1) + ft_strlen(s2))) == NULL)
		return (NULL);
	while (s1[j] != '\0')
	{
		tmp[i] = s1[j];
		i += 1;
		j += 1;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		tmp[i] = s2[j];
		i += 1;
		j += 1;
	}
	free(s1);
	return (tmp);
}
