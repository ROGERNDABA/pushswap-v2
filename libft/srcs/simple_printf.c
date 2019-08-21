/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_printf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmdaba <rogerndaba@gmil.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 14:07:12 by rmdaba            #+#    #+#             */
/*   Updated: 2019/08/21 18:23:11 by rmdaba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/libft.h"

char	*convert(unsigned int num, int base)
{
	static char		rep[17];
	static char		buffer[50];
	char			*ptr;

	ft_strcpy(rep, "0123456789ABCDEF");
	ptr = &buffer[49];
	*ptr = '\0';
	while (num != 0)
	{
		*--ptr = rep[num % base];
		num /= base;
	}
	return (ptr);
}

void	proc(int *i, va_list arg, char c, char **s)
{
	if (c == 'c')
	{
		*i = va_arg(arg, int);
		ft_putchar(*i);
	}
	else if (c == 'd')
	{
		*i = va_arg(arg, int);
		if (*i < 0)
		{
			*i = -*i;
			ft_putchar('-');
		}
		ft_putstr(convert(*i, 10));
	}
	else if (c == 's')
	{
		*s = va_arg(arg, char *);
		ft_putstr(*s);
	}
}

void	simple_printf(char *format, ...)
{
	int				i;
	char			*traverse;
	char			*s;
	va_list			arg;

	va_start(arg, format);
	traverse = format;
	while (*traverse != '\0')
	{
		if (*traverse == '%')
		{
			traverse++;
			proc(&i, arg, *traverse, &s);
		}
		else
			ft_putchar(*traverse);
		traverse++;
	}
	va_end(arg);
}
