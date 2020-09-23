/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_lights.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msole <msole@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/09 12:58:16 by msole             #+#    #+#             */
/*   Updated: 2020/08/09 14:15:57 by msole            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rtv1.h"

int		move(char *str, int *index, int counter)
{
	if (str[*index] == ',')
		*index = *index + 1;
	if (str[*index] == '{')
		*index = *index + 1;
	counter++;
	return (counter);
}

int		move_type(char *str, int *index, int counter)
{
	if (str[*index] == '}')
		*index = *index + 3;
	else if (str[*index] == ',')
		*index = *index + 1;
	counter++;
	return (counter);
}

int		find_option(char *str, int *index, int counter, t_scene *rt)
{
	if ((find_quotes(str, index, "\"type\"\0")))
	{
		rt->lights[rt->current_light]->type = parsing_type(str, index);
		counter = move_type(str, index, counter);
	}
	else if (find_quotes(str, index, "\"position\"\0"))
	{
		rt->lights[rt->current_light]->position = \
		parsing_coordinates(str, index);
		counter = move(str, index, counter);
	}
	else if (find_quotes(str, index, "\"direction\"\0"))
	{
		rt->lights[rt->current_light]->direction = \
		parsing_coordinates(str, index);
		counter = move(str, index, counter);
	}
	else if (find_quotes(str, index, "\"intensity\"\0"))
	{
		intensity_parsing(str, index, rt, rt->current_light);
		counter++;
	}
	else
		file_contents_error();
	return (counter);
}

void	lights_parsing(char *str, int *index, t_scene *rt)
{
	int n;
	int i;
	int counter;

	n = *index;
	i = *index;
	counter = 0;
	malloc_lightes(str, index, rt);
	*index = n + 2;
	n = 0;
	while (rt->lights[n] != NULL)
	{
		rt->current_light = n;
		counter = find_option(str, index, counter, rt);
		if (counter == 4)
		{
			n++;
			counter = 0;
		}
	}
}
