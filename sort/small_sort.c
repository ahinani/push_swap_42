/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahinani <ahinani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 14:05:30 by ahinani           #+#    #+#             */
/*   Updated: 2022/05/26 16:26:46 by ahinani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	is_ordered(int *arr)
{
	int	i;

	i = 0;
	while (i < 3 && i + 1 < 3)
	{
		if (arr[i] > arr[i + 1])
			return (FALSE);
		i++;
	}
	return (TRUE);
}

static void	update_array(t_stack *stack, int *arr)
{
	arr[0] = stack->a->data;
	arr[1] = stack->a->next->data;
	arr[2] = stack->a->next->next->data;
}

static void	sort_3(t_stack *stack)
{
	int	arr[3];

	update_array(stack, arr);
	while (!is_ordered(arr))
	{
		update_array(stack, arr);
		if (arr[0] > arr[1] && arr[0] > arr[2])
		{
			ra(stack, 1);
			continue ;
		}
		if (arr[2] < arr[1])
		{
			rra(stack, 1);
			continue ;
		}
		if (arr[0] > arr[1])
		{
			sa(stack, 1);
			break ;
		}
	}
}

static void	sort_4_5(t_stack *stack)
{
	int	size;

	size = stack->size_a;
	while (stack->a && stack->size_a > 3)
	{
		if (stack->a->data < (size - 3))
			pb(stack, 1);
		else
			ra(stack, 1);
	}
	sort_3(stack);
	while (stack->b && stack->size_b)
	{
		if (stack->size_b > 1
			&& stack->b->data < stack->b->next->data)
			rb(stack, 1);
		pa(stack, 1);
	}
}

void	small_sort(t_stack *stack)
{
	if (stack->size_a == 2)
		if (stack->a->data > stack->a->next->data)
			sa(stack, 1);
	if (stack->size_a == 3)
		sort_3(stack);
	if (stack->size_a == 4 || stack->size_a == 5)
		sort_4_5(stack);
}
