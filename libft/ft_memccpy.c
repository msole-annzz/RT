/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msole <msole@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 11:29:12 by msole             #+#    #+#             */
/*   Updated: 2019/09/25 09:53:32 by msole            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t		i;
	char		*d;
	const char	*s;

	if (!dst && !src)
		return (NULL);
	i = 0;
	d = (char*)dst;
	s = (char*)src;
	c = (char)c;
	while (i < n)
	{
		d[i] = s[i];
		if (s[i] == c)
			return (&dst[i + 1]);
		i++;
	}
	return (NULL);
}
