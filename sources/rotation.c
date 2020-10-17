
#include "../includes/rt.h"

t_coord	ft_rotatex(t_angle angle, t_coord v)
{
	t_coord m;

	m.x = v.x;
	m.y = (double)(v.y * cos(angle.x)) + (double)(v.z * sin(angle.x));
	m.z = (double)(-v.y * sin(angle.x)) + (double)(v.z * cos(angle.x));
	return (m);
}

t_coord	ft_rotatey(t_angle angle, t_coord v)
{
	t_coord m;

	m.x = (double)(v.x * cos(angle.y)) + (double)(v.z * sin(angle.y));
	m.y = v.y;
	m.z = (double)(-v.x * sin(angle.y)) + (double)(v.z * cos(angle.y));
	return (m);
}

t_coord	ft_rotatez(t_angle angle, t_coord v)
{
	t_coord m;

	m.x = (double)(v.x * cos(angle.z)) - (double)(v.y * sin(angle.z));
	m.y = (double)(v.x * sin(angle.z)) + (double)(v.y * cos(angle.z));
	m.z = (double)(v.z);
	return (m);
}

t_coord	ft_rotation_vector(t_angle *angle, t_coord *ray)
{
	t_coord		dot;
	t_matrix	value;
	double		x;

	value.cos_x = cos(angle->x);
	value.cos_y = cos(angle->y);
	value.cos_z = cos(angle->z);
	value.sin_x = sin(angle->x);
	value.sin_y = sin(angle->y);
	value.sin_z = sin(angle->z);
	dot.y = ray->y * value.cos_x + ray->z * value.sin_x;
	dot.z = -ray->y * value.sin_x + ray->z * value.cos_x;
	dot.x = ray->x * value.cos_y + dot.z * value.sin_y;
	dot.z = -ray->x * value.sin_y + dot.z * value.cos_y;
	x = dot.x;
	dot.x = x * value.cos_z - dot.y * value.sin_z;
	dot.y = x * value.sin_z + dot.y * value.cos_z;
	return (dot);
}

void	ft_rotate_vector(t_angle *angle, t_coord *ray)
{
	t_matrix	value;
	double		y;
	double		x;

	value.cos_x = cos(angle->x);
	value.cos_y = cos(angle->y);
	value.cos_z = cos(angle->z);
	value.sin_x = sin(angle->x);
	value.sin_y = sin(angle->y);
	value.sin_z = sin(angle->z);
	y = ray->y;
	ray->y = y * value.cos_x + ray->z * value.sin_x;
	ray->z = -y * value.sin_x + ray->z * value.cos_x;
	x = ray->x;
	ray->x = x * value.cos_y + ray->z * value.sin_y;
	ray->z = -x * value.sin_y + ray->z * value.cos_y;
	x = ray->x;
	ray->x = x * value.cos_z - ray->y * value.sin_z;
	ray->y = x * value.sin_z + ray->y * value.cos_z;
}