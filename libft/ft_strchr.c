/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msole <msole@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 14:53:47 by msole             #+#    #+#             */
/*   Updated: 2019/09/19 17:28:44 by msole            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
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
		while ((s[index] != (char)c) && (s[index] != '\0'))
			index++;
		if (s[index] == (char)c)
			return ((char *)&s[index]);
		else
			return (NULL);
	}
}
