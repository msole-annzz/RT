
#include "../includes/rt.h"

t_quadreq	ft_sfera(t_coord origin, t_coord direction, t_object object)
{
	double	a;
	double	b;
	double	c;
	t_coord	len;

	len = ft_sub_vectors(origin, object.center);
	a = ft_dotproduct(direction, direction);
	b = 2 * ft_dotproduct(len, direction);
	c = ft_dotproduct(len, len) - object.radius * object.radius;
	return (ft_quadrsolution(a, b, c));
}

t_quadreq	ft_cylinder(t_coord origin, t_coord direction, t_object object)
{
	double	a;
	double	b;
	double	c;
	t_coord	oc;
	t_coord	normal;

	oc = ft_sub_vectors(origin, object.center);
	normal = object.axis;
	normal = ft_mult_num_vector(1 / ft_length_vector(normal), normal);
	a = ft_dotproduct(direction, direction) - ft_dotproduct(direction, normal) *\
		ft_dotproduct(direction, normal);
	b = 2 * (ft_dotproduct(oc, direction) - ft_dotproduct(direction, normal) *\
		ft_dotproduct(oc, normal));
	c = ft_dotproduct(oc, oc) - ft_dotproduct(oc, normal) * ft_dotproduct(oc, normal) -\
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

	oc = ft_sub_vectors(origin, object.center);
	normal = object.axis;
	normal = ft_mult_num_vector(1 / ft_length_vector(normal), normal);
	object.tang = tan(object.angle / 2);
	a = ft_dotproduct(direction, direction) - (1 + \
		object.tang * object.tang) *\
		ft_dotproduct(direction, normal) * ft_dotproduct(direction, normal);
	b = 2 * (ft_dotproduct(oc, direction) - (1 + object.tang * \
		object.tang) * \
		ft_dotproduct(direction, normal) * ft_dotproduct(oc, normal));
	c = ft_dotproduct(oc, oc) - (1 + object.tang * object.tang) *\
		ft_dotproduct(oc, normal) * ft_dotproduct(oc, normal);
	return (ft_quadrsolution(a, b, c));
}

t_quadreq	ft_paraboloid(t_coord origin, t_coord direction, t_object object)
{
	double	a;
	double	b;
	double	c;
	t_coord	oc;
	t_coord	normal;

	oc = ft_sub_vectors(origin, object.center);
	normal = object.axis;
	normal = ft_mult_num_vector(1 / ft_length_vector(normal), normal);

	a = ft_dotproduct(direction, direction) - (ft_dotproduct(direction, normal) * ft_dotproduct(direction, normal));
	b = 2 * (ft_dotproduct(oc, direction) - (ft_dotproduct(direction, normal) * (ft_dotproduct(oc, normal) + 2 * object.k_paraboloid)));
	c = ft_dotproduct(oc, oc) - (ft_dotproduct(oc, normal) * (ft_dotproduct(oc, normal) + 4 * object.k_paraboloid));
	return (ft_quadrsolution(a, b, c));
}
/*
//нужно решение уравнения 4 степени
t_quadreq	ft_torus(t_coord origin, t_coord direction, t_object object)
{
	t_coord	oc;
	t_coord	normal;

	oc = ft_sub_vectors(origin, object.center);
	normal = object.axis;
	normal = ft_mult_num_vector(1 / ft_length_vector(normal), normal);
	object.tor.m = ft_dotproduct(direction, direction);
	object.tor.n = ft_dotproduct(direction, oc);
	object.tor.o = ft_dotproduct(oc, oc);
	object.tor.p = ft_dotproduct(direction, normal);
	object.tor.q = ft_dotproduct(oc, normal);
	object.tor.sr2 = object.small_tor_radius * object.small_tor_radius;
	object.tor.br2 = object.big_tor_radius * object.big_tor_radius;
	object.tor.a = object.tor.m * object.tor.m;
	object.tor.b = 4 * object.tor.m * object.tor.n;
	object.tor.c = 4 * object.tor.m * object.tor.m + 2 * object.tor.m * object.tor.o - 2 * (object.tor.sr2 + object.tor.br2) * object.tor.m+ 4 * object.tor.br2 * object.tor.sr2 * object.tor.p * object.tor.p;
	object.tor.d = 4 * object.tor.n * object.tor.o - 4 * (object.tor.sr2 + object.tor.br2) * object.tor.n + 8 * object.tor.br2 * object.tor.p * object.tor.q;
	object.tor.e = object.tor.o * object.tor.o - 2 * (object.tor.sr2 + object.tor.br2) * object.tor.o + 4 *  object.tor.br2 * object.tor.q * object.tor.q + (object.tor.br2 - object.tor.sr2) * (object.tor.br2 - object.tor.sr2);



	return (ft_quadrsolution(a, b, c));//переписать функцию, решение ур 4 степени
}
*/
t_quadreq	ft_plane(t_coord origin, t_coord direction, t_object object)
{
	double		a;
	double		b;
	t_coord		oc;
	t_quadreq	t;

	t.eqcount = 0;
	oc = ft_sub_vectors(object.center, origin);
	a = ft_dotproduct(oc, object.axis);
	b = ft_dotproduct(direction, object.axis);
	if (b != 0)
	{
		t.eqcount = 1;
		t.d_1 = (a / b);
		t.d_2 = 0;
	}
	return (t);
}
