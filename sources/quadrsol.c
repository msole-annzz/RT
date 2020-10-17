
#include "../includes/rt.h"

t_quadreq	ft_quadrsolution(double a, double b, double c)
{
	double		d;
	double		sqrt_d;
	t_quadreq	eq;

	d = (b * b) - (4 * a * c);
	if (d < 0)
		eq.eqcount = NO_INTERSECT;
	if (d == 0)
	{
		eq.eqcount = 1;
		eq.d_1 = -b;
		eq.d_2 = -b;
	}
	if (d > 0)
	{
		eq.eqcount = 2;
		sqrt_d = sqrt(d);
		eq.d_1 = (-b - sqrt_d) / (2 * a); // поменял местами х1 первое пересечение
		eq.d_2 = (-b + sqrt_d) / (2 * a);
	}
	return (eq);
}

t_corsol	ft_get_correct_solution(t_quadreq t, t_restr r, int k)
{
	t_corsol	x;

	if ((t.eqcount > 0) && ((((t.d_1 > r.tmin) && (t.d_1 < r.tmax)) || \
	((t.d_2 > r.tmin) && (t.d_2 < r.tmax)))))
	{
		if ((t.d_1 > r.tmin) && (t.d_1 < r.tmax))
			x.sol = t.d_1;
		else
			x.sol = t.d_2;
		if ((t.d_2 > r.tmin) && (t.d_2 < r.tmax) && (t.d_2 < t.d_1))
			x.sol = t.d_2;
		x.kobj = k;
		x.issol = 1;
	}
	else
		x.issol = 0;
	x.kobj = k;
	return (x);
}
