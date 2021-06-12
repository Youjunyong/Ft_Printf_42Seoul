# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juyou <juyou@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/24 16:37:37 by tsecret           #+#    #+#              #
#    Updated: 2021/06/10 00:38:52 by juyou            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
NAME = libftprintf.a


CFALGS = -Wall -Werror -Wextra
SRC = ft_printf.c ft_precision.c ft_flag.c\
	 ft_printf_c.c ft_utils.c ft_width.c\
	 ft_printf_str.c ft_printf_int.c\
	 ft_printf_p.c ft_printf_uint.c\

OBJS = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)


	ar cr $@ $(OBJS)

%.o : %.c ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@

clean :

	rm -f $(OBJS)
fclean : clean

	rm -f $(NAME)
re : fclean clean all

.PHONY : clean fclean re all
