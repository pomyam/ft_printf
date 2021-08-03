/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyamcha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 14:06:36 by pyamcha           #+#    #+#             */
/*   Updated: 2021/01/31 15:37:27 by pyamcha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_put_length(char *str, int count)
{
	int length;
	int index;
	int size;

	length = 0;
	index = 0;
	size = 0;
	while (size < count)
	{
		length += ft_putchar(str[index]);
		index++;
		size++;
	}
	return (length);
}

t_outlst	ft_parse_width(va_list ap, t_outlst lst)
{
	lst.star = 1;
	lst.width = va_arg(ap, int);
	if (lst.width < 0)
	{
		lst.minus = 1;
		lst.width *= -1;
	}
	return (lst);
}

t_outlst	ft_parse_minus(t_outlst lst)
{
	lst.minus = 1;
	lst.zero = 0;
	return (lst);
}

int			ft_parse_dot(va_list ap, t_outlst *lst, int index, const char *s)
{
	if (s[++index] == '*')
	{
		lst->dot = va_arg(ap, int);
		index++;
	}
	else
	{
		lst->dot = 0;
		while (s[index] >= '0' && s[index] <= '9')
			lst->dot = (lst->dot * 10) + (s[index++] - '0');
	}
	return (index);
}

t_outlst	ft_parse_digit(t_outlst lst, char s)
{
	if (lst.star == 1)
		lst.width = 0;
	lst.width = (lst.width * 10) + (s - '0');
	return (lst);
}
