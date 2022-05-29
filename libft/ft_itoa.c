/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahinani <ahinani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 23:46:36 by ahinani           #+#    #+#             */
/*   Updated: 2021/11/29 14:30:44 by ahinani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_array(char *arr, unsigned int number, int len)
{
	while (number > 0)
	{
		arr[len--] = 48 + (number % 10);
		number = number / 10;
	}
	return (arr);
}

static int	ft_len(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len = 1;
	while (n != 0)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char			*arr;
	int				len;
	unsigned int	number;
	int				sign;

	sign = 1;
	len = ft_len(n);
	arr = (char *)malloc(sizeof(char) * (len + 1));
	if (!arr)
		return (NULL);
	arr[len--] = '\0';
	if (n == 0)
		arr[0] = '0';
	if (n < 0)
	{
		sign *= -1;
		number = n * -1;
		arr[0] = '-';
	}
	else
		number = n;
	arr = ft_array(arr, number, len);
	return (arr);
}
