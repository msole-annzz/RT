/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_objects.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msole <msole@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/09 13:00:59 by msole             #+#    #+#             */
/*   Updated: 2020/08/12 15:48:01 by msole            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rtv1.h"

int		fill_objects_start(char *str, int *index, t_scene *rt, int counter)
{
	if ((find_quotes(str, index, "\"type\"\0")))
	{
		rt->object[rt->current_object]->type = parsing_object_type(str, index);
		if (str[*index] == ',')
			*index = *index + 1;
		if (str[*index] == '}')
			*index = *index + 2;
		counter++;
	}
	else if (find_quotes(str, index, "\"position\"\0"))
	{
		rt->object[rt->current_object]->center = \
		parsing_coordinates(str, index);
		counter++;
		*index = *index + 1;
	}
	return (counter);
}

int		fill_objects_middle(char *str, int *index, t_scene *rt, int counter)
{
	if (find_quotes(str, index, "\"color\"\0"))
	{
		rt->object[rt->current_object]->color = parsing_color(str, index);
		counter = counter + 1;
	}
	else if (find_quotes(str, index, "\"radius\"\0"))
	{
		rt->object[rt->current_object]->radius = double_parsing(str, index);
		counter = counter + 1;
	}
	else if (find_quotes(str, index, "\"reflection\"\0"))
	{
		rt->object[rt->current_object]->reflection = double_parsing(str, index);
		counter = counter + 1;
	}
	return (counter);
}

int		fill_objects_end(char *str, int *index, t_scene *rt, int counter)
{
	if (find_quotes(str, index, "\"angle\"\0"))
	{
		rt->object[rt->current_object]->angle = double_parsing(str, index);
		counter = counter + 1;
	}
	else if (find_quotes(str, index, "\"normal\"\0"))
	{
		rt->object[rt->current_object]->vectorperp = \
		parsing_coordinates(str, index);
		*index = *index + 1;
		counter = counter + 1;
	}
	else if (find_quotes(str, index, "\"specularity\"\0"))
	{
		rt->object[rt->current_object]->specular = double_parsing(str, index);
		counter = counter + 1;
	}
	return (counter);
}

int		fill_objects(char *str, int *index, t_scene *rt, int counter)
{
	int checker;

	checker = counter;
	if ((str[*index + 1] == 't') || (str[*index + 1] == 'p'))
	{
		counter = fill_objects_start(str, index, rt, counter);
	}
	else if ((str[*index + 1] == 'c') || (str[*index + 1] == 'r'))
	{
		counter = fill_objects_middle(str, index, rt, counter);
	}
	else if ((str[*index + 1] == 'a') || (str[*index + 1] == 'n') ||\
		(str[*index + 1] == 's'))
		counter = fill_objects_end(str, index, rt, counter);
	else
		file_contents_error();
	if (counter != checker + 1)
		file_contents_error();
	return (counter);
}

void	objects_parsing(char *str, int *index, t_scene *rt)
{
	int n;
	int counter;

	n = *index;
	counter = 0;
	malloc_objects(str, index, rt, n);
	n = 0;
	while (rt->object[n] != NULL)
	{
		rt->current_object = n;
		counter = fill_objects(str, index, rt, counter);
		if (counter == 8)
		{
			n++;
			counter = 0;
			*index = *index + 1;
		}
	}
}
