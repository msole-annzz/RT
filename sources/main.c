/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrhett <wrhett@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/09 15:13:49 by msole             #+#    #+#             */
/*   Updated: 2020/09/28 12:13:41 by wrhett           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

void		ft_init_scene(t_scene *scene)
{
	scene->d = 1;
	scene->bkg_color.r = 0xff;
	scene->bkg_color.g = 0xff;
	scene->bkg_color.b = 0xff;
	scene->angle.x = 0;
	scene->angle.y = 0;
	scene->angle.z = 0;
	scene->color_schema = 0;
}

/*
** Function <ft_findnearobj> finds the point of intersection of a ray OC
** with the nearest object of any type.
** Last if: if the point of intersection with the k-th object is closer then t,
** we rewrite t.
*/

t_corsol	ft_findnearobj(t_scene *scene, t_coord o, t_coord c, t_restr r)
{
	t_corsol	t_temp;
	t_corsol	t;

	scene->current_object = 0;
	t.sol = 0;
	while (scene->current_object < scene->n_objects)
	{
		if (scene->object[scene->current_object]->type == 1)
			t_temp = ft_intersectsfera(scene, o, c, r);
		if (scene->object[scene->current_object]->type == 2)
			t_temp = ft_intersectplane(scene, o, c, r);
		if (scene->object[scene->current_object]->type == 3)
			t_temp = ft_intersectcylinder(scene, o, c, r);
		if (scene->object[scene->current_object]->type == 4)
			t_temp = ft_intersectcone(scene, o, c, r);
		if (((t_temp.issol == 1) && (t_temp.sol < t.sol)) || \
		((t_temp.issol == 1) && (t.sol == 0)))
			t = t_temp;
		scene->current_object++;
	}
	return (t);
}

void		ft_conv2to3(t_scene *scene, int x, int y)
{
	scene->cur_point.x = x * (double)VIEW_WIDTH / WIN_WIDTH;
	scene->cur_point.y = -y * (double)VIEW_HEIGHT / WIN_HEIGHT;
	scene->cur_point.z = scene->d;
	scene->cur_point = ft_rotatex(scene->angle, scene->cur_point);
	scene->cur_point = ft_rotatey(scene->angle, scene->cur_point);
	scene->cur_point = ft_rotatez(scene->angle, scene->cur_point);
}

int		ft_mouse(int mouse, int x, int y, t_scene *scene)
{
	//(void)x;
	//(void)y;
	t_corsol	t;
	t_restr		r;
	scene->mouse->is_press = 0;
	//if ((mouse == 4) || (mouse == 5))
	//	ft_zoom(mouse, fractol);
	//printf("x %d\n", x);
	if (mouse == 1)
	{
		scene->mouse->is_press = 1;
		scene->mouse->x = x;
		scene->mouse->y = y;
		ft_conv2to3(scene, x - WIN_WIDTH / 2, y - WIN_HEIGHT / 2);

	r.tmin = 1;
	r.tmax = 100000;
	t = ft_findnearobj(scene, scene->camera.place, scene->cur_point, r);
		printf("№ %d\n", t.kobj);
		scene->mouse->num_obj = t.kobj;
	}
	return (0);
}

t_new_x_y	ft_conv2to3_return(t_scene *scene, int x, int y)
{

	t_new_x_y new;
	scene->cur_point.x = x * (double)VIEW_WIDTH / WIN_WIDTH;
	scene->cur_point.y = -y * (double)VIEW_HEIGHT / WIN_HEIGHT;
	scene->cur_point.z = scene->d;
	scene->cur_point = ft_rotatex(scene->angle, scene->cur_point);
	scene->cur_point = ft_rotatey(scene->angle, scene->cur_point);
	scene->cur_point = ft_rotatez(scene->angle, scene->cur_point);
	new.x = scene->cur_point.x;
	new.y = scene->cur_point.y;
	printf("new.X %f/n", new.x);
	return(new);
}


int		ft_mouse_release(int mouse, int x, int y, t_scene *scene)
{
	(void)mouse;
	//(void)x;
	//(void)y;

	t_new_x_y new;
	t_new_x_y old;

	mlx_clear_window(scene->mlx.init, scene->mlx.win);
	//fractol->mouse->is_press = 0;
	//scene->mouse->new_x = x;
	//scene->mouse->new_y = y;
	old = ft_conv2to3_return(scene, scene->mouse->x- WIN_WIDTH/2, scene->mouse->y- WIN_HEIGHT / 2);//ft_conv2to3(scene, i - WIN_WIDTH / 2, j - WIN_HEIGHT / 2);
	new = ft_conv2to3_return(scene, x- WIN_WIDTH/2, y- WIN_HEIGHT / 2);//ft_conv2to3(scene, i - WIN_WIDTH / 2, j - WIN_HEIGHT / 2);


printf("old.x %f/n", old.x);
printf("new.x %f/n", new.x);

	scene->object[scene->mouse->num_obj]->center.x = scene->object[scene->mouse->num_obj]->center.x -
			- old.x + new.x;
	scene->object[scene->mouse->num_obj]->center.y = scene->object[scene->mouse->num_obj]->center.y -
			- old.y + new.y;
	ft_threads(scene);
	return (0);
}

int		ft_mouse_move(int x, int y, t_scene *scene)
{
	scene->mouse->x = x;
	scene->mouse->y = y;

printf("x %d\n", scene->mouse->x);
	//if ((x > 0 && y > 0) && (x < WIN_WIDTH && y < WIN_HEIGHT))
	//{
//
	//}
	return (0);
}
/*
** Function <mlx_hook> has parametrs: 12 for expose_hook, 0 - for MAC

**	mlx_hook (mlx.win, 4, 0, *ft, *param);
** 4- mouse scroll & mouse key press
**	mlx_hook (mlx.win, 5, 0, *ft, *param);
** 5- mouse not clicked
**	mlx_hook (fmlx.win, 6, 0, *ft, *param);
** 6 - movements of the mouse
*/

void		ft_hooks(t_scene *scene)
{
	mlx_hook(scene->mlx.win, 12, 0, expose_hook, scene);

	mlx_hook(scene->mlx.win, 4, 0, ft_mouse, scene);
	mlx_hook(scene->mlx.win, 5, 0, ft_mouse_release, scene);
	//mlx_hook(scene->mlx.win, 6, 0, ft_mouse_move, scene);

	mlx_hook(scene->mlx.win, 2, 0, scene_keys, scene);
	mlx_hook(scene->mlx.win, 17, 0, close_window, scene);
}

int			main(int argc, char **argv)
{
	t_scene	*scene;
	char	*str;

	str = NULL;
	scene = NULL;
	if (argc != 2)
		file_error();
	//if (!(scene = (t_scene *)malloc(sizeof(t_scene))) && !(scene->mouse = (t_mouse *)malloc(sizeof(t_mouse))))
	//


	if (!(scene = (t_scene *)malloc(sizeof(t_scene))) ||\
					!(scene->mouse = (t_mouse *)malloc(sizeof(t_mouse))))
		memory_allocation_error();


	str = read_file(argv[1], scene);
	//check_parsing(scene); // DELETE ME
	scene->mlx.init = mlx_init();
	scene->legend.init = scene->mlx.init;
	scene->mlx.win = mlx_new_window(scene->mlx.init, WIN_WIDTH, \
				WIN_HEIGHT, "RT");
	scene->legend.win = mlx_new_window(scene->mlx.init, WIN_WIDTH/2, \
				WIN_HEIGHT, "Legend");
	scene->mlx.img = mlx_new_image(scene->mlx.init, WIN_WIDTH, WIN_HEIGHT);
	scene->legend.img = mlx_new_image(scene->mlx.init, WIN_WIDTH/2, WIN_HEIGHT);
	scene->image.data = mlx_get_data_addr(scene->mlx.img, &scene->image.bpp,\
			&scene->image.size, &scene->image.endian);
	scene->legend_image.data = mlx_get_data_addr(scene->legend.img, &scene->legend_image.bpp, &scene->legend_image.size, &scene->legend_image.endian);
	ft_init_scene(scene);
	ft_threads(scene);
	ft_hooks(scene);
	ft_legend(scene);
	mlx_loop(scene->mlx.init);
	free(str);
	ft_free_scene(scene);
	free(scene);
	return (0);
}
