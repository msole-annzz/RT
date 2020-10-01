#include "../includes/rt.h"

void	*ft_traceray(void *thread_data)
{
	int		i;
	int		j;
	t_scene	*scene;

	scene = (t_scene *)(thread_data);
	i = scene->thrminwidth;
	j = 0;
	while (j < WIN_HEIGHT)
	{
		while (i < scene->thrmaxwidth)
		{
			ft_conv2to3(scene, i - WIN_WIDTH / 2, j - WIN_HEIGHT / 2);
			ft_initcolor(scene);
			ft_intersect(scene);
			ft_put_pixel(scene, i, j);
			i++;
		}
		i = scene->thrminwidth;
		j++;
	}
	return (thread_data);
}

void	ft_intersect(t_scene *scene)
{
	t_corsol	t;
	double		deep;
	t_restr		r;

	r.tmin = 1;
	r.tmax = 100000;
	t = ft_findnearobj(scene, scene->camera.place, scene->cur_point, r);
	if (t.issol == 1)
	{
		scene->cur_prop.p = ft_addv(scene->camera.place, ft_multkv(t.sol, \
		scene->cur_point));
		ft_getnorms_and_view(scene, t.kobj);
		deep = 0;
		if (scene->object[t.kobj]->specular)
			deep = ft_light(scene, scene->object[t.kobj]->specular);
		ft_changecolor(scene, scene->object[t.kobj]->color, deep);
	}
}

void	ft_getnorm3(t_scene *scene, int i)
{
	double m;

	m = ft_dotprod(ft_substrv(scene->cur_prop.p, scene->object[i]->center), \
	ft_multkv(1 / ft_lengthv(scene->object[i]->vectorperp), \
	scene->object[i]->vectorperp));
	scene->cur_prop.normal = ft_substrv(ft_substrv(scene->cur_prop.p, \
	scene->object[i]->center), ft_multkv(m, ft_multkv(1 / \
	ft_lengthv(scene->object[i]->vectorperp), \
	scene->object[i]->vectorperp)));
}

void	ft_getnorm4(t_scene *scene, int i)
{
	double	m;
	double	k;
	t_coord	a;

	m = ft_dotprod(ft_substrv(scene->cur_prop.p, scene->object[i]->center), \
	ft_multkv(1 / ft_lengthv(scene->object[i]->vectorperp), \
	scene->object[i]->vectorperp));
	a = ft_addv(scene->object[i]->center, ft_multkv(m, ft_multkv(1 / \
	ft_lengthv(scene->object[i]->vectorperp), scene->object[i]->vectorperp)));
	k = ft_lengthv(ft_substrv(scene->cur_prop.p, a)) / m;
	scene->cur_prop.normal = ft_substrv(ft_substrv(scene->cur_prop.p, \
	scene->object[i]->center), ft_multkv((1 + k * k), ft_multkv(m, \
	ft_multkv(1 / ft_lengthv(scene->object[i]->vectorperp), \
	scene->object[i]->vectorperp))));
}


void	ft_getnorm5(t_scene *scene, int i)
{
	double	m;

	m = ft_dotprod(ft_substrv(scene->cur_prop.p, scene->object[i]->center), \
	ft_multkv(1 / ft_lengthv(scene->object[i]->vectorperp), \
	scene->object[i]->vectorperp));
	scene->cur_prop.normal = ft_substrv(ft_substrv(scene->cur_prop.p, scene->object[i]->center), ft_multkv((m + scene->object[i]->k_paraboloid), ft_multkv(1 / ft_lengthv(scene->object[i]->vectorperp), scene->object[i]->vectorperp)));
}

void	ft_getnorm6(t_scene *scene, int i)// для тора
{
	double	k;
	t_coord	a;
	double	m;
	double	koef;
	k = ft_dotprod(ft_substrv(scene->cur_prop.p, scene->object[i]->center), \
	ft_multkv(1 / ft_lengthv(scene->object[i]->vectorperp), \
	scene->object[i]->vectorperp));
	a = ft_substrv(scene->cur_prop.p, ft_multkv(k, ft_multkv(1 / ft_lengthv(scene->object[i]->vectorperp), \
	scene->object[i]->vectorperp)));
	m = (scene->object[i]->tor.sr2 - k * k ) * (scene->object[i]->tor.sr2 - k * k );
	koef = m / (scene->object[i]->big_tor_radius + m);
	scene->cur_prop.normal = ft_substrv(scene->cur_prop.p, ft_substrv(a, ft_multkv(koef, ft_substrv(scene->object[i]->center, a))));

}

void	ft_getnorms_and_view(t_scene *scene, int i)
{
	if (scene->object[i]->type == e_sphere)
		scene->cur_prop.normal = ft_substrv(scene->cur_prop.p, \
		scene->object[i]->center);
	if (scene->object[i]->type == e_plane)
		scene->cur_prop.normal = scene->object[i]->vectorperp;
	if (scene->object[i]->type == e_cylindr)
		ft_getnorm3(scene, i);
	if (scene->object[i]->type == e_cone)
		ft_getnorm4(scene, i);
	if (scene->object[i]->type == 5)
		ft_getnorm5(scene, i);
	/*if (scene->object[i]->type == 6)
		ft_getnorm6(scene, i);

*/
	scene->cur_prop.normal = ft_multkv(1 / ft_lengthv(scene->cur_prop.normal), \
	scene->cur_prop.normal);
	scene->cur_prop.view = ft_multkv(-1, scene->cur_point);
}
