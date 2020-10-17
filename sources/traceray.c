#include "../includes/rt.h"

void	*ft_traceray(void *thread_data)
{
	int		i;
	int		j;
	t_scene	*scene;
	t_coord cur_point;
	t_distcolor cur_prop;

	scene = (t_scene *)(thread_data);
	i = scene->thrminwidth;
	j = 0;
	while (j < WIN_HEIGHT)
	{
		while (i < scene->thrmaxwidth)
		{
			cur_point=ft_conv2to3(scene, i - WIN_WIDTH / 2, j - WIN_HEIGHT / 2);
			cur_prop=ft_initcolor(scene);
			cur_prop=ft_intersect(scene, scene->camera.place, cur_point, cur_prop);
			ft_put_pixel(scene, i, j, cur_prop);
			i++;
		}
		i = scene->thrminwidth;
		j++;
	}
	return (thread_data);
}

t_coord ft_getnormals(t_object object, t_coord crossp)
{
t_coord normal;
double m;
double k;
t_coord A;


if (object.type == e_sphere)
{
normal = ft_substrv(crossp, object.center);
}
if (object.type == e_plane)
normal = object.vectorperp;
if (object.type == e_cylindr)
normal=ft_getnorm_cylinder(object, crossp);
if (object.type == e_cone)
normal=ft_getnorm_cone(object, crossp);
if (object.type == e_paraboloid)
normal=ft_getnorm_paraboloid(object, crossp);
return (normal);
}

t_distcolor	ft_intersect(t_scene *scene, t_coord start_point, t_coord end_point, t_distcolor cur_prop)
{
	t_corsol	t;
	double		deep;
	t_restr		r;
	t_color color_light;
	t_coord normal;
	t_coord p;
	t_coord view;
	t_color reflect_color;
	//int n;
	//t_distcolor cur_prop;

	r.tmin = 1;
	r.tmax = 100000;
	t = ft_findnearobj(scene, start_point, end_point, r);
	if (t.issol == 1)
	{
		p = ft_add_vector(start_point, ft_mult_num_vector(t.sol, \
		end_point));//точка пересечения с фигурой луча из камеры
		normal = ft_getnormals(*scene->object[t.kobj], p);
		view = ft_mult_num_vector(-1,end_point);
		deep = 0;
		if (scene->object[t.kobj]->specular)
			deep = ft_ligth(scene,normal, p,view,  scene->object[t.kobj]->specular);
		if (scene->object[t.kobj]->reflection) //  если у фигура зеркальная, но снова запускаем intersect чтобы найти отражающися цвет
			{
					// тут функция отраженного луча
				reflect_color = ft_intersect(scene, p, t_coord end_point, cur_prop);// перезаписываем cur/ prop или нужна его копия. Что значит cur prop
			}
		cur_prop = ft_changecolor(scene, scene->object[t.kobj]->color, deep);
	}
	else if (t.issol == 0)
	{

		 color_light = add_light_color(scene, start_point, end_point);
		printf("%d\n", color_light.r);
		//n = add_light_color(scene/*, scene->camera.place, scene->cur_point*/);

		   cur_prop.color = color_light;
	}
return(cur_prop);
}

t_coord	ft_getnorm_cylinder(t_object object, t_coord crossp)
{
	double m;
	t_coord normal;

m = ft_dotprod(ft_substrv(crossp, object.center), ft_mult_num_vector(1/ft_lengthv(object.vectorperp),object.vectorperp));// эта хорошая
normal = ft_substrv(ft_substrv(crossp,object.center), ft_mult_num_vector(m, ft_mult_num_vector(1/ft_lengthv(object.vectorperp),object.vectorperp)));
return(normal);
}

t_coord	ft_getnorm_cone(t_object object, t_coord crossp)
{
	double	m;
	double	k;
	t_coord	A;
	t_coord normal;
m = ft_dotprod(ft_substrv(crossp, object.center), ft_mult_num_vector(1/ft_lengthv(object.vectorperp),object.vectorperp));
A = ft_add_vector(object.center, ft_mult_num_vector(m, ft_mult_num_vector(1/ft_lengthv(object.vectorperp),object.vectorperp)));
k = ft_lengthv(ft_substrv(crossp, A)) / m;
normal = ft_substrv(ft_substrv(crossp, object.center), ft_mult_num_vector((1+k*k),ft_mult_num_vector(m, ft_mult_num_vector(1/ft_lengthv(object.vectorperp),object.vectorperp))));
return(normal);
}


t_coord	ft_getnorm_paraboloid(t_object object, t_coord crossp)
{
	double	m;
	t_coord v;
	t_coord normal;

	v = ft_mult_num_vector(1 / ft_lengthv(object.vectorperp), object.vectorperp);
	m = ft_dotprod(ft_substrv(crossp, object.center), v);
	normal = ft_substrv(ft_substrv(crossp, object.center), ft_mult_num_vector((m + object.k_paraboloid), v));
	normal = ft_norm_vector(normal);
	return(normal);
}
/*
void	ft_getnorm6(t_scene *scene, int i)// для тора
{
	double	k;
	t_coord	a;
	double	m;
	double	koef;
	k = ft_dotprod(ft_substrv(scene->cur_prop.p, scene->object[i]->center), \
	ft_mult_num_vector(1 / ft_lengthv(scene->object[i]->vectorperp), \
	scene->object[i]->vectorperp));
	a = ft_substrv(scene->cur_prop.p, ft_mult_num_vector(k, ft_mult_num_vector(1 / ft_lengthv(scene->object[i]->vectorperp), \
	scene->object[i]->vectorperp)));
	m = (scene->object[i]->tor.sr2 - k * k ) * (scene->object[i]->tor.sr2 - k * k );
	koef = m / (scene->object[i]->big_tor_radius + m);
	scene->cur_prop.normal = ft_substrv(scene->cur_prop.p, ft_substrv(a, ft_mult_num_vector(koef, ft_substrv(scene->object[i]->center, a))));

}*/
