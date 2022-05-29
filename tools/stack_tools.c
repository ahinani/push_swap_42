/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahinani <ahinani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 11:54:15 by ahinani           #+#    #+#             */
/*   Updated: 2022/05/22 12:39:28 by ahinani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	*stack_init(void)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		show_message(ERROR_MSG);
	stack->a = NULL;
	stack->b = NULL;
	stack->tmp = NULL;
	stack->size_a = 0;
	stack->size_b = 0;
	return (stack);
}

void	free_all(t_stack *stack, char *join, char **list)
{
	int	i;

	if (!stack)
		return ;
	if (list)
	{
		i = -1;
		while (list[++i])
			free(list[i]);
		free(list);
	}
	if (join)
		free(join);
	free(stack);
}
