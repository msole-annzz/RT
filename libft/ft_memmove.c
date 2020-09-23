/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msole <msole@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 11:57:45 by msole             #+#    #+#             */
/*   Updated: 2019/09/24 13:10:40 by msole            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*s;
	unsigned char	*d;

	s = (unsigned char *)src;
	d = (unsigned char *)dst;
	if (dst == NULL && src == NULL)
		return (NULL);
	if (s > d)
	{
		while (len--)
			*d++ = *s++;
	}
	if (s < d)
	{
		s += len;
		d += len;
		while (len--)
		{
			d--;
			s--;
			*d = *s;
		}
	}
	return (void *)(dst);
}
