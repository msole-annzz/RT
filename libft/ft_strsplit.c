/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msole <msole@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 10:05:28 by msole             #+#    #+#             */
/*   Updated: 2019/09/24 15:01:37 by msole            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_lword(char const *s, char c, int i)
{
	int	l;
	int	index;

	index = i;
	l = 0;
	while ((s[index] != '\0') && (s[index] != c))
	{
		l++;
		index++;
	}
	return (l);
}

static void	*ft_free(char **tab, int n)
{
	while (n >= 0)
	{
		n--;
		free(tab[n]);
	}
	free(tab);
	return (NULL);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		n;
	int		l;
	int		i;

	i = 0;
	n = 0;
	if ((!s) ||
	(!(tab = (char **)malloc(sizeof(char *) * (ft_nw(s, c) + 1)))))
		return (NULL);
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			l = ft_lword(s, c, i);
			if (!(tab[n++] = ft_strsub(s, i, l)))
				return (ft_free(tab, n));
			i = i + l;
		}
		else
			i++;
	}
	tab[n] = NULL;
	return (tab);
}
