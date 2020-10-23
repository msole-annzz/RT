#include "../includes/rt.h"

void	*ft_traceray(void *thread_data)
{
	int		i;
	int		j;
	t_scene	*scene;
	t_coord cur_point;
	t_color local_color;
t_restr         r;
	
      r.tmin = 1;
      r.tmax = 100000;
scene = (t_scene *)(thread_data);
	

	i = scene->thrminwidth;
	j = 0;
	while (j < WIN_HEIGHT)
	{
		while (i < scene->thrmaxwidth)
		{
			cur_point=ft_conv2to3(scene, i - WIN_WIDTH / 2, j - WIN_HEIGHT / 2);
			local_color=ft_intersect(scene, scene->camera.place, cur_point, r, 1);
			ft_put_pixel(scene, i, j, ft_clamp(local_color));
			i++;
		}
		i = scene->thrminwidth;
		j++;
	}
	return (thread_data);
}

t_coord         check_normal(t_coord start, t_coord normal)
{
        if (ft_dotprod(start, normal) > 0)
                normal = ft_mult_num_vector(-1,normal);
return(normal);
}

t_coord ft_getnormals(t_coord end_point,t_object object, t_coord crossp)
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
normal = ft_mult_num_vector(1 / ft_lengthv(normal), normal);
normal=check_normal(end_point, normal);
return (normal);
}


t_coord ft_reflect_ray(t_coord v1, t_coord normal)
{
t_coord refl_ray;
refl_ray= ft_mult_num_vector(2*ft_dotprod(v1, normal), normal);
refl_ray=ft_substrv( v1,refl_ray);
return(refl_ray);
}



t_coord ft_refract_ray(t_coord v1, t_coord normal)
{
t_coord refr_ray;
refr_ray= ft_mult_num_vector(10, v1);
return(refr_ray);
}


//[200~ft_substrv(ft_mult_num_vector(ft_dotprod(cur_prop.normal, vl),ft_mult_num_vector(2, cur_prop.normal) ), vl);



t_color	ft_intersect(t_scene *scene, t_coord start_point, t_coord end_point, t_restr r, int recurs)
{
	t_corsol	t;
	double		deep;
	t_color color_light;
	t_distcolor cur_prop;
	t_coord reflected_ray;
	t_color local_color;
	t_color reflected_color;
	t_restr         r1;
        t_coord refracted_ray;
	t_color refracted_color;

      r1.tmin = 0.0001;
      r1.tmax = 100000;

	t = ft_findnearobj(scene, start_point, end_point, r);
	local_color=ft_initcolor(scene);  
	

if (t.issol == 1)
	{
		cur_prop.p = ft_add_vector(start_point, ft_mult_num_vector(t.sol, \
		end_point));
		cur_prop.normal=ft_getnormals(end_point,*scene->object[t.kobj], cur_prop.p);
		cur_prop.view = ft_mult_num_vector(-1,end_point);
		deep = 0;
		if (scene->object[t.kobj]->specular)
			deep = ft_ligth(scene,cur_prop,  scene->object[t.kobj]->specular);
		local_color=ft_changecolor(scene, scene->object[t.kobj]->color, deep);
		if (scene->object[t.kobj]->reflection <= 0 || recurs <= 0)
    			return (local_color);	
		else
		reflected_ray = ft_reflect_ray(cur_prop.normal,cur_prop.p);
	reflected_color = ft_intersect(scene,cur_prop.view, reflected_ray, r1, recurs - 1);

 return (ft_add2color(ft_mult_num_color(1 - scene->object[t.kobj]->reflection, local_color),
	     ft_mult_num_color(scene->object[t.kobj]->reflection, reflected_color)));
	
}
	
return(local_color);
}


t_color ft_add2color(t_color c1, t_color c2)
{
t_color res_color;
res_color.r = c1.r + c2.r;
res_color.g = c1.g + c2.g;
res_color.b = c1.b + c2.b;
return(res_color);
}

t_color ft_mult_num_color(double k, t_color c1)
{
t_color res_color;
res_color.r = c1.r * k;
res_color.g = c1.g * k;
res_color.b = c1.b * k;
return(res_color);
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
	//normal = ft_norm_vector(normal);
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
