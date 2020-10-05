
#include "../includes/rt.h"

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
	normal = ft_mult_num_vector(1 / ft_lengthv(normal), normal);
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
	normal = ft_mult_num_vector(1 / ft_lengthv(normal), normal);
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

t_quadreq	ft_paraboloid(t_coord origin, t_coord direction, t_object object)
{
	double	a;
	double	b;
	double	c;
	t_coord	oc;
	t_coord	normal;

	oc = ft_substrv(origin, object.center);
	normal = object.vectorperp;
	normal = ft_mult_num_vector(1 / ft_lengthv(normal), normal);

	a = ft_dotprod(direction, direction) - (ft_dotprod(direction, normal) * ft_dotprod(direction, normal));
	b = 2 * (ft_dotprod(oc, direction) - (ft_dotprod(direction, normal) * (ft_dotprod(oc, normal) + 2 * object.k_paraboloid)));
	c = ft_dotprod(oc, oc) - (ft_dotprod(oc, normal) * (ft_dotprod(oc, normal) + 4 * object.k_paraboloid));
	return (ft_quadrsolution(a, b, c));
}
/*
//нужно решение уравнения 4 степени
t_quadreq	ft_torus(t_coord origin, t_coord direction, t_object object)
{
	t_coord	oc;
	t_coord	normal;

	oc = ft_substrv(origin, object.center);
	normal = object.vectorperp;
	normal = ft_mult_num_vector(1 / ft_lengthv(normal), normal);
	object.tor.m = ft_dotprod(direction, direction);
	object.tor.n = ft_dotprod(direction, oc);
	object.tor.o = ft_dotprod(oc, oc);
	object.tor.p = ft_dotprod(direction, normal);
	object.tor.q = ft_dotprod(oc, normal);
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
