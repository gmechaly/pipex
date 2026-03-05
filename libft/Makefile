# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gmechaly <gmechaly@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/17 13:44:53 by gmechaly          #+#    #+#              #
#    Updated: 2024/12/05 16:22:05 by gmechaly         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wextra -Wall -Werror -g -I$(INCLUDES)
NAME = libft.a
INCLUDES = includes/
FILES = ft_putchar_fd.c ft_putstr_fd.c ft_atoi.c ft_strlen.c ft_bzero.c \
		ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c \
		ft_isprint.c ft_itoa.c ft_memchr.c ft_memcmp.c ft_memcpy.c \
		ft_memmove.c ft_memset.c ft_putendl_fd.c ft_putnbr_fd.c ft_split.c \
		ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c \
		ft_strlcpy.c ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c \
		ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c \
		ft_printchar.c ft_printlowhexa.c ft_printnbr.c ft_printptr.c \
		ft_printstr.c ft_printunint.c ft_printuphexa.c ft_printf.c
BONUSFILES = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c \
		ft_lstadd_back_bonus.c ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c \
		ft_lstmap_bonus.c
OBJ = $(FILES:.c=.o)
OBJBONUS = $(BONUSFILES:.c=.o)

all: $(NAME)

$(NAME) : $(OBJ) $(OBJBONUS) $(INCLUDES)
	ar rcs $(NAME) $(OBJ) $(OBJBONUS) -o $(NAME)

.c.o :
	$(CC) $(CFLAGS) -c $< -o $@ -I$(INCLUDES)

clean:
	rm -rf $(OBJ) $(OBJBONUS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re all