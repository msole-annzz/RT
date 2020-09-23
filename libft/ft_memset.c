/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msole <msole@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 17:24:40 by msole             #+#    #+#             */
/*   Updated: 2019/09/19 17:24:47 by msole            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memset(void *b, int c, size_t len)
{
	size_t	n;
	char	*tab;

	n = 0;
	tab = b;
	while (n < len)
	{
		tab[n] = (unsigned int)c;
		n++;
	}
	return (b);
}
