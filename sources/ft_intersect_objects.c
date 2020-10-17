#include "rt.h"

t_cross	ft_raytrace_objects(t_object *object, t_coord start, t_coord ray)
{
	// double		len_dist;
	t_cross		intersect;

	intersect.len = NO_INTERSECT;
	if (object->type == e_sphere)
		intersect = ft_intersect_ray_sphera(object, start, ray);
	// if (object->type == e_plane) 
	// 	intersect = ft_intersect_plane(object, start, ray);
	// if (object->type == e_cylindr)
	// 	intersect = ft_intersect_cylinder(object, start, ray);
	// if (object->type == e_tube)
	// 	intersect = ft_intersect_tube(object, start, ray);
	// if (object->type == e_cone)
	// 	intersect = ft_intersect_cone(object, start, ray);
	// if (object->type == e_hemisphere)
	// 	intersect = ft_intersect_hemisphere(object, start, ray);
	// if (object->type == e_ring)
	// 	intersect = ft_intersect_ring(object, start, ray);
	return (intersect);
}

t_cross	ft_intersect_objects(t_scene *scene, t_coord start, t_coord ray)
{
	t_cross		intersect;
	t_cross		result;
	int			n;

	result.len = INT_MAX;
	n = 0;
	while (n < scene->n_objects)
	{
		intersect = ft_raytrace_objects(scene->object[n], start, ray);
		if (intersect.len != NO_INTERSECT && intersect.len < result.len &&
			intersect.len > 0.001)
		{
			result.len = intersect.len;
			result.id = n;
			result.check = intersect.check;
		}
		n += 1;
	}
	return (result);
}

