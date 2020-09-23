/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msole <msole@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 11:25:58 by msole             #+#    #+#             */
/*   Updated: 2019/09/24 13:45:08 by msole            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*str;
	size_t	i;
	size_t	n;
	size_t	k;

	n = 0;
	k = 0;
	if (!s)
		return (NULL);
	i = ft_strlen(s);
	while ((s[n] == ' ' || s[n] == '\n' || s[n] == '\t') && (s[n] != '\0'))
		n++;
	if ((n == i) || (*s == '\0'))
		return (str = ft_strnew(1));
	k = i - 1;
	while (((s[k] == ' ') || (s[k] == '\n') || (s[k] == '\t')) && (n < k))
		k--;
	i = n;
	n = 0;
	if (!(str = ft_strnew(k - i + 1)))
		return (NULL);
	while (i <= k)
		str[n++] = s[i++];
	str[n] = '\0';
	return (str);
}
