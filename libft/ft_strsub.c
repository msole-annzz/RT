/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msole <msole@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 17:45:21 by msole             #+#    #+#             */
/*   Updated: 2019/09/23 12:53:20 by msole            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*str;
	char	*substring;
	size_t	i;

	i = 0;
	if (!s || !(substring = ft_strnew(len)))
		return (NULL);
	str = (char *)s;
	while (i < len)
	{
		substring[i] = str[start];
		i++;
		start++;
	}
	return (substring);
}
