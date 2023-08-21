# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ckojima- <ckojima-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/14 10:31:04 by ckojima-          #+#    #+#              #
#    Updated: 2023/08/14 10:31:04 by ckojima-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= so_long
SOURCES			= so_long.c map_checker.c 
OBJECTS			= $(SOURCES:.c=.o)
CC				= cc

CFLAGS			= -Wall -Wextra -Werror -g
CFLAGS			+= -fsanitize=address -fsanitize=undefined
RM				= rm -rf

#Libft
LIBFT = ./libft/libft.a
LIBFT_PATH = ./libft

#ft_printf
FT_PRINTF = ./ft_printf/ft_printf.a
FT_PRINTF_PATH = ./ft_printf

#GetNextLine
GNL = ./mod_gnl/gnl.a
GNL_PATH = ./mod_gnl

#Colors
GREEN=\033[0;32m
END=\033[0m

#Silencing makefile
$(VERBOSE).SILENT:

all: $(NAME)

$(NAME): $(OBJECTS)
	make -C $(LIBFT_PATH)
	@echo "$(GREEN)******** libft compiled ********$(END)"
	make -C $(FT_PRINTF_PATH)
	@echo "$(GREEN)******** ft_printf compiled ********$(END)"
	make -C $(GNL_PATH)
	@echo "$(GREEN)******** gnl compiled ********$(END)"
	$(CC) $(CFLAGS) $(OBJECTS) $(LIBFT) $(FT_PRINTF) $(GNL) -o $(NAME)
	@echo "$(GREEN)******** $(NAME) compiled ********$(END)"

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	make clean -C $(LIBFT_PATH) 
	make clean -C $(FT_PRINTF_PATH)
	make clean -C $(GNL_PATH)
	$(RM) $(OBJECTS)
	@echo "$(GREEN)******** everything clean ********$(END)"

fclean: clean
	make fclean -C $(LIBFT_PATH) 
	make fclean -C $(FT_PRINTF_PATH)
	make fclean -C $(GNL_PATH)
	$(RM) $(NAME)
	@echo "$(GREEN)******** $(NAME) removed ********$(END)"

re: fclean all

.PHONY: all, clean, fclean, re
