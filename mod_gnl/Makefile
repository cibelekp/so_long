# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ckojima- <ckojima-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/14 10:26:33 by ckojima-          #+#    #+#              #
#    Updated: 2023/08/14 10:26:33 by ckojima-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			= cc
CFLAGS		= -Wall -Werror -Wextra

NAME		= gnl.a
HEAD		= get_next_line.h
SOURCES		= get_next_line.c \
			get_next_line_utils.c \
			# get_next_line_bonus.c \
			get_next_line_utils_bonus.c

OBJECTS		= ${SOURCES:.c=.o}
MKLIB		= ar -rcs
RM			= rm -rf
LIB_FILES	= ar -t

#Silencing makefile
$(VERBOSE).SILENT:

${NAME}: ${OBJECTS}
	${MKLIB} ${NAME} ${OBJECTS}

all: ${NAME}

clean:
	${RM} ${OBJECTS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all, clean, fclean, re, test, tclean