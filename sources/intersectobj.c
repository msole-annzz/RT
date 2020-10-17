
#include "../includes/rt.h"

/*
** t_quadreq t -  the result of solving a quadratic equation
*/

t_corsol	ft_intersect_sphere(t_scene *scene, t_coord o, t_coord c, t_restr r)
{
	t_quadreq t;

	t = ft_sfera(o, c, *scene->object[scene->current_object]);
	return (ft_get_correct_solution(t, r, scene->current_object));
}

t_corsol	ft_intersect_cylinder(t_scene *scene, t_coord o, t_coord c, \
			t_restr r)
{
	t_quadreq t;

	t = ft_cylinder(o, c, *scene->object[scene->current_object]);
	return (ft_get_correct_solution(t, r, scene->current_object));
}

t_corsol	ft_intersect_cone(t_scene *scene, t_coord o, t_coord c, t_restr r)
{
	t_quadreq t;

	t = ft_cone(o, c, *scene->object[scene->current_object]);
	return (ft_get_correct_solution(t, r, scene->current_object));
}

t_corsol	ft_intersect_paraboloid(t_scene *scene, t_coord o, t_coord c, t_restr r)
{
	t_quadreq t;

	t = ft_paraboloid(o, c, *scene->object[scene->current_object]);
	return (ft_get_correct_solution(t, r, scene->current_object));
}

t_corsol	ft_intersect_plane(t_scene *scene, t_coord o, t_coord c, t_restr r)
{
	t_quadreq t;

	t = ft_plane(o, c, *scene->object[scene->current_object]);
	return (ft_get_correct_solution(t, r, scene->current_object));
}
