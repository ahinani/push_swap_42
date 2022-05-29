# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahinani <ahinani@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/11 15:02:54 by ahinani           #+#    #+#              #
#    Updated: 2022/05/22 21:00:10 by ahinani          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PS_SRCS		=	tools/args_tools.c			\
				tools/error_tools.c			\
				tools/stack_tools.c			\
				instructions/p_instr.c		\
				instructions/r_instr.c		\
				instructions/rr_instr.c		\
				instructions/s_instr.c		\
				sort/sort_tools.c			\
				sort/small_sort.c			\
				sort/big_sort.c				\
				push_swap.c

CK_SRCS		=	tools/args_tools.c			\
				tools/error_tools.c			\
				tools/stack_tools.c			\
				instructions/p_instr.c		\
				instructions/r_instr.c		\
				instructions/rr_instr.c		\
				instructions/s_instr.c		\
				checker_tools/checker.c

PS_OBJS		=	$(PS_SRCS:.c=.o)
CK_OBJS		=	$(CK_SRCS:.c=.o)

CC			=	gcc
RM			=	rm -f
CFLAGS		=	-Wall -Werror -Wextra

NAME		=	push_swap
NAME_B		=	checker
LIB			=	libft/libft.a
HEADER		=	push_swap.h

all			:	$(NAME) $(NAME_B) $(LIB)

$(NAME)		:	$(LIB) $(PS_OBJS) $(HEADER)
	@$(CC) $(CFLAGS) $(LIB) -I include $(PS_OBJS) -o $@
	@echo "\n\033[3m\033[2;32m[+]\033[2;37m	push_swap File was created ✅\033[0m\n"

bonus		:	$(NAME_B) $(LIB)

$(NAME_B)	:	$(LIB) $(CK_OBJS) $(HEADER)
	@$(CC) $(CFLAGS) $(LIB) -I include $(CK_OBJS) -o $@
	@echo "\n\033[3m\033[2;32m[+]\033[2;37m	checker File was created ✅\033[0m\n"
	
%.o			:	%.c
	@$(CC) $(CFLAGS) -I include -c $< -o $(<:.c=.o)
	

$(LIB)		:
	@make all -C libft
	

clean		:
	@make clean -C libft
	@$(RM) $(PS_OBJS)
	@$(RM) $(CK_OBJS)
	
	
fclean		:
	@make fclean -C libft
	@$(RM) $(PS_OBJS)
	@$(RM) $(CK_OBJS)
	@$(RM) $(NAME_B)
	@$(RM) $(NAME)
	

re			:	fclean all

.PHONY		:	all bonus re clean fclean