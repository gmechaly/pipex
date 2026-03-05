# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gmechaly <gmechaly@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/10 18:58:22 by gmechaly          #+#    #+#              #
#    Updated: 2024/12/11 20:46:23 by gmechaly         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Werror -Wextra -g -I$(INCLUDES)
NAME = pipex
INCLUDES = includes/
FILES = main.c tools.c pipex.c
OBJ = $(FILES:.c=.o)

LIBFT_DIR = libft/
LIBFT = libft/libft.a
LIBFT_H = libft/includes/

all: $(NAME)

$(NAME) : $(OBJ) $(LIBFT) $(INCLUDES)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

.c.o :
	$(CC) $(CFLAGS) -c $< -o $@ -I$(INCLUDES) -I$(LIBFT_H)

$(LIBFT) :
	make -C $(LIBFT_DIR)

clean:
	rm -rf $(OBJ)
	make clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: clean fclean re all