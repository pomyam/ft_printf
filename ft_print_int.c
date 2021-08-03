/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyamcha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 14:27:51 by pyamcha           #+#    #+#             */
/*   Updated: 2021/01/31 14:31:38 by pyamcha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_utils_int(char *str, int tmp, t_outlst lst, size_t count)
{
	int	length;

	length = 0;
	if (tmp < 0 && lst.dot >= 0)
		ft_putchar('-');
	if (lst.dot >= 0 && tmp == -2147483648)
	{
		length += ft_put_utils_width(lst.dot - 1, count - 1, 1);
		length += ft_put_length(str, count);
	}
	else if (lst.dot >= 0)
	{
		length += ft_put_utils_width(lst.dot - 1, count - 1, 1);
		length += ft_put_length(str, count);
	}
	else
		length += ft_put_length(str, count);
	return (length);
}

int	ft_check_int(char *str, int tmp, t_outlst lst)
{
	size_t	count;
	size_t	length;

	length = 0;
	count = ft_strlen(str);
	if (lst.minus == 1)
	{
		lst.zero = 0;
		length += ft_print_utils_int(str, tmp, lst, count);
	}
	if (lst.dot >= 0 && (size_t)lst.dot < count)
		lst.dot = count;
	if (lst.dot >= 0)
		length += ft_put_utils_width(lst.width - lst.dot, 0, 0);
	else if (lst.zero == 1 && lst.width == 1)
	{
		lst.zero = 0;
		length += ft_put_utils_width(lst.width, count, lst.zero);
	}
	else
		length += ft_put_utils_width(lst.width, count, lst.zero);
	if (lst.minus == 0)
		length += ft_print_utils_int(str, tmp, lst, count);
	return (length);
}

int	ft_neg_tmp(t_outlst *lst, long long *tmp)
{
	int	length;

	length = 0;
	if (lst->zero == 1 && lst->dot < 0)
		ft_putchar('-');
	*tmp *= -1;
	lst->zero = 1;
	lst->width--;
	length++;
	return (length);
}

int	ft_print_int(long long n, t_outlst lst)
{
	int			length;
	long long	tmp;
	char		*str;

	length = 0;
	tmp = n;
	str = NULL;
	if (lst.dot == 0 && n == 0)
		length += ft_put_utils_width(lst.width - lst.dot, 0, 0);
	if (tmp < 0 && (lst.dot >= 0 || lst.zero == 1))
		length += ft_neg_tmp(&lst, &tmp);
	if (!(tmp == 0 && lst.dot == 0))
	{
		str = ft_itoa_int(tmp);
		length += (lst.dot < 0 && lst.zero == 1) ? ft_check_int(str, n, lst) :
			ft_check_int(str, n, lst);
	}
	free(str);
	return (length);
}
