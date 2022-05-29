/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahinani <ahinani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 22:47:22 by ahinani           #+#    #+#             */
/*   Updated: 2022/05/23 22:47:26 by ahinani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ln_dump(char *s)
{
	char	*d;
	int		i;

	if (!*s)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	d = (char *)malloc(i + 2);
	i = -1;
	while (s[++i] && s[i] != '\n')
		d[i] = s[i];
	if (s[i] == '\n')
		d[i++] = '\n';
	d[i] = '\0';
	return (d);
}

static char	*update_rec(char *rec)
{
	char	*r;
	int		i;
	int		j;

	i = 0;
	while (rec[i] && rec[i] != '\n')
		i++;
	if (!*(rec + i))
	{
		free(rec);
		return (NULL);
	}
	r = (char *)malloc(ft_strlen_gnl(rec) - i + 1);
	if (!r)
		return (NULL);
	i++;
	j = 0;
	while (rec[i])
		r[j++] = rec[i++];
	r[j] = '\0';
	free(rec);
	return (r);
}

static int	buf_alloc(char **buf)
{
	*buf = (char *)malloc(BUFFER_SIZE + 1);
	if (!*buf)
		return (0);
	return (1);
}

char	*get_next_line(int fd)
{
	char		*buf;
	char		*rtn;
	static char	*rec;
	int			rdr;

	if (fd < 0 || BUFFER_SIZE <= 0 || !buf_alloc(&buf))
		return (NULL);
	rdr = 1;
	while (!nl_found(rec) && rdr)
	{
		rdr = read(fd, buf, BUFFER_SIZE);
		if (rdr == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[rdr] = '\0';
		rec = ft_strjoin_gnl(rec, buf);
	}
	free(buf);
	rtn = ln_dump(rec);
	rec = update_rec(rec);
	return (rtn);
}
