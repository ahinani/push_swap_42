/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_instr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahinani <ahinani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 15:32:13 by ahinani           #+#    #+#             */
/*   Updated: 2022/05/22 12:37:01 by ahinani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	push(t_dlist **dst, t_dlist **src, int *d_size, int *s_size)
{
	if (!*src)
		return (FALSE);
	if (*s_size > 0)
	{
		if (*s_size == 1)
		{
			(*src)->next = *dst;
			*dst = *src;
			*src = NULL;
		}
		else
		{
			*src = (*src)->next;
			(*src)->prev->next = *dst;
			*dst = (*src)->prev;
			(*src)->prev = NULL;
		}
		if (*d_size)
			(*dst)->next->prev = *dst;
		(*s_size)--;
		(*d_size)++;
		return (TRUE);
	}
	return (FALSE);
}

void	pa(t_stack *stack, int flag)
{
	if (push(&stack->a, &stack->b, &stack->size_a, &stack->size_b) && flag)
		ft_putendl_fd("pa", 1);
}

void	pb(t_stack *stack, int flag)
{
	if (push(&stack->b, &stack->a, &stack->size_b, &stack->size_a) && flag)
		ft_putendl_fd("pb", 1);
}
