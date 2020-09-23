/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msole <msole@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 10:47:10 by msole             #+#    #+#             */
/*   Updated: 2019/09/19 17:28:23 by msole            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strstr(const char *haystack, const char *needle)
{
	int		i;
	int		k;
	char	*ptr;

	i = 0;
	ptr = (char *)haystack;
	if (needle[i] == '\0')
		return ((char *)haystack);
	while (ptr[i])
	{
		k = 0;
		while (ptr[i + k] == needle[k])
		{
			k++;
			if (!needle[k])
				return (ptr + i);
		}
		i++;
	}
	return (NULL);
}
