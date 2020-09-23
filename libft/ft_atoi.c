/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msole <msole@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 09:54:26 by msole             #+#    #+#             */
/*   Updated: 2019/09/20 14:22:49 by msole            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <limits.h>

int		ft_atoi(const char *str)
{
	int			i;
	int			m;
	long long	num;

	i = 0;
	m = 1;
	num = 0;
	while (ft_isspace(str[i]))
		i++;
	if ((((str[i] == '+') ||
	(str[i] == '-')) && (str[i + 1] >= 48)) && (str[i + 1] <= 57))
	{
		if (str[i] == '-')
			m = -1;
		i++;
	}
	while ((str[i] >= 48) && (str[i] <= 57))
	{
		num = ft_overlong(m, num, str[i]);
		if (num < 0)
			return (num + 1);
		i++;
	}
	num = num * m;
	return ((int)num);
}
