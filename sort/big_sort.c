/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahinani <ahinani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 16:01:36 by ahinani           #+#    #+#             */
/*   Updated: 2022/05/22 12:38:08 by ahinani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	push_in_parts(t_stack *stack, int part_size)
{
	int	part_nb;
	int	part_tv;
	int	part;

	part_nb = 1;
	part_tv = 0;
	while (stack->size_a)
	{
		part = part_size * part_nb;
		if (stack->a->data < part)
		{
			pb(stack, 1);
			if (stack->b->data < part - (part_size / 2))
				rb(stack, 1);
			part_tv++;
		}
		else
			ra(stack, 1);
		if (part_tv == part)
			part_nb++;
	}
}

static int	push_next(t_stack *stack, int swap)
{
	if (stack->b->data == stack->size_b - 2 && !swap)
	{
		pa(stack, 1);
		return (1);
	}
	return (0);
}

int	smart_rotate(t_stack *stack)
{
	int	pos;
	int	swap;
	int	size;

	pos = 0;
	swap = 0;
	size = stack->size_b;
	stack->tmp = stack->b;
	while (stack->tmp->data != size - 1 && ++pos)
		stack->tmp = stack->tmp->next;
	while (stack->b->data != size - 1)
	{
		if (!push_next(stack, swap))
		{
			if (pos > size / 2)
				rrb(stack, 1);
			else
				rb(stack, 1);
		}
		else
			swap = 1;
	}
	return (swap);
}

static void	push_back(t_stack *stack)
{
	while (stack->size_b)
	{
		if (smart_rotate(stack))
		{
			pa(stack, 1);
			sa(stack, 1);
		}
		else
			pa(stack, 1);
	}
}

void	big_sort(t_stack *stack)
{
	int	part_size;

	part_size = stack->size_a / 10 + 12;
	push_in_parts(stack, part_size);
	push_back(stack);
}
