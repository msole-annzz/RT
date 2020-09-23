/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_overlong.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msole <msole@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 12:18:58 by msole             #+#    #+#             */
/*   Updated: 2019/09/20 15:29:58 by msole            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>

long long	ft_overlong(int m, long long num, const char s)
{
	if (m > 0)
	{
		if (num > ((LLONG_MAX) / 10))
			return (-2);
		num = num * 10;
		if (num > (LLONG_MAX - (s - '0')))
			return (-2);
		num = num + (s - '0');
	}
	else
	{
		if (num > ((LLONG_MAX) / 10))
			return (-1);
		num = num * 10;
		if (num > ((LLONG_MAX) - (s - '0')))
			return (-1);
		num = num + (s - '0');
	}
	return (num);
}
