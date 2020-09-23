/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quadrsol.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msole <msole@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/09 17:26:41 by msole             #+#    #+#             */
/*   Updated: 2020/08/09 17:49:57 by msole            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

t_quadreq	ft_quadrsolution(double a, double b, double c)
{
	double		d;
	t_quadreq	eq;

	d = (b * b) - (4 * a * c);
	if (d < 0)
		eq.eqcount = 0;
	if (d == 0)
	{
		eq.eqcount = 1;
		eq.x1 = -b;
		eq.x2 = -b;
	}
	if (d > 0)
	{
		eq.eqcount = 2;
		eq.x1 = (-b + (double)sqrt(d)) / (2 * a);
		eq.x2 = (-b - (double)sqrt(d)) / (2 * a);
	}
	return (eq);
}

t_corsol	ft_getcorrectsolution(t_quadreq t, t_restr r, int k)
{
	t_corsol	x;

	if ((t.eqcount > 0) && ((((t.x1 > r.tmin) && (t.x1 < r.tmax)) || \
	((t.x2 > r.tmin) && (t.x2 < r.tmax)))))
	{
		if ((t.x1 > r.tmin) && (t.x1 < r.tmax))
			x.sol = t.x1;
		else
			x.sol = t.x2;
		if ((t.x2 > r.tmin) && (t.x2 < r.tmax) && (t.x2 < t.x1))
			x.sol = t.x2;
		x.kobj = k;
		x.issol = 1;
	}
	else
		x.issol = 0;
	x.kobj = k;
	return (x);
}
