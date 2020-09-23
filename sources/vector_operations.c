/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msole <msole@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/09 18:00:33 by msole             #+#    #+#             */
/*   Updated: 2020/08/09 18:00:43 by msole            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

t_coord	ft_multkv(double k, t_coord v)
{
	t_coord	m;

	m.x = k * v.x;
	m.y = k * v.y;
	m.z = k * v.z;
	return (m);
}

double	ft_dotprod(t_coord v1, t_coord v2)
{
	return (v1.x * v2.x + v1.y * v2.y + v1.z * v2.z);
}

double	ft_lengthv(t_coord v)
{
	return (sqrt(ft_dotprod(v, v)));
}

t_coord	ft_addv(t_coord v1, t_coord v2)
{
	t_coord	t;

	t.x = v1.x + v2.x;
	t.y = v1.y + v2.y;
	t.z = v1.z + v2.z;
	return (t);
}

t_coord	ft_substrv(t_coord v1, t_coord v2)
{
	t_coord	t;

	t.x = v1.x - v2.x;
	t.y = v1.y - v2.y;
	t.z = v1.z - v2.z;
	return (t);
}
