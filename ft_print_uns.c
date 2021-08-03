/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_uns.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyamcha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 14:39:39 by pyamcha           #+#    #+#             */
/*   Updated: 2021/01/31 17:20:13 by pyamcha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check_ifnull_un(t_outlst lst, char *str)
{
	int	length;

	length = 0;
	if (lst.minus == 1)
	{
		length += ft_put_length(str, ft_strlen(str));
		length += ft_put_utils_width(lst.width, ft_strlen(str), 0);
	}
	else
	{
		length += ft_put_utils_width(lst.width, ft_strlen(str), 0);
		length += ft_put_length(str, ft_strlen(str));
	}
	return (length);
}

int	ft_print_utils_un(t_outlst lst, char *str)
{
	int	length;

	length = 0;
	if (lst.dot >= 0)
	{
		length += ft_put_utils_width(lst.dot - ft_strlen(str), 0, 1);
		length += ft_put_length(str, ft_strlen(str));
	}
	else
	{
		length += ft_put_length(str, ft_strlen(str));
		length += ft_put_utils_width(lst.width - ft_strlen(str), 0, 0);
	}
	return (length);
}

int	ft_check_un(t_outlst lst, char *str)
{
	int length;

	length = 0;
	if (lst.dot >= 0)
	{
		length += (lst.dot < lst.width) ? ft_put_utils_width(0, 0, 0) : 0;
		if (lst.dot > ft_strlen(str))
			length += ft_put_utils_width(lst.dot, ft_strlen(str), 1);
		length += ft_put_length(str, ft_strlen(str));
	}
	else
	{
		if (lst.zero)
		{
			length += ft_put_utils_width(lst.width - ft_strlen(str), 0, 1);
			length += ft_put_length(str, ft_strlen(str));
		}
		else
		{
			length += ft_put_utils_width(lst.width - ft_strlen(str), 0, 0);
			length += ft_put_length(str, ft_strlen(str));
		}
	}
	return (length);
}

int	ft_print_un(unsigned int n, t_outlst lst)
{
	unsigned long int	length;
	char				*str;

	length = 0;
	str = (n == 0 && lst.dot == 0) ? ft_strdup("") : ft_itoa(n);
	if (lst.dot == 0 && n == 0)
		length += ft_check_ifnull_un(lst, str);
	else
	{
		length += (lst.minus == 1) ? ft_print_utils_un(lst, str) : 0;
		if (lst.dot >= 0 && lst.dot <= ft_strlen(str))
			lst.dot = ft_strlen(str);
		if (lst.dot >= 0)
		{
			lst.width -= lst.dot;
			length += ft_put_utils_width(lst.width, 0, 0);
		}
		else if (lst.dot <= 0 && lst.width == 0 && !lst.zero)
			length += ft_put_utils_width(lst.width - ft_strlen(str), 0, 0);
		length += (lst.minus == 0) ? ft_check_un(lst, str) : 0;
	}
	free(str);
	return (length);
}
