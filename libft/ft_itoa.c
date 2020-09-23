/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msole <msole@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 12:28:38 by msole             #+#    #+#             */
/*   Updated: 2019/09/24 12:33:33 by msole            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	size_t			counter;
	char			*str;
	unsigned int	nn;

	counter = ft_nbrlen(n);
	if (!(str = ft_strnew(counter)))
		return (NULL);
	if (n < 0)
	{
		str[0] = '-';
		nn = -n;
	}
	else
		nn = n;
	if ((n == 0) && (n == -0))
		str[0] = '0';
	while (nn)
	{
		str[--counter] = (nn % 10) + '0';
		nn = nn / 10;
	}
	return (str);
}
