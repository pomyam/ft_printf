/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyamcha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 15:02:27 by pyamcha           #+#    #+#             */
/*   Updated: 2021/01/31 15:35:48 by pyamcha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct	s_output
{
	int			zero;
	int			minus;
	int			dot;
	int			width;
	int			star;
	int			type;
}				t_outlst;

int				ft_spec(int s);
int				ft_flag(int s);
int				ft_digit(int s);
char			*ft_str_tolower(char *s);
char			*ft_itoa_hex(unsigned long long n, int del);
char			*ft_itoa(unsigned long int n);
char			*ft_itoa_int(long long n);
t_outlst		ft_parse_width(va_list ap, t_outlst lst);
t_outlst		ft_parse_minus(t_outlst lst);
int				ft_parse_dot(va_list ap, t_outlst *lst,
				int index, const char *s);
t_outlst		ft_parse_digit(t_outlst lst, char s);
int				ft_put_utils_width(int width, int len, int zero);
int				ft_parser(va_list ap, const char *s);
int				ft_print_string(char *str, t_outlst lst);
int				ft_print_char(int n, t_outlst lst);
int				ft_print_proc(t_outlst lst);
int				ft_print_hex(unsigned int n, t_outlst lst, int flag);
int				ft_put_length(char *str, int count);
int				ft_print_int(long long n, t_outlst lst);
int				ft_print_pointer(void *n, t_outlst lst);
int				ft_print_un(unsigned int n, t_outlst lst);
int				ft_printf(const char *format, ...);
int				ft_putchar(int c);
char			*ft_strdup(const char *s);
int				ft_strlen(const char *a);
#endif
