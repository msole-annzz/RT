/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msole <msole@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 16:23:12 by msole             #+#    #+#             */
/*   Updated: 2019/09/19 17:23:35 by msole            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memalloc(size_t size)
{
	size_t	i;
	char	*tab;

	i = 0;
	tab = malloc(sizeof(char) * size);
	if (tab == NULL)
		return (tab);
	else
		while (i <= size)
			tab[i++] = 0;
	return (tab);
}
