/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyamcha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 14:24:28 by pyamcha           #+#    #+#             */
/*   Updated: 2021/01/31 17:05:03 by pyamcha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_utils_hex(char *hex, t_outlst lst, size_t count)
{
	int	length;

	length = 0;
	if (lst.dot >= 0)
		length += ft_put_utils_width(lst.dot - 2, count - 2, 1);
	length += ft_put_length(hex, count);
	return (length);
}

int	ft_check_hex(char *hex, t_outlst lst)
{
	size_t	count;
	int		length;

	length = 0;
	count = ft_strlen(hex);
	if (lst.minus == 1)
		length += ft_print_utils_hex(hex, lst, count);
	if (lst.dot >= 0 && (size_t)lst.dot < count)
		lst.dot = count;
	if (lst.dot >= 0)
	{
		lst.width -= lst.dot;
		length += ft_put_utils_width(lst.width, 0, 0);
	}
	else
	{
		if (lst.minus == 1)
			length += ft_put_utils_width(lst.width, count, 0);
		else
			length += ft_put_utils_width(lst.width, count, lst.zero);
	}
	if (lst.minus == 0)
		length += ft_print_utils_hex(hex, lst, count);
	return (length);
}

int	ft_print_hex(unsigned int n, t_outlst lst, int flag)
{
	char	*hex;
	int		length;

	length = 0;
	if (lst.dot == 0 && n == 0)
	{
		length += ft_put_utils_width(lst.width, 0, 0);
		return (length);
	}
	hex = ft_itoa_hex((unsigned long long)n, 16);
	if (flag == 0)
		hex = ft_str_tolower(hex);
	length += ft_check_hex(hex, lst);
	free(hex);
	return (length);
}
