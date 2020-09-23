/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msole <msole@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/09 16:48:27 by msole             #+#    #+#             */
/*   Updated: 2020/08/12 17:01:59 by msole            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

void	ft_rotate(int keycode, t_scene *scene)
{
	if (keycode == KEY_ANSI_R)
		scene->angle.x = scene->angle.x - 0.1;
	if (keycode == KEY_ANSI_T)
		scene->angle.x = scene->angle.x + 0.1;
	if (keycode == KEY_ANSI_F)
		scene->angle.y = scene->angle.y - 0.1;
	if (keycode == KEY_ANSI_G)
		scene->angle.y = scene->angle.y + 0.1;
	if (keycode == KEY_ANSI_V)
		scene->angle.z = scene->angle.z - 0.1;
	if (keycode == KEY_ANSI_B)
		scene->angle.z = scene->angle.z + 0.1;
}

void	ft_move(int keycode, t_scene *scene)
{
	if (keycode == KEY_LEFTARROW)
		scene->camera.place.x = scene->camera.place.x - 1;
	if (keycode == KEY_RIGHTARROW)
		scene->camera.place.x = scene->camera.place.x + 1;
	if (keycode == KEY_DOWNARROW)
		scene->camera.place.y = scene->camera.place.y + 1;
	if (keycode == KEY_UPARROW)
		scene->camera.place.y = scene->camera.place.y - 1;
	if (keycode == KEY_ANSI_A)
		scene->camera.place.z = scene->camera.place.z + 1;
	if (keycode == KEY_ANSI_Z)
		scene->camera.place.z = scene->camera.place.z - 1;
}

int		scene_keys(int keycode, t_scene *scene)
{
	if (keycode == KEY_ESCAPE)
	{
		mlx_destroy_window(scene->mlx.init, scene->mlx.win);
		exit(0);
	}
	if ((keycode == KEY_LEFTARROW) || (keycode == KEY_RIGHTARROW) || \
		(keycode == KEY_DOWNARROW) || (keycode == KEY_UPARROW) || \
		(keycode == KEY_ANSI_A) || (keycode == KEY_ANSI_Z))
		ft_move(keycode, scene);
	if ((keycode == KEY_ANSI_R) || (keycode == KEY_ANSI_T) || \
		(keycode == KEY_ANSI_F) || (keycode == KEY_ANSI_G) || \
		(keycode == KEY_ANSI_V) || (keycode == KEY_ANSI_B))
		ft_rotate(keycode, scene);
	ft_threads(scene);
	ft_legend(scene);
	return (0);
}

int		ft_legend(t_scene *scene)
{
	mlx_string_put(scene->mlx.init, scene->mlx.win, WIN_WIDTH - 300, 20, \
	0xaaaaaa, "Camera position: x - < / >");
	mlx_string_put(scene->mlx.init, scene->mlx.win, WIN_WIDTH - 130, 40, \
	0xaaaaaa, "y - ^ / v");
	mlx_string_put(scene->mlx.init, scene->mlx.win, WIN_WIDTH - 130, 60, \
	0xaaaaaa, "z - a / z");
	mlx_string_put(scene->mlx.init, scene->mlx.win, WIN_WIDTH - 300, 100, \
	0xaaaaaa, "Rotation:        x - f / g");
	mlx_string_put(scene->mlx.init, scene->mlx.win, WIN_WIDTH - 130, 120, \
	0xaaaaaa, "y - r / t");
	mlx_string_put(scene->mlx.init, scene->mlx.win, WIN_WIDTH - 130, 140, \
	0xaaaaaa, "v - b / z");
	return (0);
}

int		expose_hook(t_scene *scene)
{
	mlx_put_image_to_window(scene->mlx.init, scene->mlx.win, \
	scene->mlx.img, 0, 0);
	ft_legend(scene);
	return (1);
}
