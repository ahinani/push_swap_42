/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_instr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahinani <ahinani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 15:35:21 by ahinani           #+#    #+#             */
/*   Updated: 2022/05/22 12:37:27 by ahinani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	rotate(t_dlist **head, int size)
{
	if (!*head)
		return (FALSE);
	if (size > 1)
	{
		(*head) = (*head)->next;
		(*head)->prev->prev = ft_dlstlast(*head);
		(*head)->prev->prev->next = (*head)->prev;
		(*head)->prev->prev->next->next = NULL;
		(*head)->prev = NULL;
		return (TRUE);
	}
	return (FALSE);
}

void	ra(t_stack *stack, int flag)
{
	if (rotate(&stack->a, stack->size_a) && flag)
		ft_putendl_fd("ra", 1);
}

void	rb(t_stack *tab, int flag)
{
	if (rotate(&tab->b, tab->size_b) && flag)
		ft_putendl_fd("rb", 1);
}

void	rr(t_stack *stack, int flag)
{
	if (rotate(&stack->a, stack->size_a)
		&& rotate(&stack->b, stack->size_b) && flag)
		ft_putendl_fd("rr", 1);
}
