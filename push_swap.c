/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahinani <ahinani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 22:50:36 by ahinani           #+#    #+#             */
/*   Updated: 2022/05/23 20:19:38 by ahinani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*stack;

	if (ac < 2)
		printf("%s%s", YELLOW, "Usage: ./push_swap with <list of args>");
	stack = stack_init();
	args_reader(stack, ac, av);
	if (unordered_list(stack->a))
		sort_list(stack);
	free_all(stack, NULL, NULL);
	exit(EXIT_SUCCESS);
}
