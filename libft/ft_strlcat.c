/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahinani <ahinani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 13:52:01 by ahinani           #+#    #+#             */
/*   Updated: 2021/11/20 11:57:09 by ahinani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	d_len;
	size_t	s_len;
	size_t	rtn;

	s_len = ft_strlen(src);
	if (dst == NULL && dstsize == 0)
		return (s_len);
	d_len = ft_strlen(dst);
	if (d_len < dstsize)
		rtn = d_len + s_len;
	else
		rtn = s_len + dstsize;
	i = 0;
	while (src[i] != '\0' && (d_len + 1 < dstsize))
	{
		dst[d_len] = src[i];
		d_len++;
		i++;
	}
	dst[d_len] = '\0';
	return (rtn);
}
