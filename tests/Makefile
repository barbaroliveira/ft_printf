# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wcorrea- <wcorrea-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/22 22:59:46 by wcorrea-          #+#    #+#              #
#    Updated: 2023/04/22 22:59:52 by wcorrea-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PRINTF_PATH = ../

NAME = ${PRINTF_PATH}/libftprintf.a


CC = gcc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror
INCLUDE = -I ${PRINTF_PATH}
MAKE = make -C

m:		clean
		${MAKE} ${PRINTF_PATH} all
		${CC} ${CFLAGS} ${INCLUDE} mandatory.c ${NAME} -o m

clean:
		${RM} m

fclean: clean
		${MAKE} ${PRINTF_PATH} fclean
		
.PHONY: all clean fclean re
