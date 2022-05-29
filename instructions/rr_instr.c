/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr_instr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahinani <ahinani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 15:36:40 by ahinani           #+#    #+#             */
/*   Updated: 2022/05/22 12:37:43 by ahinani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	r_rotate(t_dlist **head, int size)
{
	if (!*head)
		return (FALSE);
	if (size > 1)
	{
		*head = ft_dlstlast(*head);
		(*head)->next = ft_dlstfirst(*head);
		(*head)->next->prev = *head;
		(*head)->prev->next = NULL;
		(*head)->prev = NULL;
		return (TRUE);
	}
	return (FALSE);
}

void	rra(t_stack *stack, int flag)
{
	if (r_rotate(&stack->a, stack->size_a) && flag)
		ft_putendl_fd("rra", 1);
}

void	rrb(t_stack *stack, int flag)
{
	if (r_rotate(&stack->b, stack->size_b) && flag)
		ft_putendl_fd("rrb", 1);
}

void	rrr(t_stack *stack, int flag)
{
	if (r_rotate(&stack->a, stack->size_a)
		&& r_rotate(&stack->b, stack->size_b) && flag)
		ft_putendl_fd("rrr", 1);
}
