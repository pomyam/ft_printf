/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extra_functions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyamcha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 13:54:18 by pyamcha           #+#    #+#             */
/*   Updated: 2021/01/31 13:55:44 by pyamcha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_spec(int s)
{
	return (s == 'c' || s == 's' || s == 'd' || s == 'i' || s == 'x' ||
			s == 'X' || s == 'p' || s == 'u' || s == '%');
}

int		ft_flag(int s)
{
	return (s == '-' || s == '0' || s == '*' || s == '.' || s == ' ');
}

int		ft_digit(int s)
{
	return (s >= '0' && s <= '9');
}

int		ft_tolower(int c)
{
	if (c >= 'a' && c <= 'z')
		return ((c - 'a') + 'A');
	return (c);
}

char	*ft_str_tolower(char *s)
{
	int	index;

	index = 0;
	while (s[index])
	{
		s[index] = ft_tolower(s[index]);
		index++;
	}
	return (s);
}
