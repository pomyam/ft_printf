/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyamcha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 14:08:18 by pyamcha           #+#    #+#             */
/*   Updated: 2021/01/31 17:05:53 by pyamcha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_utils_str(t_outlst lst, char *line, int size)
{
	int	length;

	length = 0;
	if (lst.dot >= 0)
	{
		if (lst.width < lst.dot)
			length += ft_put_utils_width(lst.width - 1, size, 0);
		length += ft_put_length(line, lst.dot);
	}
	else
		length += ft_put_length(line, size);
	return (length);
}

int	ft_print_string(char *str, t_outlst lst)
{
	int		length;
	int		size;
	char	*line;

	length = 0;
	if (!str)
		str = "(null)";
	line = ft_strdup(str);
	size = ft_strlen(line);
	if (lst.dot >= 0 && lst.dot > size)
		lst.dot = size;
	if (lst.minus == 1)
		length += ft_print_utils_str(lst, line, size);
	if (lst.dot >= 0)
		length += ft_put_utils_width(lst.width, lst.dot, 0);
	else
		length += ft_put_utils_width(lst.width, size, lst.zero);
	if (lst.minus == 0)
		length += ft_print_utils_str(lst, line, size);
	free(line);
	return (length);
}

int	ft_print_char(int n, t_outlst lst)
{
	int	length;

	length = 0;
	if (lst.minus == 1)
		ft_putchar(n);
	length += ft_put_utils_width(lst.width, 1, 0);
	if (lst.minus == 0)
		ft_putchar(n);
	return (length + 1);
}

int	ft_print_proc(t_outlst lst)
{
	int	length;

	length = 0;
	if (lst.minus == 1)
	{
		length += ft_putchar('%');
		lst.zero = 0;
	}
	length += ft_put_utils_width(lst.width, 1, lst.zero);
	if (lst.minus == 0)
		length += ft_putchar('%');
	return (length);
}
