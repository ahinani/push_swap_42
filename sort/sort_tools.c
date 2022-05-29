/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahinani <ahinani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 18:39:10 by ahinani           #+#    #+#             */
/*   Updated: 2022/05/22 12:38:51 by ahinani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	unordered_list(t_dlist *tmp)
{
	while (tmp && tmp->next)
	{
		if (tmp->data > tmp->next->data)
			return (TRUE);
		tmp = tmp->next;
	}
	return (FALSE);
}

void	sort_list(t_stack *stack)
{
	if (stack->size_a <= 5)
		small_sort(stack);
	else
		big_sort(stack);
}
