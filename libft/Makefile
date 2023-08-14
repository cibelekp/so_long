# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ckojima- <ckojima-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/21 15:46:26 by ckojima-          #+#    #+#              #
#    Updated: 2022/11/21 15:46:26 by ckojima-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= ft_isalpha.c \
		ft_isdigit.c \
		ft_isalnum.c \
		ft_isascii.c \
		ft_isprint.c \
		ft_tolower.c \
		ft_toupper.c \
		ft_bzero.c \
		ft_strlen.c \
		ft_strlcat.c \
		ft_strlcpy.c \
		ft_strchr.c \
		ft_strrchr.c \
		ft_strdup.c \
		ft_strncmp.c \
		ft_strnstr.c \
		ft_memset.c \
		ft_memcpy.c \
		ft_memmove.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_atoi.c \
		ft_itoa.c \
		ft_calloc.c \
		ft_substr.c \
		ft_strjoin.c \
		ft_strtrim.c \
		ft_split.c \
		ft_strmapi.c \
		ft_striteri.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putnbr_fd.c \
		ft_putendl_fd.c \


BNS		= ft_lstnew.c \
		ft_lstadd_front.c \
		ft_lstsize.c \
		ft_lstlast.c \
		ft_lstadd_back.c \
		ft_lstdelone.c \
		ft_lstclear.c \
		ft_lstiter.c \
		ft_lstmap.c 

CC				= cc
CFLAGS			= -Wall -Wextra -Werror
OBJECTS			= ${SRCS:.c=.o}
OBJECTS_BONUS	= ${BNS:.c=.o}
HEAD			= libft.h
NAME			= libft.a
LIBC			= ar -rcs
RM				= rm -rf
LIBLIST			= ar -t

$(VERBOSE).SILENT:

${NAME}: ${OBJECTS}
	${LIBC} ${NAME} ${OBJECTS}

all: ${NAME}

bonus: ${NAME} ${OBJECTS_BONUS}
	${LIBC} ${NAME} ${OBJECTS_BONUS}

clean:
	${RM} ${OBJECTS} ${OBJECTS_BONUS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all, bonus, clean, fclean, re