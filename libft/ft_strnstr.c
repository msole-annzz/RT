/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msole <msole@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 10:47:10 by msole             #+#    #+#             */
/*   Updated: 2019/09/26 14:23:45 by msole            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int		i;
	int		j;
	int		n;

	if (needle[0] == '\0' && len == 0)
		return ((char *)haystack);
	if (ft_strlen(needle) == 0)
		return ((char *)haystack);
	i = 0;
	j = 0;
	while (haystack[i] != '\0')
	{
		n = (int)len;
		while (haystack[i + j] == needle[j] && needle[j] != '\0' && n-- > 0)
			j++;
		if (needle[j] == '\0')
			return ((char *)&haystack[i]);
		i++;
		j = 0;
		len--;
	}
	return (0);
}
