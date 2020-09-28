
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
