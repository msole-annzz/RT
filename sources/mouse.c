
#include "../includes/rt.h"

int		ft_mouse(int mouse, int x, int y, t_scene *scene)
{
	t_corsol	t;
	t_restr		r;
	scene->mouse->is_press = 0;
	if (mouse == 1)
	{
		scene->mouse->is_press = 1;
		scene->mouse->x = x;
		scene->mouse->y = y;
		ft_conv2to3(scene, x - WIN_WIDTH / 2, y - WIN_HEIGHT / 2);
		r.tmin = 1;
		r.tmax = 100000;
		t = ft_findnearobj(scene, scene->camera.place, scene->cur_point, r);
		scene->mouse->num_obj = t.kobj;
	}
	return (0);
}

int		ft_mouse_release(int mouse, int x, int y, t_scene *scene)
{
	(void)mouse;
	t_new_x_y new;
	t_new_x_y old;
	double delta;

	delta = scene->object[scene->mouse->num_obj]->center.z + scene->d;
	mlx_clear_window(scene->mlx.init, scene->mlx.win);
	old.x = scene->mouse->x * (double)VIEW_WIDTH / WIN_WIDTH;
	old.y = -scene->mouse->y * (double)VIEW_HEIGHT / WIN_HEIGHT;
	new.x = x * (double)VIEW_WIDTH / WIN_WIDTH;
	new.y = -y * (double)VIEW_HEIGHT / WIN_HEIGHT;
	scene->object[scene->mouse->num_obj]->center.x = scene->object[scene->mouse->num_obj]->center.x - old.x * delta + new.x * delta;
	scene->object[scene->mouse->num_obj]->center.y = scene->object[scene->mouse->num_obj]->center.y - old.y * delta + new.y * delta;
	ft_threads(scene);
	return (0);
}
//пока не нужна
/*
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
*/
