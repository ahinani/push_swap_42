/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahinani <ahinani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 16:45:13 by ahinani           #+#    #+#             */
/*   Updated: 2022/05/22 12:36:40 by ahinani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	show_message(const char *msg)
{
	printf("%s\n", msg);
	exit(EXIT_FAILURE);
}

static int	number_checker(char *join)
{
	int	i;
	int	exp1;
	int	exp2;

	i = -1;
	while (join[++i])
	{
		exp1 = (!(join[i] == '-' && ft_isdigit(join[i + 1]))
				&& !(join[i] == '+' && ft_isdigit(join[i + 1]))
				&& !ft_isdigit(join[i]) && join[i] != ' ');
		exp2 = ((ft_isdigit(join[i]) && join[i + 1] == '-')
				|| (ft_isdigit(join[i]) && join[i + 1] == '+'));
		if (exp1 || exp2)
			return (FALSE);
	}
	return (TRUE);
}

static int	duplicated_number(char **list, char *nbr, int pos)
{
	int	i;

	i = -1;
	while (++i < pos)
		if (ft_atoi(list[i]) == ft_atoi(nbr))
			return (TRUE);
	return (FALSE);
}

static void	add_to_stack(char **list, t_stack *stack)
{
	int	i;
	int	j;
	int	s;
	int	index;

	s = -1;
	while (list[++s])
		if (duplicated_number(list, list[s], s))
			show_message(ERROR_MSG);
	index = s - 1;
	i = -1;
	while (list[++i])
	{
		j = -1;
		while (list[++j])
			if (ft_atoi(list[i]) < ft_atoi(list[j]) && i != j)
				index--;
		ft_dlst_addback(&stack->a, ft_dlstnew(index));
		index = s - 1;
	}
	stack->size_a = ft_dlstsize(stack->a);
	i = -1;
	while (list[++i])
		free(list[i]);
	free(list);
}

void	args_reader(t_stack *stack, int ac, char **av)
{
	char	**list;
	char	*join;
	char	*tmp;
	int		r;

	r = 0;
	join = ft_strdup("");
	while (++r < ac)
	{
		if (just_spaces(av[r]) || av[r][0] == '\0'
			|| ft_atoi(av[r]) > INT_MAX || ft_atoi(av[r]) < INT_MIN)
			show_message(ERROR_MSG);
		tmp = join;
		join = ft_strjoin(tmp, av[r]);
		free(tmp);
		tmp = join;
		join = ft_strjoin(tmp, " ");
		free(tmp);
	}
	if (!number_checker(join))
		show_message(ERROR_MSG);
	list = ft_split(join, ' ');
	add_to_stack(list, stack);
	free(join);
}
