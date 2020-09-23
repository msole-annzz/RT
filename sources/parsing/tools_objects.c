/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_objects.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msole <msole@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/09 13:11:17 by msole             #+#    #+#             */
/*   Updated: 2020/08/12 15:48:07 by msole            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rtv1.h"

int		go_to_coma(char *str, int i)
{
	while (str[i] != ',')
		i++;
	i++;
	return (i);
}

t_color	parsing_color(char *str, int *index)
{
	t_color	res;
	int		i;

	i = 0;
	i = *index + 2;
	if (ft_atoi(&str[i]) >= 0 && ft_atoi(&str[i]) <= 255)
		res.r = ft_atoi(&str[i]);
	else
		file_contents_error();
	i = go_to_coma(str, i);
	if (ft_atoi(&str[i]) >= 0 && ft_atoi(&str[i]) <= 255)
		res.g = ft_atoi(&str[i]);
	else
		file_contents_error();
	i = go_to_coma(str, i);
	if (ft_atoi(&str[i]) >= 0 && ft_atoi(&str[i]) <= 255)
		res.b = ft_atoi(&str[i]);
	else
		file_contents_error();
	i = go_to_coma(str, i);
	*index = i;
	return (res);
}

int		parsing_object_type(char *str, int *index)
{
	int	rez;
	int	i;

	rez = 0;
	i = *index + 1;
	*index = *index + 1;
	if ((find_quotes(str, index, "\"sphere\"\0")))
		return (rez = 1);
	*index = i;
	if ((find_quotes(str, index, "\"plane\"\0")))
		return (rez = 2);
	*index = i;
	if ((find_quotes(str, index, "\"cylinder\"\0")))
		return (rez = 3);
	*index = i;
	if ((find_quotes(str, index, "\"cone\"\0")))
		return (rez = 4);
	return (rez);
}

double	double_parsing(char *str, int *index)
{
	double res;

	res = 0;
	*index = *index + 1;
	res = rt_atof(&str[*index]);
	while (((str[*index] >= '0') && (str[*index] <= '9')) || \
	(str[*index] == '.') || (str[*index] == '+') || (str[*index] == '-'))
		*index = *index + 1;
	if ((ft_strlen(str) - *index) < 5)
		return (res);
	while (str[*index] != ',')
		*index = *index + 1;
	*index = *index + 1;
	return (res);
}

int		int_parsing(char *str, int *index)
{
	int res;

	res = 0;
	*index = *index + 1;
	res = ft_atoi(&str[*index]);
	while (((str[*index] >= '0') && (str[*index] <= '9')) || \
	(str[*index] == '+') || (str[*index] == '-'))
		*index = *index + 1;
	if ((ft_strlen(str) - *index) < 5)
		return (res);
	while (str[*index] != ',')
		*index = *index + 1;
	*index = *index + 1;
	return (res);
}
