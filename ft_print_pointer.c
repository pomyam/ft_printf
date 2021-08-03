/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyamcha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 14:35:18 by pyamcha           #+#    #+#             */
/*   Updated: 2021/01/31 14:39:07 by pyamcha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_utils_pointer(char *str, t_outlst lst)
{
	int	length;

	length = 0;
	if (lst.minus == 1)
	{
		length += ft_put_length("0x", 2);
		length += ft_put_length(str, ft_strlen(str));
		length += ft_put_utils_width(lst.width - 2, ft_strlen(str), 0);
		return (length);
	}
	if (lst.minus == 0)
	{
		length += ft_put_utils_width(lst.width, ft_strlen(str) + 2, 0);
		length += ft_put_length("0x", 2);
		length += ft_put_utils_width(lst.dot, ft_strlen(str), 1);
		length += ft_put_length(str, ft_strlen(str));
	}
	else
	{
		length += ft_put_length("0x", 2);
		length += ft_put_length(str, ft_strlen(str));
		length += ft_put_utils_width(lst.width, ft_strlen(str) + 2, 0);
	}
	return (length);
}

int	ft_print_ifnull_pointer(t_outlst lst)
{
	int	length;

	length = 0;
	if (lst.dot >= 0)
	{
		if (lst.minus == 0)
		{
			length += ft_put_utils_width(lst.width, 2, 0);
			lst.width = -1;
		}
		length += 1 + ft_put_length("0x", 2);
		length += ft_put_utils_width(lst.dot, 0, 1);
		length += write(1, NULL, 1);
	}
	else
	{
		length += (lst.minus == 0) ? ft_put_utils_width(lst.width, 3, 0) : 0;
		length += ft_put_length("0x0", 3);
		length += (lst.minus == 1) ? ft_put_utils_width(lst.width, 3, 0) : 0;
		lst.width = -1;
	}
	if (lst.width >= 0)
		length += ft_put_utils_width(lst.width, 2, 0);
	return (length);
}

int	ft_print_pointer(void *num, t_outlst lst)
{
	int					length;
	char				*str;
	unsigned long int	n;

	length = 0;
	str = NULL;
	if (num == NULL)
	{
		length += ft_print_ifnull_pointer(lst);
		return (length);
	}
	n = (unsigned long int)num;
	str = (n == 0) ? "0" : ft_itoa_hex(n, 16);
	length += ft_print_utils_pointer(str, lst);
	free(str);
	return (length);
}
