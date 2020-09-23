/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msole <msole@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 10:36:19 by msole             #+#    #+#             */
/*   Updated: 2019/12/09 12:26:36 by msole            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#define BUFF_SIZE 100

char			*ft_new_line(char **tail)
{
	int			n;
	char		*tmp;

	n = ft_strlen(*tail);
	tmp = ft_strnew(n + BUFF_SIZE + 1);
	ft_memcpy(tmp, *tail, n);
	free(*tail);
	*tail = tmp;
	return ((tmp + n));
}

char			*ft_find_tail(char *tail, int ret)
{
	char		*tmp;

	if ((tmp = ft_strchr(tail, '\n')))
	{
		*tmp = '\0';
		return (tmp + 1);
	}
	else
	{
		if (ret < BUFF_SIZE)
		{
			tmp = ft_strchr(tail, '\0');
			return (tmp);
		}
		return (tail);
	}
}

int				get_next_line(const int fd, char **line)
{
	static char	*tail[4096];
	char		buf[BUFF_SIZE + 1];
	int			ret;

	if (fd < 0 || BUFF_SIZE <= 0 || !line
		|| fd > 4095 || (read(fd, buf, 0) < 0))
		return (-1);
	if (tail[fd] == NULL)
		tail[fd] = ft_strnew(0);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0 || *tail[fd] != '\0')
	{
		buf[ret] = '\0';
		ft_memcpy(ft_new_line(&tail[fd]), buf, BUFF_SIZE);
		*line = tail[fd];
		tail[fd] = ft_find_tail(tail[fd], ret);
		if (*line != tail[fd])
		{
			tail[fd] = ft_strdup(tail[fd]);
			return (1);
		}
	}
	return (0);
}
