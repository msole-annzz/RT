
#include "../includes/rt.h"

void		ft_init_scene(t_scene *scene)
{
	scene->d = 1;
	scene->bkg_color.r = 0;
	scene->bkg_color.g = 0;
	scene->bkg_color.b = 0;
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
	t_temp.issol = 0;// добавила, в интерсекте добавить else и чтобы в t.issol не попадал мусор из t.tempa, когда нет решения 
	while (scene->current_object < scene->n_objects)
	{
		if (scene->object[scene->current_object]->type == e_sphere)
			t_temp = ft_intersect_sfera(scene, o, c, r);
		if (scene->object[scene->current_object]->type == e_plane)
			t_temp = ft_intersect_plane(scene, o, c, r);
		if (scene->object[scene->current_object]->type == e_cylindr)
			t_temp = ft_intersect_cylinder(scene, o, c, r);
		if (scene->object[scene->current_object]->type == e_cone)
			t_temp = ft_intersect_cone(scene, o, c, r);
		if (scene->object[scene->current_object]->type == e_paraboloid)
			t_temp = ft_intersect_paraboloid(scene, o, c, r);
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
	mlx_hook(scene->legend.win, 2, 0, scene_keys, scene);
	//mlx_hook(scene->mlx.win, 17, 0, close_window, scene);
	//mlx_hook(scene->legend.win, 17, 0, close_window, scene);
}

int			main(int argc, char **argv)
{
	t_scene	*scene;
	char	*str;

	str = NULL;
	scene = NULL;
	if (argc != 2)
		file_error();
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
	scene->mlx.filtered_img = mlx_new_image(scene->mlx.init, WIN_WIDTH, WIN_HEIGHT);
	scene->legend.img = mlx_new_image(scene->mlx.init, WIN_WIDTH/2, WIN_HEIGHT);
	scene->image.data = (int *)mlx_get_data_addr(scene->mlx.img, &scene->image.bpp,&scene->image.size, &scene->image.endian);
	scene->image.filtered_data = (int *)mlx_get_data_addr(scene->mlx.filtered_img, &scene->image.bpp,&scene->image.size, &scene->image.endian);
	scene->legend_image.data = (int *) mlx_get_data_addr(scene->legend.img, &scene->legend_image.bpp, &scene->legend_image.size, &scene->legend_image.endian);
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
