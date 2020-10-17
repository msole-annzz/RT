
#include "../includes/rt.h"

t_coord	ft_mult_num_vector(double num, t_coord vector)
{
	t_coord	result;

	result = (t_coord){num * vector.x, num * vector.y, num * vector.z};
	return (result);
}

double	ft_dotproduct(t_coord v1, t_coord v2)
{
	return (v1.x * v2.x + v1.y * v2.y + v1.z * v2.z);
}

double	ft_length_vector(t_coord v)
{
	return (sqrt(ft_dotproduct(v, v)));
}

t_coord	ft_add_vectors(t_coord vec1, t_coord vec2)
{
	t_coord	result;

	result = (t_coord){vec1.x + vec2.x, vec1.y + vec2.y, vec1.z + vec2.z};
	return (result);
}

t_coord	ft_sub_vectors(t_coord vec1, t_coord vec2)
{
	t_coord	result;

	result = (t_coord){vec1.x - vec2.x, vec1.y - vec2.y, vec1.z - vec2.z};
	return (result);
}

double	ft_modul_vector(t_coord vec)
{
	return (sqrt(vec.x * vec.x + vec.y * vec.y + vec.z * vec.z));
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

t_coord	vector_mult(t_coord *v1, t_coord *v2)
{
	t_coord result;

	result.x = v1->y * v2->z - v2->y * v1->z;
	result.y = v2->x * v1->z - v1->x * v2->z;
	result.z = v1->x * v2->y - v2->x * v1->y;

	return(result);
}

// t_coord	ft_add_vectorss(t_coord *vec1, t_coord *vec2)
// {
// 	t_coord	result;

// 	result = (t_coord){vec1->x + vec2->x, vec1->y + vec2->y, vec1->z + vec2->z};
// 	return (result);
// }

// t_coord	ft_sub_vectors(t_coord *vec1, t_coord *vec2)
// {
// 	t_coord	result;

// 	result = (t_coord){vec1->x - vec2->x, vec1->y - vec2->y, vec1->z - vec2->z};
// 	return (result);
// }

double		ft_vector_modul(t_coord *v)
{
	return (sqrt(v->x * v->x + v->y * v->y + v->z * v->z));
}

// double		ft_dotproduct(t_coord *v1, t_coord *v2)
// {
// 	return (v1->x * v2->x + v1->y * v2->y + v1->z * v2->z);
// }

/*
** Проекция vector V1 on vector V2  and return the len vector V1;
** return (sqrt(pow(v->x, 2) + pow(v->y, 2) + pow(v->z, 2)));
*/

double		ft_vector_projection_on_ray(t_coord *vec1, t_coord *vec2)
{
	return (ft_dotproduct(*vec1, *vec2) / ft_vector_modul(vec2));
}

void		ft_normalized(t_coord *vector)
{
	double		modul_v;

	modul_v = ft_vector_modul(vector);
	vector->x /= modul_v;
	vector->y /= modul_v;
	vector->z /= modul_v;
}
