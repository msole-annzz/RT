
#include "../includes/rt.h"

t_coord	ft_mult_num_vector(double k, t_coord v)
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

t_coord	ft_add_vector(t_coord v1, t_coord v2)
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

double	ft_modul_vector(t_coord v)
{
	return (sqrt(v.x * v.x + v.y * v.y + v.z * v.z));
}

t_coord 	ft_norm_vector(t_coord vector)
{
	double		modul_v;

	modul_v = ft_modul_vector(vector);
	vector.x /= modul_v;
	vector.y /= modul_v;
	vector.z /= modul_v;

	return (vector);
}

t_coord vector_mult(t_coord v1, t_coord v2)
{
	t_coord v;

	v.x = v1.y*v2.z - v2.y*v1.z;
	v.y = v2.x*v1.z - v1.x*v2.z;
	v.z = v1.x*v2.y - v2.x*v1.y;

	return(v);
}
