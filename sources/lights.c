
#include "../includes/rt.h"

/*
** <ft_findnearobj> - we look over all objects and check if the ray intersects
** any of them from a point to the light source
*/

double ft_ligth(t_scene *scene, t_coord normal, t_coord point,t_coord view, int s)
{
double intense;
int i;
double m;
intense = 0;
i = 0;
t_coord vl;
t_coord R;
double rv;
double t_max;
t_corsol x;
    t_coord med;
t_restr         r;

r.tmin = 0.0001;
while (i<scene->n_lights)//тут вместо n_lights  - 3 - количество источников света
{

if (scene->lights[i]->type == 1)
{
intense = intense + scene->lights[i]->intens;
}

else

{
	if (scene->lights[i]->type == 2)
	{
		vl=ft_substrv(scene->lights[i]->position, point);
		r.tmax=1;
	}
	else
		{
		vl = scene->lights[i]->direction;
		r.tmax = 100000;
		}

//check shadow  проходим по всем обьектам и проверяем пересекается ли с ними луч от точки до источника света
	x = ft_findnearobj(scene, point, vl, r);  //проверяем пересекается ли луч point, vl с каким-либо обьектом сферы

	if (x.sol == 0)
	{

        med = ft_mult_num_vector(1/ft_lengthv(view),view);
        if (ft_dotprod(med, normal)>=0)
        {

		m = ft_dotprod(vl, normal);
		if (m > 0 )
		intense += scene->lights[i]->intens * m / (ft_lengthv(normal) * ft_lengthv(vl));

		if (s!= -1)
		{
			R= ft_substrv(ft_mult_num_vector(2 * m,normal),vl);
			rv = ft_dotprod(R, view);
			if (rv > 0)
			{
				intense += scene->lights[i]->intens * (pow (rv/(ft_lengthv(R)*ft_lengthv(view)) , s));
			}
		}
        }
	}
}
i++;
}

return(intense);
}


/*
double	ft_light(t_scene *scene,t_coord normal, t_coord crossp, t_coord view, int s)
{
	double		intense;
	int			i;
	t_restr		r;

	intense = 0;
	i = 0;
	r.tmin = 0.0001;
	while (i < scene->n_lights)
	{
		if (scene->lights[i]->type == 1)
			intense = intense + scene->lights[i]->intens;
		else
			intense += ft_lights23(scene, r, scene->lights[i], s);
		i++;
	}
	return (intense);
}

double	ft_lights23(t_scene *scene, t_restr r, t_light *light, int s)
{
	t_coord		vl;
	t_corsol	x;
	t_coord		med;
	double		intense;

	intense = 0;
	if (light->type == 2)
	{
		vl = ft_substrv(light->position, scene->cur_prop.p);
		r.tmax = 1;
	}
	if (light->type == 3)
	{
		vl = light->direction;
		r.tmax = 100000;
	}
	x = ft_findnearobj(scene, scene->cur_prop.p, vl, r);
	med = ft_mult_num_vector(1 / ft_lengthv(scene->cur_prop.view), \
	scene->cur_prop.view);
	if ((x.sol == 0) && (ft_dotprod(med, scene->cur_prop.normal) >= 0))
		intense += ft_shine(scene, s, vl, light);
	return (intense);
}

double	ft_shine(t_scene *scene, int s, t_coord vl, t_light *light)
{
	double	m;
	double	intense;
	t_coord	r;
	double	rv;

	intense = 0;
	m = ft_dotprod(vl, scene->cur_prop.normal);
	if (m > 0)
		intense += light->intens * m / \
		(ft_lengthv(scene->cur_prop.normal) * ft_lengthv(vl));
	if (s != -1)
	{
		r = ft_substrv(ft_mult_num_vector(2 * m, scene->cur_prop.normal), vl);
		rv = ft_dotprod(r, scene->cur_prop.view);
		if (rv > 0)
		{
			intense += light->intens * (pow(rv / \
			(ft_lengthv(r) * ft_lengthv(scene->cur_prop.view)), s));
		}
	}
	return (intense);
}
*/
//int add_light_color(t_scene *scene/*, t_coord o, t_coord c*/)
t_color add_light_color(t_scene *scene, t_coord o, t_coord c)


{

	t_color color;

	t_coord p;
	t_coord m;
	int n;
	//double t;
double R = 0.5;
	double d;
	//t_coord light;


	n = scene->n_lights - 1;

	//light.x = scene->lights[n]->position.x;
	//light.y = scene->lights[n]->position.y;
	//light.z = scene->d;


	p = ft_substrv(c, o);
	p = ft_norm_vector(p);

	 color.r = 0;
	 color.g = 0;
	 color.b = 0;
	//color = (t_color){0, 0, 0};
	//printf("ok\n");
	while (n < scene->n_lights)
	{
		m = ft_substrv(scene->lights[n]->position, o);
		//m = ft_substrv(light, o);
		d =  ft_modul_vector(vector_mult(m, p))/ft_modul_vector(p);
		//d *= fabs(scene->camera.place.z - scene->d);
		//d *= fabs(scene->camera.place.z - scene->lights[n]->position.z);
		//if (d < R) //R = радиус для сферы по формулам из чата;
		{
			color.r += scene->lights[n]->color.r / (1 + pow(d, 6));// добавть в парсин цвет света
			color.b += scene->lights[n]->color.b / (1 + pow(d, 6));
			color.g += scene->lights[n]->color.g / (1 + pow(d, 6));
		}
		n++;
	}
	return(color);
}
