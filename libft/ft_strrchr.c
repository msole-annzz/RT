/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msole <msole@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 15:18:13 by msole             #+#    #+#             */
/*   Updated: 2019/09/24 14:15:30 by msole            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	index;

	index = 0;
	if ((char)c == '\0')
	{
		while (s[index] != '\0')
			index++;
		return ((char *)&s[index]);
	}
	else
	{
		while (s[index] != '\0')
			index++;
		while ((s[index] != (char)c) && (index >= 0))
			index--;
		if (s[index] == (char)c)
			return ((char *)&s[index]);
		else
			return (NULL);
	}
}
