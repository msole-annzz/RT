/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_lights.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msole <msole@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/09 14:16:32 by msole             #+#    #+#             */
/*   Updated: 2020/08/09 14:16:33 by msole            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rtv1.h"

int		parsing_type(char *str, int *index)
{
	int rez;
	int i;

	rez = 0;
	i = *index + 1;
	*index = *index + 1;
	if ((find_quotes(str, index, "\"sun\"\0")))
		return (rez = 3);
	*index = i;
	if ((find_quotes(str, index, "\"lamp\"\0")))
		return (rez = 2);
	*index = i;
	if ((find_quotes(str, index, "\"ambient\"\0")))
		return (rez = 1);
	return (rez);
}

void	intensity_parsing(char *str, int *index, t_scene *rt, int n)
{
	*index = *index + 1;
	rt->lights[n]->intens = rt_atof(&str[*index]);
	while ((str[*index] != '}') && (str[*index] != ','))
		*index = *index + 1;
	if (str[*index] == '}')
		*index = *index + 3;
	else if (str[*index] == ',')
		*index = *index + 1;
}
