/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_instr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahinani <ahinani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 15:37:22 by ahinani           #+#    #+#             */
/*   Updated: 2022/05/22 12:37:52 by ahinani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	swap(t_dlist **head, int size)
{
	if (!*head)
		return (FALSE);
	if (size > 1)
	{
		if (size == 2)
		{
			*head = (*head)->next;
			(*head)->next = (*head)->prev;
			(*head)->prev->next = NULL;
			(*head)->prev = NULL;
		}
		else
		{
			*head = (*head)->next;
			(*head)->next->prev = (*head)->prev;
			(*head)->prev->next = (*head)->next;
			(*head)->next = (*head)->prev;
			(*head)->prev->prev = *head;
			(*head)->prev = NULL;
		}
		return (TRUE);
	}
	return (FALSE);
}

void	sa(t_stack *stack, int flag)
{
	if (swap(&stack->a, stack->size_a) && flag)
		ft_putendl_fd("sa", 1);
}

void	sb(t_stack *stack, int flag)
{
	if (swap(&stack->b, stack->size_b) && flag)
		ft_putendl_fd("sb", 1);
}

void	ss(t_stack *stack, int flag)
{
	if (swap(&stack->a, stack->size_a)
		&& swap(&stack->b, stack->size_b) && flag)
		ft_putendl_fd("ss", 1);
}
