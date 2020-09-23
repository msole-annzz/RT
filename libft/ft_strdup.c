/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msole <msole@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 10:54:09 by msole             #+#    #+#             */
/*   Updated: 2019/09/25 17:12:27 by msole            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*dstr;
	int		i;
	int		k;

	k = 0;
	i = 0;
	while (src[i] != '\0')
		i++;
	dstr = (char*)malloc(i + 1);
	if (dstr != NULL)
	{
		while (k <= i)
		{
			dstr[k] = src[k];
			k++;
		}
		dstr[k] = '\0';
	}
	return (dstr);
}
