/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahinani <ahinani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 17:29:30 by ahinani           #+#    #+#             */
/*   Updated: 2022/05/23 17:00:16 by ahinani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	instructions(t_stack *stack, char *ins)
{
	if (!ft_strncmp(ins, "sa\n", 4))
		sa(stack, 0);
	else if (!ft_strncmp(ins, "sb\n", 4))
		sb(stack, 0);
	else if (!ft_strncmp(ins, "ss\n", 4))
		ss(stack, 0);
	else if (!ft_strncmp(ins, "ra\n", 4))
		ra(stack, 0);
	else if (!ft_strncmp(ins, "rb\n", 4))
		rb(stack, 0);
	else if (!ft_strncmp(ins, "rr\n", 4))
		rr(stack, 0);
	else if (!ft_strncmp(ins, "rra\n", 4))
		rra(stack, 0);
	else if (!ft_strncmp(ins, "rrb\n", 4))
		rrb(stack, 0);
	else if (!ft_strncmp(ins, "rrr\n", 4))
		rrr(stack, 0);
	else if (!ft_strncmp(ins, "pa\n", 4))
		pa(stack, 0);
	else if (!ft_strncmp(ins, "pb\n", 4))
		pb(stack, 0);
	else
		show_message(ERROR_MSG);
}

static int	is_sorted(t_stack *stack)
{
	stack->tmp = stack->a;
	if (stack->size_b)
		return (FALSE);
	while (stack->tmp->next)
	{
		if (stack->tmp->data > stack->tmp->next->data)
			return (FALSE);
		stack->tmp = stack->tmp->next;
	}
	return (TRUE);
}

static void	check(t_stack *stack)
{
	char	*ins;

	ins = get_next_line(STDIN_FILENO);
	while (ins)
	{
		instructions(stack, ins);
		free(ins);
		ins = get_next_line(STDIN_FILENO);
	}
	free(ins);
	if (is_sorted(stack))
		ft_putendl_fd("OK", STDOUT_FILENO);
	else
		ft_putendl_fd("KO", STDOUT_FILENO);
}

int	main(int ac, char **av)
{
	t_stack	*stack;

	if (ac < 2)
		exit(EXIT_SUCCESS);
	stack = stack_init();
	args_reader(stack, ac, av);
	check(stack);
	free_all(stack, NULL, NULL);
	exit(EXIT_SUCCESS);
}
