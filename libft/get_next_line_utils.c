/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahinani <ahinani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 22:47:12 by ahinani           #+#    #+#             */
/*   Updated: 2022/05/23 22:49:29 by ahinani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen_gnl(const char *s)
{
	size_t	len;

	len = 0;
	while (s && s[len])
		len++;
	return (len);
}

int	nl_found(const char *s)
{
	while (s && *s)
	{
		if (*s == '\n')
			return (1);
		s++;
	}
	return (0);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	char	*rtn;
	int		l;
	int		i;
	int		j;

	if (!s1)
	{
		s1 = (char *)malloc(1);
		*s1 = '\0';
	}
	l = ft_strlen_gnl(s1) + ft_strlen_gnl(s2);
	rtn = (char *)malloc(l + 1);
	if (!rtn)
		return (NULL);
	i = -1;
	while (s1[++i])
		rtn[i] = s1[i];
	j = -1;
	while (i < l)
		rtn[i++] = s2[++j];
	rtn[l] = '\0';
	free(s1);
	return (rtn);
}
