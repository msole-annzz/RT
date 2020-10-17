#include "rt.h"

static void	ft_swap_double(double *a, double *b)
{
	double tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

double	calc_angle(t_coord *pos, t_coord *axis, t_coord *intersect,
					double min)
{
	t_coord	check;
	double	angle;

	if (min == 0.0)
		check = ft_sub_vectors(*intersect, *pos);
	else
	{
		check = ft_multiply_vector_num(*axis, min);
		check = ft_add_vectors(*pos, check);
		check = ft_sub_vectors(*intersect, check);
	}
	ft_normalized(&check);
	angle = ft_dotproduct(check, *axis);
	return (angle);
}

// t_quadreq	ft_quadrsolution(double a, double b, double c)
// {
// 	double		d;
// 	double		sqrt_d;
// 	t_quadreq	eq;

// 	d = (b * b) - (4 * a * c);
// 	if (d < 0)
// 		eq.eqcount = NO_INTERSECT;
// 	if (d == 0)
// 	{
// 		eq.eqcount = 1;
// 		eq.d_1 = -b;
// 		eq.d_2 = -b;
// 	}
// 	if (d > 0)
// 	{
// 		eq.eqcount = 2;
// 		sqrt_d = sqrt(d);
// 		eq.d_1 = (-b - sqrt_d) / (2 * a); // поменял местами х1 первое пересечение
// 		eq.d_2 = (-b + sqrt_d) / (2 * a);
// 	}
// 	return (eq);
// }

// t_corsol	ft_get_correct_solution(t_quadreq t, t_restr limit, int k)
// {
// 	t_corsol	x;

// 	if ((t.eqcount > 0) && ((((t.x1 > limit.tmin) && (t.x1 < limit.tmax)) || \
// 	((t.x2 > limit.tmin) && (t.x2 < limit.tmax)))))
// 	{
// 		if ((t.x1 > limit.tmin) && (t.x1 < limit.tmax))
// 			x.sol = t.x1;
// 		else
// 			x.sol = t.x2;
// 		if ((t.x2 > limit.tmin) && (t.x2 < limit.tmax) && (t.x2 < t.x1))
// 			x.sol = t.x2;
// 		x.kobj = k;
// 		x.issol = 1;
// 	}
// 	else
// 		x.issol = 0;
// 	x.kobj = k;
// 	return (x);
// }

void	ft_solve_quadratic_equation(t_quadreq *sol)
{
	sol->d_1 = NO_INTERSECT;
	sol->d_2 = NO_INTERSECT;
	sol->discr = (sol->b * sol->b) - (4 * sol->a * sol->c);
	if (sol->discr < 0)
		sol->eqcount = NO_INTERSECT;
	if (sol->discr == 0)
	{
		sol->eqcount = 1;
		sol->d_1 = -sol->b;
		sol->d_2 = -sol->b;
	}
	if (sol->discr > 0)
	{
		sol->eqcount = 2;
		sol->sqrt_discr = sqrt(sol->discr);
		sol->d_1 = (-sol->b - sol->sqrt_discr) / (2 * sol->a); // поменял местами х1 первое пересечение
		sol->d_2 = (-sol->b + sol->sqrt_discr) / (2 * sol->a);
		if (sol->d_1 >= 0.001f && sol->d_2 >= 0.001f)
		{
			if (sol->d_1 > sol->d_2)
				ft_swap_double(&sol->d_1, &sol->d_2);
		}
		if (sol->d_1 < 0.001f && sol->d_2 > 0.001f)
			ft_swap_double(&sol->d_1, &sol->d_2);
	}
}

t_quadreq	calculate_a_b_c_discr_sphere(t_object *object, t_coord origin, t_coord direction)
{
	double	a;
	double	b;
	double	c;
	t_quadreq solution;
	t_coord	len;

	len = ft_sub_vectors(origin, object->center);
	solution.a = ft_dotproduct(direction, direction);
	solution.b = 2 * ft_dotproduct(len, direction);
	solution.c = ft_dotprod(len, len) - object->radius * object->radius;
	return (solution);
}

t_cross		ft_intersect_ray_sphera(t_object *sphere, t_coord origin, t_coord direction)
{
	t_quadreq	solution;
	t_cross		cross;
	t_coord		intersect;

	solution = calculate_a_b_c_discr_sphere(sphere, origin, direction);
	ft_solve_quadratic_equation(&solution);
	if (solution.discr < 0)
	{
		cross.len = NO_INTERSECT;
		// return (cross);
	}
	// if (ft_vector_modul(&sphere->axis) != 0.0)
	// {
	// 	intersect = ft_multiply_vector_num(direction, solution.d_1);
	// 	if (calc_angle(&sphere->center, &sphere->axis, &intersect, sphere->high) <= 0.001)
	// 		cross.len = solution.d_1;
	// 	intersect = ft_multiply_vector_num(direction, solution.d_2);
	// 	if (calc_angle(&sphere->center, &sphere->axis, &intersect, sphere->high) <= 0.001)
	// 		cross.len = solution.d_2;
	// }
	else
		cross.len = solution.d_1;
		// return (len_dir);
	return (cross);
}
