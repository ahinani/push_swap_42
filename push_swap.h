/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahinani <ahinani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 22:51:25 by ahinani           #+#    #+#             */
/*   Updated: 2022/05/23 15:53:48 by ahinani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define ERROR_MSG "\e[0;31mError\e[0m"
# define YELLOW "\033[0;33m"
# define TRUE 1
# define FALSE 0

# include "libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <unistd.h>

typedef struct s_stack
{
	t_dlist	*a;
	t_dlist	*b;
	t_dlist	*tmp;
	int		size_a;
	int		size_b;
}	t_stack;

int			just_spaces(char *s);
void		args_reader(t_stack	*stack, int ac, char **av);
t_stack		*stack_init(void);
void		free_all(t_stack *stack, char *join, char **list);
void		pa(t_stack *stack, int flag);
void		pb(t_stack *stack, int flag);
void		ra(t_stack *stack, int flag);
void		rb(t_stack *stack, int flag);
void		rr(t_stack *stack, int flag);
void		rra(t_stack *stack, int flag);
void		rrb(t_stack *stack, int flag);
void		rrr(t_stack *stack, int flag);
void		sa(t_stack *obj, int flag);
void		sb(t_stack *obj, int flag);
void		ss(t_stack *obj, int flag);
int			unordered_list(t_dlist *tmp);
void		sort_list(t_stack *stack);
void		small_sort(t_stack *stack);
int			smart_rotate(t_stack *stack);
void		big_sort(t_stack *stack);
void		show_message(const char *msg);
#endif