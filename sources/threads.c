
#include "../includes/rt.h"

void color_to_anaglyph(t_scene	*scene)
{
	int		i;
	int		j;
	int		p;
	int		p1;
	int		p2;
	
	//scene->mlx.anaglyph_img = mlx_new_image(scene->mlx.init, WIN_WIDTH, WIN_HEIGHT);
	//scene->image.anaglyph_data = (int *)mlx_get_data_addr(scene->mlx.img, &scene->image.bpp,&scene->image.size, &scene->image.endian);
	


	i = 0;
	j = 0;
	while (j < WIN_HEIGHT)
	{
		while (i < WIN_WIDTH)
		{
			p = WIN_WIDTH * j + i;
			p1 = WIN_WIDTH * j + i - 3;
			p2 = WIN_WIDTH * j + i + 3;
			if ((i - 3) < 0)
				p1 = p;
			if ((i + 3) > WIN_WIDTH - 1)
				p2 = p;
			anaglyph(scene, p1, p2, p);
			i++;
		}
		i = 0;
		j++;
	}
	mlx_put_image_to_window(scene->mlx.init, scene->mlx.win, scene->mlx.filtered_img, 0, 0);
}

void	ft_intersect(t_scene *scene, t_coord ray)
{
	t_corsol	intersect;
	t_cross		result;
	double		deep;
	t_restr		limit;
	t_color color_light;
	// t_color	color_tmp[3];

	limit.tmin = 1;
	limit.tmax =  INT_MAX;
	intersect = ft_findnearobj(scene, scene->camera.place, ray, limit);
	// result = ft_intersect_objects(scene, scene->camera.place, ray);
	if (intersect.issol == INTERSECT)
	{
		scene->cur_prop.p = ft_add_vectors(scene->camera.place, ft_mult_num_vector(intersect.sol, scene->cur_point));
		ft_getnorms_and_view(scene, intersect.kobj);
		deep = 0;
		if (scene->object[intersect.kobj]->specular)
			deep = ft_light(scene, scene->object[intersect.kobj]->specular);
		ft_changecolor(scene, scene->object[intersect.kobj]->color, deep);
		// color_tmp[0] = ft_change_color_new(&scene->object[intersect.kobj]->color, deep);
	}
}


t_coord		ft_conv2to3(t_scene *scene, double x, double y)
{
	// t_coord direction;

	// direction.x = x * (double)VIEW_WIDTH / WIN_WIDTH;
	// direction.y = y * (double)VIEW_HEIGHT / WIN_HEIGHT;
	// direction.z = scene->d;
	// ft_rotate_vector(&scene->angle, &direction);
	// ft_normalized(&direction);
	// return (direction);

	scene->cur_point.x = x * (double)VIEW_WIDTH / WIN_WIDTH;
	scene->cur_point.y = y * (double)VIEW_HEIGHT / WIN_HEIGHT;
	scene->cur_point.z = scene->d;
	scene->cur_point = ft_rotatex(scene->angle, scene->cur_point);
	scene->cur_point = ft_rotatey(scene->angle, scene->cur_point);
	scene->cur_point = ft_rotatez(scene->angle, scene->cur_point);
	ft_normalized(&scene->cur_point);
	return (scene->cur_point);
}

void	*ft_traceray(void *thread_data)
{
	int		x;
	int		y;
	t_coord	ray;
	t_scene	*scene;

	scene = (t_scene *)(thread_data);
	x = scene->thrminwidth;
	y = 0;
	while (y < WIN_HEIGHT)
	{
		while (x < scene->thrmaxwidth)
		{
			ray = ft_conv2to3(scene, (double)x - scene->x0, scene->y0 - (double)y);
			ft_initcolor(scene);
			ft_intersect(scene, ray);
			ft_put_pixel(scene, x, y);
			x++;
		}
		x = scene->thrminwidth;
		y++;
	}
	return (thread_data);
}

void		ft_threads(t_scene *scene)
{
	int			i;
	pthread_t	thread[THREAD];
	t_scene		thread_data[THREAD];

	i = 0;
	while (i < THREAD)
	{
		ft_memcpy((void *)&thread_data[i], (void *)scene, sizeof(t_scene));
		thread_data[i].thrminwidth = (WIN_WIDTH / THREAD) * i;
		thread_data[i].thrmaxwidth = (WIN_WIDTH / THREAD) * (i + 1);
		i = i + 1;
	}
	i = 0;
	while (i < THREAD)
	{
		pthread_create(&(thread[i]), NULL, ft_traceray, &thread_data[i]);
		i = i + 1;
	}
	while (i--)
	{
		pthread_join(thread[i], NULL);
	}
	if (scene->color_schema == 2)
		color_to_anaglyph(scene);
	else
		mlx_put_image_to_window(scene->mlx.init, scene->mlx.win, scene->mlx.img, 0, 0);
}
