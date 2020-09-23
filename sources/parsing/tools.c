/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msole <msole@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/09 13:08:41 by msole             #+#    #+#             */
/*   Updated: 2020/08/09 13:36:24 by msole            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rtv1.h"

double		is_tail(const char *str, int i, int sing, double rez)
{
	int		rate;

	rate = 1;
	if (str[i] != '.')
		return (rez * (double)sing);
	i++;
	while ((str[i] >= 48) && (str[i] <= 57))
	{
		rate *= 10;
		rez = rez + (double)((str[i] - '0') / (double)rate);
		i++;
	}
	return (rez * (double)sing);
}

double		rt_atof(const char *str)
{
	int			i;
	int			sing;
	double		rez;

	i = 0;
	sing = 1;
	rez = 0;
	while (ft_isspace(str[i]))
		i++;
	if ((((str[i] == '+') ||
	(str[i] == '-')) && (str[i + 1] >= 48)) && (str[i + 1] <= 57))
	{
		if (str[i] == '-')
			sing = -1;
		i++;
	}
	while ((str[i] >= 48) && (str[i] <= 57))
	{
		rez = rez * 10 + str[i] - '0';
		i++;
	}
	rez = is_tail(str, i, sing, rez);
	return (rez);
}

int			find_quotes(char *str, int *index, char *mask)
{
	int		n;
	int		i;

	n = 0;
	i = *index;
	while (mask[n] != '\0')
	{
		if (str[i] != mask[n])
			return (0);
		i++;
		n++;
	}
	*index = i;
	return (1);
}

t_coord		parsing_coordinates(char *str, int *index)
{
	int		i;
	t_coord	rez;

	i = 0;
	i = *index + 2;
	rez.x = rt_atof(&str[i]);
	while (str[i] != ',')
		i++;
	i++;
	rez.y = rt_atof(&str[i]);
	while (str[i] != ',')
		i++;
	i++;
	rez.z = rt_atof(&str[i]);
	while (str[i] != ',')
		i++;
	*index = i;
	return (rez);
}

t_rotate	parsing_angles(char *str, int *index)
{
	int			i;
	t_rotate	rez;

	i = 0;
	i = *index + 2;
	rez.anglex = rt_atof(&str[i]);
	while (str[i] != ',')
		i++;
	i++;
	rez.angley = rt_atof(&str[i]);
	while (str[i] != ',')
		i++;
	i++;
	rez.anglez = rt_atof(&str[i]);
	while (str[i] != ',')
		i++;
	i++;
	*index = i;
	return (rez);
}
