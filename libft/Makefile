# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahinani <ahinani@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/21 12:52:24 by ahinani           #+#    #+#              #
#    Updated: 2022/05/22 20:49:29 by ahinani          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = libft.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRC =   ft_isalnum.c			\
		ft_isascii.c			\
		ft_isprint.c			\
		ft_memset.c				\
		ft_strlen.c				\
		ft_tolower.c			\
		ft_bzero.c				\
		ft_isalpha.c			\
		ft_isdigit.c			\
		ft_memchr.c				\
		ft_memcpy.c				\
		ft_memmove.c			\
		ft_strchr.c				\
		ft_strlcpy.c			\
		ft_strncmp.c			\
		ft_strrchr.c			\
		ft_atoi.c				\
		ft_strnstr.c			\
		ft_toupper.c			\
		ft_strlcat.c			\
		ft_memcmp.c				\
		ft_calloc.c				\
		ft_strdup.c				\
		ft_putchar_fd.c			\
		ft_putstr_fd.c			\
		ft_putendl_fd.c			\
		ft_substr.c				\
		ft_strjoin.c			\
		ft_strtrim.c			\
		ft_putnbr_fd.c			\
		ft_split.c				\
		ft_itoa.c				\
		ft_strmapi.c			\
		ft_striteri.c			\
		ft_dlst_addback.c		\
		ft_dlstadd_front.c		\
		ft_dlstfirst.c			\
		ft_dlstlast.c			\
		ft_dlstnew.c			\
		ft_dlstsize.c			\
		get_next_line.c			\
		get_next_line_utils.c

OBJECTS = $(SRC:.c=.o)

INCLUDES = libft.h

all: $(NAME)

$(NAME): $(OBJECTS) $(INCLUDES)
	ar rcs $(NAME) $(OBJECTS)
	@echo "\n\033[3m\033[2;32m[+]\033[2;37m	Library was created succefully ✅\033[0m\n"

%.o : %.c
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	rm -rf $(OBJECTS)
	@echo "\n\033[3m\033[2;32m[+]\033[2;37m	Cleaning ✅\033[0m\n"

fclean: clean
	rm -rf $(NAME)
	@echo "\n\033[3m\033[2;32m[+]\033[2;37m	Files Removed ✅\033[0m\n"

re: fclean all

.PHONY: all re clean fclean
