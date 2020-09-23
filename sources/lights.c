/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lights.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msole <msole@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/09 17:03:33 by msole             #+#    #+#             */
/*   Updated: 2020/08/09 17:47:31 by msole            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

/*
** <ft_findnearobj> - we look over all objects and check if the ray intersects
** any of them from a point to the light source
*/

double	ft_light(t_scene *scene, int s)
{
	double		intense;
	int			i;
	t_restr		r;

	intense = 0;
	i = 0;
	r.tmin = 0.0001;
	while (i < scene->n_lights)
	{
		if (scene->lights[i]->type == 1)
			intense = intense + scene->lights[i]->intens;
		else
			intense += ft_lights23(scene, r, scene->lights[i], s);
		i++;
	}
	return (intense);
}

double	ft_lights23(t_scene *scene, t_restr r, t_light *light, int s)
{
	t_coord		vl;
	t_corsol	x;
	t_coord		med;
	double		intense;

	intense = 0;
	if (light->type == 2)
	{
		vl = ft_substrv(light->position, scene->cur_prop.p);
		r.tmax = 1;
	}
	if (light->type == 3)
	{
		vl = light->direction;
		r.tmax = 100000;
	}
	x = ft_findnearobj(scene, scene->cur_prop.p, vl, r);
	med = ft_multkv(1 / ft_lengthv(scene->cur_prop.view), \
	scene->cur_prop.view);
	if ((x.sol == 0) && (ft_dotprod(med, scene->cur_prop.normal) >= 0))
		intense += ft_shine(scene, s, vl, light);
	return (intense);
}

double	ft_shine(t_scene *scene, int s, t_coord vl, t_light *light)
{
	double	m;
	double	intense;
	t_coord	r;
	double	rv;

	intense = 0;
	m = ft_dotprod(vl, scene->cur_prop.normal);
	if (m > 0)
		intense += light->intens * m / \
		(ft_lengthv(scene->cur_prop.normal) * ft_lengthv(vl));
	if (s != -1)
	{
		r = ft_substrv(ft_multkv(2 * m, scene->cur_prop.normal), vl);
		rv = ft_dotprod(r, scene->cur_prop.view);
		if (rv > 0)
		{
			intense += light->intens * (pow(rv / \
			(ft_lengthv(r) * ft_lengthv(scene->cur_prop.view)), s));
		}
	}
	return (intense);
}
