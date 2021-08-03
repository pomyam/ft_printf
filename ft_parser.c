/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyamcha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 14:07:42 by pyamcha           #+#    #+#             */
/*   Updated: 2021/01/31 15:36:40 by pyamcha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_outlst	ft_init(void)
{
	t_outlst	lst;

	lst.zero = 0;
	lst.minus = 0;
	lst.dot = -1;
	lst.width = 0;
	lst.star = 0;
	lst.type = 0;
	return (lst);
}

int			ft_put_utils_width(int width, int len, int zero)
{
	int	length;

	length = 0;
	while (width - len > 0)
	{
		if (zero)
			ft_putchar('0');
		else
			ft_putchar(' ');
		width--;
		length++;
	}
	return (length);
}

int			ft_check_flag(va_list ap, t_outlst *lst, const char *s, int index)
{
	while (s[index])
	{
		if (!(ft_digit(s[index])) && !ft_spec(s[index]) && !ft_flag(s[index]))
			break ;
		if (s[index] == '-')
			*lst = ft_parse_minus(*lst);
		if (s[index] == '0' && lst->width == 0 && lst->minus == 0)
			lst->zero = 1;
		if (s[index] == '*')
			*lst = ft_parse_width(ap, *lst);
		if (s[index] == '.')
			index = ft_parse_dot(ap, lst, index, s);
		if (ft_digit(s[index]))
			*lst = ft_parse_digit(*lst, s[index]);
		if (ft_spec(s[index]))
		{
			lst->type = s[index];
			break ;
		}
		index++;
	}
	return (index);
}

int			ft_parse_type(va_list ap, int s, t_outlst lst)
{
	int length;

	length = 0;
	if (s == 'c')
		length += ft_print_char(va_arg(ap, int), lst);
	if (s == 's')
		length += ft_print_string(va_arg(ap, char *), lst);
	if (s == 'd' || s == 'i')
		length += ft_print_int(va_arg(ap, int), lst);
	if (s == 'u')
		length += ft_print_un(va_arg(ap, unsigned int), lst);
	if (s == 'p')
		length += ft_print_pointer(va_arg(ap, void *), lst);
	if (s == 'x')
		length += ft_print_hex(va_arg(ap, unsigned int), lst, 1);
	if (s == 'X')
		length += ft_print_hex(va_arg(ap, unsigned int), lst, 0);
	if (s == '%')
		length += ft_print_proc(lst);
	return (length);
}

int			ft_parser(va_list ap, const char *s)
{
	int			index;
	int			length;
	t_outlst	lst;

	index = -1;
	length = 0;
	while (s[++index] != '\0')
	{
		lst = ft_init();
		if (s[index] == '%' && s[index + 1])
		{
			index++;
			index = ft_check_flag(ap, &lst, s, index);
			if (ft_spec(s[index]))
				length += ft_parse_type(ap, (char)lst.type, lst);
		}
		else if (s[index] != '%' && s[index + 1] == '%')
			length += ft_putchar(s[index]);
		else
			length += ft_putchar(s[index]);
	}
	return (length);
}
