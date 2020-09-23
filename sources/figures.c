/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   figures.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msole <msole@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/09 15:26:20 by msole             #+#    #+#             */
/*   Updated: 2020/08/09 19:01:03 by msole            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

t_quadreq	ft_sfera(t_coord origin, t_coord direction, t_object object)
{
	double	a;
	double	b;
	double	c;
	t_coord	oc;

	oc = ft_substrv(origin, object.center);
	a = ft_dotprod(direction, direction);
	b = 2 * ft_dotprod(oc, direction);
	c = ft_dotprod(oc, oc) - object.radius * object.radius;
	return (ft_quadrsolution(a, b, c));
}

t_quadreq	ft_cylinder(t_coord origin, t_coord direction, t_object object)
{
	double	a;
	double	b;
	double	c;
	t_coord	oc;
	t_coord	normal;

	oc = ft_substrv(origin, object.center);
	normal = object.vectorperp;
	normal = ft_multkv(1 / ft_lengthv(normal), normal);
	a = ft_dotprod(direction, direction) - ft_dotprod(direction, normal) *\
		ft_dotprod(direction, normal);
	b = 2 * (ft_dotprod(oc, direction) - ft_dotprod(direction, normal) *\
		ft_dotprod(oc, normal));
	c = ft_dotprod(oc, oc) - ft_dotprod(oc, normal) * ft_dotprod(oc, normal) -\
		object.radius * object.radius;
	return (ft_quadrsolution(a, b, c));
}

t_quadreq	ft_cone(t_coord origin, t_coord direction, t_object object)
{
	double	a;
	double	b;
	double	c;
	t_coord	oc;
	t_coord	normal;

	oc = ft_substrv(origin, object.center);
	normal = object.vectorperp;
	normal = ft_multkv(1 / ft_lengthv(normal), normal);
	object.tang = tan(object.angle / 2);
	a = ft_dotprod(direction, direction) - (1 + \
		object.tang * object.tang) *\
		ft_dotprod(direction, normal) * ft_dotprod(direction, normal);
	b = 2 * (ft_dotprod(oc, direction) - (1 + object.tang * \
		object.tang) * \
		ft_dotprod(direction, normal) * ft_dotprod(oc, normal));
	c = ft_dotprod(oc, oc) - (1 + object.tang * object.tang) *\
		ft_dotprod(oc, normal) * ft_dotprod(oc, normal);
	return (ft_quadrsolution(a, b, c));
}

t_quadreq	ft_plane(t_coord origin, t_coord direction, t_object object)
{
	double		a;
	double		b;
	t_coord		oc;
	t_quadreq	t;

	t.eqcount = 0;
	oc = ft_substrv(object.center, origin);
	a = ft_dotprod(oc, object.vectorperp);
	b = ft_dotprod(direction, object.vectorperp);
	if (b != 0)
	{
		t.eqcount = 1;
		t.x1 = (a / b);
		t.x2 = 0;
	}
	return (t);
}
