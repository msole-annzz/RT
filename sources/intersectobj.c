/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersectobj.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msole <msole@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/09 16:41:46 by msole             #+#    #+#             */
/*   Updated: 2020/08/09 18:36:28 by msole            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

/*
** t_quadreq t -  the result of solving a quadratic equation
*/

t_corsol	ft_intersectsfera(t_scene *scene, t_coord o, t_coord c, t_restr r)
{
	t_quadreq t;

	t = ft_sfera(o, c, *scene->object[scene->current_object]);
	return (ft_getcorrectsolution(t, r, scene->current_object));
}

t_corsol	ft_intersectcylinder(t_scene *scene, t_coord o, t_coord c, \
			t_restr r)
{
	t_quadreq t;

	t = ft_cylinder(o, c, *scene->object[scene->current_object]);
	return (ft_getcorrectsolution(t, r, scene->current_object));
}

t_corsol	ft_intersectcone(t_scene *scene, t_coord o, t_coord c, t_restr r)
{
	t_quadreq t;

	t = ft_cone(o, c, *scene->object[scene->current_object]);
	return (ft_getcorrectsolution(t, r, scene->current_object));
}

t_corsol	ft_intersectplane(t_scene *scene, t_coord o, t_coord c, t_restr r)
{
	t_quadreq t;

	t = ft_plane(o, c, *scene->object[scene->current_object]);
	return (ft_getcorrectsolution(t, r, scene->current_object));
}
