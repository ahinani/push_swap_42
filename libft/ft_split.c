/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahinani <ahinani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 14:42:07 by ahinani           #+#    #+#             */
/*   Updated: 2021/11/29 14:31:50 by ahinani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

static int	ft_count_rows(char const *s, char c)
{
	int	i;
	int	r;

	i = 0;
	r = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			r++;
		i++;
	}
	return (r);
}

static int	ft_length(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != c && s[i])
		i++;
	return (i);
}

static void	ft_free(char **sp, int l)
{
	int	i;

	i = 0;
	while (i < l)
	{
		free(sp[i]);
		i++;
	}
	free(sp);
}

static void	ft_write_sp(char **sp, char const *s, char c, int w)
{
	int	i;
	int	l;
	int	j;

	i = -1;
	while (++i < w)
	{
		while (*s == c)
			s++;
		l = ft_length(s, c);
		sp[i] = (char *)malloc(sizeof(char) * (l + 1));
		if (!sp[i])
			ft_free(sp, i);
		j = 0;
		while (j < l)
			sp[i][j++] = *s++;
		sp[i][j] = '\0';
	}
	sp[i] = NULL;
}

char	**ft_split(char const *s, char c)
{
	int		w;
	char	**rtn;

	if (!s)
		return (NULL);
	w = ft_count_rows(s, c);
	rtn = (char **)malloc(sizeof(char *) * (w + 1));
	if (!rtn)
		return (NULL);
	ft_write_sp(rtn, s, c, w);
	return (rtn);
}
