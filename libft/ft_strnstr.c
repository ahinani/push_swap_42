/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahinani <ahinani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 14:40:52 by ahinani           #+#    #+#             */
/*   Updated: 2021/12/05 16:14:59 by ahinani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	char	*h;

	h = (char *)haystack;
	if (ft_strlen(needle) == 0)
		return (h);
	i = 0;
	while (h[i] && i < len)
	{
		j = 0;
		while (needle[j] && h[i + j] && i + j < len && h[i + j] == needle[j])
			j++;
		if (j == ft_strlen(needle))
			return (h + i);
		i++;
	}
	return (NULL);
}
