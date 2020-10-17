#include "../includes/rt.h"


// void	ft_intersect(t_scene *scene, t_coord ray)
// {
// 	t_corsol	intersect;
// 	double		deep;
// 	t_restr		limit;
// 	t_color color_light;
// 	// t_color	color_tmp[3];

// 	limit.tmin = 1;
// 	limit.tmax = 100000;
// 	intersect = ft_findnearobj(scene, scene->camera.place, ray, limit);
// 	if (intersect.issol == INTERSECT)
// 	{
// 		scene->cur_prop.p = ft_add_vectors(scene->camera.place, ft_mult_num_vector(intersect.sol, scene->cur_point));
// 		ft_getnorms_and_view(scene, intersect.kobj);
// 		deep = 0;
// 		if (scene->object[intersect.kobj]->specular)
// 			deep = ft_light(scene, scene->object[intersect.kobj]->specular);
// 		ft_changecolor(scene, scene->object[intersect.kobj]->color, deep);
// 		// color_tmp[0] = ft_change_color_new(&scene->object[intersect.kobj]->color, deep);
// 	}
// }

void	ft_getnorm_cylinder(t_scene *scene, int i)
{
	double m;
	t_coord v;

	v = ft_mult_num_vector(1 / ft_length_vector(scene->object[i]->axis), scene->object[i]->axis);
	m = ft_dotproduct(ft_sub_vectors(scene->cur_prop.p, scene->object[i]->center), v);
	scene->cur_prop.normal = ft_sub_vectors(ft_sub_vectors(scene->cur_prop.p, scene->object[i]->center), ft_mult_num_vector(m, v));
	scene->cur_prop.normal = ft_norm_vector(scene->cur_prop.normal);

}

void	ft_getnorm_cone(t_scene *scene, int i)
{
	double	m;
	double	k;
	t_coord	a;
	t_coord v;

	v = ft_mult_num_vector(1 / ft_length_vector(scene->object[i]->axis), scene->object[i]->axis);
	m = ft_dotproduct(ft_sub_vectors(scene->cur_prop.p, scene->object[i]->center), v);
	a = ft_add_vectors(scene->object[i]->center, ft_mult_num_vector(m, v));
	k = ft_length_vector(ft_sub_vectors(scene->cur_prop.p, a)) / m;
	scene->cur_prop.normal = ft_sub_vectors(ft_sub_vectors(scene->cur_prop.p, scene->object[i]->center), ft_mult_num_vector((1 + k * k), ft_mult_num_vector(m, v)));
	scene->cur_prop.normal = ft_norm_vector(scene->cur_prop.normal);
}


void	ft_getnorm_paraboloid(t_scene *scene, int i)
{
	double	m;
	t_coord v;

	v = ft_mult_num_vector(1 / ft_length_vector(scene->object[i]->axis), scene->object[i]->axis);
	m = ft_dotproduct(ft_sub_vectors(scene->cur_prop.p, scene->object[i]->center), v);
	scene->cur_prop.normal = ft_sub_vectors(ft_sub_vectors(scene->cur_prop.p, scene->object[i]->center), ft_mult_num_vector((m + scene->object[i]->k_paraboloid), v));
	scene->cur_prop.normal = ft_norm_vector(scene->cur_prop.normal);
}

void	ft_getnorm6(t_scene *scene, int i)// для тора
{
	double	k;
	t_coord	a;
	double	m;
	double	koef;
	k = ft_dotproduct(ft_sub_vectors(scene->cur_prop.p, scene->object[i]->center), \
	ft_mult_num_vector(1 / ft_length_vector(scene->object[i]->axis), \
	scene->object[i]->axis));
	a = ft_sub_vectors(scene->cur_prop.p, ft_mult_num_vector(k, ft_mult_num_vector(1 / ft_length_vector(scene->object[i]->axis), \
	scene->object[i]->axis)));
	m = (scene->object[i]->tor.sr2 - k * k ) * (scene->object[i]->tor.sr2 - k * k );
	koef = m / (scene->object[i]->big_tor_radius + m);
	scene->cur_prop.normal = ft_sub_vectors(scene->cur_prop.p, ft_sub_vectors(a, ft_mult_num_vector(koef, ft_sub_vectors(scene->object[i]->center, a))));

}

void	ft_getnorms_and_view(t_scene *scene, int i)
{
	if (scene->object[i]->type == e_sphere)
		scene->cur_prop.normal = ft_sub_vectors(scene->cur_prop.p, \
		scene->object[i]->center);
	if (scene->object[i]->type == e_plane)
		scene->cur_prop.normal = scene->object[i]->axis;
	if (scene->object[i]->type == e_cylindr)
		ft_getnorm_cylinder(scene, i);
	if (scene->object[i]->type == e_cone)
		ft_getnorm_cone(scene, i);
	if (scene->object[i]->type == e_paraboloid)
		ft_getnorm_paraboloid(scene, i);
	/*if (scene->object[i]->type == 6)
		ft_getnorm6(scene, i);

*/
	scene->cur_prop.normal = ft_mult_num_vector(1 / ft_length_vector(scene->cur_prop.normal), \
	scene->cur_prop.normal);
	scene->cur_prop.view = ft_mult_num_vector(-1, scene->cur_point);
}
