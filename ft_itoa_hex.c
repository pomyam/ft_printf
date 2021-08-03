/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyamcha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 13:59:48 by pyamcha           #+#    #+#             */
/*   Updated: 2021/01/31 13:59:50 by pyamcha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_len(char *line, size_t length, unsigned long long int tmp, int d)
{
	char	*ret;

	if (!(ret = (char *)malloc(sizeof(char) * (length + 1))))
		return (NULL);
	ret[length] = 0;
	while (length != 0)
	{
		ret[length - 1] = line[tmp % d];
		tmp = tmp / d;
		length--;
	}
	return (ret);
}

char	*ft_itoa_hex(unsigned long long n, int del)
{
	char					*ret;
	char					*line;
	size_t					length;
	unsigned long long int	tmp;

	length = 0;
	tmp = n;
	if (n == 0)
	{
		if (!(ret = ft_strdup("0")))
			return (NULL);
		return (ret);
	}
	line = "0123456789abcdef";
	while (n != 0)
	{
		n = n / del;
		length++;
	}
	ret = ft_len(line, length, tmp, del);
	return (ret);
}
