# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bapereir <bapereir@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/13 15:17:33 by bapereir          #+#    #+#              #
#    Updated: 2023/07/27 17:07:50 by bapereir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a

SRCS		= ft_printf.c ft_print_%c%s.c ft_print_%p.c ft_print_%d%i.c ft_print_%u.c

OBJ		= $(SRCS:.c=.o)

INCLUDES = libft/libft.h

CC		= cc

RM		= rm -f

CFLAGS		= -Wall -Wextra -Werror

.c.o:
		$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $(<:.c=.o)

$(NAME):	$(OBJ)
		make -C libft
		cp libft/libft.a $(NAME)
		ar rcs $(NAME) $(OBJ)
		echo 'printf is ready'

all:		$(NAME)

clean:
		make clean -C libft
		$(RM) $(OBJ)
		echo 'Objects removed'

fclean:	clean
		$(RM) $(NAME)
		echo 'Static library removed'

re:		fclean all