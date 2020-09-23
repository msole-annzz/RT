/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msole <msole@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 16:42:32 by msole             #+#    #+#             */
/*   Updated: 2019/09/26 15:58:21 by msole            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	size_t	i;
	char	*tab;

	i = 0;
	if (size + 1 != 0)
		tab = (char*)malloc(sizeof(char) * (size + 1));
	else
		return (NULL);
	if (tab == NULL)
		return (tab);
	else
		while (i <= size)
			tab[i++] = '\0';
	return (tab);
}
