/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmdaba <rogerndaba@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 16:57:21 by rmdaba            #+#    #+#             */
/*   Updated: 2019/08/21 15:02:43 by rmdaba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <string.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include "libft.h"
# define BUFF_SIZE 2046

int		get_next_line(int const fd, char **line);
#endif
