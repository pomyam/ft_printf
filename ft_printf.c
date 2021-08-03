/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyamcha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 12:30:47 by pyamcha           #+#    #+#             */
/*   Updated: 2021/01/31 14:47:27 by pyamcha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	char	*str;
	int		length;

	length = 0;
	if (!(str = ft_strdup(format)))
		return (0);
	va_start(ap, format);
	length += ft_parser(ap, format);
	va_end(ap);
	free(str);
	return (length);
}
