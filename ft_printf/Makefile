# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ckojima- <ckojima-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/17 18:30:21 by ckojima-          #+#    #+#              #
#    Updated: 2022/12/17 18:30:21 by ckojima-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			= cc
CFLAGS		= -Wall -Werror -Wextra

NAME		= ft_printf.a
HEAD		= ft_printf.h
SOURCES		= ft_printf.c \
			ft_aux_basic.c \
			ft_aux_hexa.c

OBJECTS		= ${SOURCES:.c=.o}
MKLIB		= ar -rcs
RM			= rm -rf
LIB_FILES	= ar -t

${NAME}: ${OBJECTS}
	${MKLIB} ${NAME} ${OBJECTS}

all: ${NAME}

clean:
	${RM} ${OBJECTS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all, clean, fclean, re, test, tclean