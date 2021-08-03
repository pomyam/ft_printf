# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pyamcha <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/30 15:23:59 by pyamcha           #+#    #+#              #
#    Updated: 2021/01/30 15:30:32 by pyamcha          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc

RM = rm -f

FLAGS = -Wall -Werror -Wextra

HEADER = ft_printf.h

OPTION = -c -I ${HEADER}

SRCS = ft_extra_functions.c ft_itoa_hex.c ft_itoa.c ft_parser_flags.c ft_parser.c ft_print_char.c ft_print_hex.c ft_print_int.c ft_print_pointer.c ft_print_uns.c ft_printf.c ft_putchar.c ft_strdup.c ft_strlen.c

OBJS = ${SRCS:.c=.o}

all: ${NAME}

${NAME}: ${OBJS}
		ar rc ${NAME} ${OBJS}

clean:
		${RM} ${OBJS}
fclean: clean
		${RM} ${NAME}
re:		fclean all
