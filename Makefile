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

NAME		= libft.a

SRCS		= ft_printf.c

OBJS		= ${SRCS:.c=.o}

CC		= cc
RM		= rm -f
CFLAGS		= -Wall -Wextra -Werror

CL 		= ar -rc
RL 		= ar -s
${NAME}:	${OBJS}
		${CL} ${NAME} ${OBJS}
		${RL} ${NAME}
		echo 'printf is ready'
all:		${NAME}
clean:
		${RM} ${OBJS}
		echo 'Objects removed'
fclean:	clean
		${RM} ${NAME}
		echo 'Static library removed'
re:		fclean all
