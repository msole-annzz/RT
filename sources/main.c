/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msole <msole@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/09 15:13:49 by msole             #+#    #+#             */
/*   Updated: 2020/08/12 17:20:13 by msole            ###   ########.fr       */
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

/*
** Function <mlx_hook> has parametrs: 12 for expose_hook, 0 - for MAC
*/

void		ft_hooks(t_scene *scene)
{
	mlx_hook(scene->mlx.win, 12, 0, expose_hook, scene);
	mlx_hook(scene->mlx.win, 2, 0, scene_keys, scene);
}

int			main(int argc, char **argv)
{
	t_scene	*scene;
	char	*str;

	str = NULL;
	scene = NULL;
	if (argc != 2)
		file_error();
	if (!(scene = (t_scene *)malloc(sizeof(t_scene))))
		memory_allocation_error();
	str = read_file(argv[1], scene);
	scene->mlx.init = mlx_init();
	scene->mlx.win = mlx_new_window(scene->mlx.init, WIN_WIDTH, \
				WIN_HEIGHT, "RTV1");
	scene->mlx.img = mlx_new_image(scene->mlx.init, WIN_WIDTH, WIN_HEIGHT);
	scene->image.data = mlx_get_data_addr(scene->mlx.img, &scene->image.bpp,\
			&scene->image.size, &scene->image.endian);
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
