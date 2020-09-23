/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msole <msole@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 14:23:57 by msole             #+#    #+#             */
/*   Updated: 2019/09/25 09:55:38 by msole            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	int		i;
	size_t	m;
	int		diff;

	diff = 0;
	i = 0;
	m = n;
	if ((s1) && (s2))
	{
		if (n == 0)
			return (1);
		while ((s1[i] == s2[i]) &&
		(s1[i] != '\0') && (s2[i] != '\0') && (m-- > 0))
		{
			i++;
		}
		if (m == 0)
			i--;
		diff = s1[i] - s2[i];
		if (diff == 0)
			return (1);
		else
			return (0);
	}
	return (0);
}
