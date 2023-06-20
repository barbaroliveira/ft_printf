# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bapereir <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/13 15:17:33 by bapereir          #+#    #+#              #
#    Updated: 2023/05/13 15:18:34 by bapereir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a

SRCS		= ft_printf.c

OBJ		= ${SRCS:.c=.o}

INCLUDES = inc/libftprintf.h

CC		= cc

RM		= rm -f

CFLAGS		= -Wall -Wextra -Werror

.c.o:
		$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $(<:.c=.o)

${NAME}:	${OBJS}
		make -C libft
		cp libft/libft.a $(NAME)
		ar rcs $(NAME) $(OBJ)
		echo 'printf is ready'

all:		${NAME}

clean:
		make clean -C libft
		${RM} ${OBJS}
		echo 'Objects removed'

fclean:	clean
		${RM} ${NAME}
		echo 'Static library removed'

re:		fclean all