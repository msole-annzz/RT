
#include "../includes/rt.h"

/*
** <ft_findnearobj> - we look over all objects and check if the ray intersects
** any of them from a point to the light source
*/

double ft_ligth(t_scene *scene, t_distcolor cur_prop, int s)
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
		vl=ft_substrv(scene->lights[i]->position, cur_prop.p);
		r.tmax=1;
	}
	else
		{
		vl = scene->lights[i]->direction;
		r.tmax = 100000;
		}

//check shadow  проходим по всем обьектам и проверяем пересекается ли с ними луч от точки до источника света
	x = ft_findnearobj(scene, cur_prop.p, vl, r);  //проверяем пересекается ли луч point, vl с каким-либо обьектом сферы

	if (x.sol == 0)
	{
        
        med = ft_mult_num_vector(1/ft_lengthv(cur_prop.view),cur_prop.view);
        if (ft_dotprod(med, cur_prop.normal)>=0)
        {
        
		m = ft_dotprod(vl, cur_prop.normal);
		if (m > 0 )
		intense += scene->lights[i]->intens * m / (ft_lengthv(cur_prop.normal) * ft_lengthv(vl));

		if (s!= -1)
		{
			R= ft_substrv(ft_mult_num_vector(2 * m,cur_prop.normal),vl);
			rv = ft_dotprod(R, cur_prop.view);
			if (rv > 0)
			{
				intense += scene->lights[i]->intens * (pow (rv/(ft_lengthv(R)*ft_lengthv(cur_prop.view)) , s));
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

	t_coord d; //p
	t_coord m;
	int n;
	double t;
double R = 2;

	n = scene->n_lights - 1;

	d = ft_substrv(o, c);

	 color.r = 0;
	 color.g = 0;
	 color.b = 0;
	//color = (t_color){0, 0, 0};
	//printf("ok\n");
	while (n < scene->n_lights)
	{
		m = ft_substrv(o, scene->lights[n]->position);
		t = 1/ft_modul_vector(d) * ft_modul_vector(vector_mult(m, d));
		if (t < R) //R = радиус для сферы по формулам из чата;
		{
			color.r += scene->lights[n]->color.r / (1 + t*t);// добавть в парсин цвет света
			color.b += scene->lights[n]->color.b / (1 + t*t);
			color.g += scene->lights[n]->color.g / (1 + t*t);
		}
		n++;
	}
	return(color);
}
