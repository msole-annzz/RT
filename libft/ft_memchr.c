/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msole <msole@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 13:05:11 by msole             #+#    #+#             */
/*   Updated: 2019/09/24 14:21:15 by msole            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char			cc;
	char			*ptr;
	size_t			i;

	i = 0;
	ptr = (char *)s;
	cc = (char)c;
	while (n--)
	{
		if (*ptr == cc)
			return (ptr);
		ptr++;
	}
	return (NULL);
}
