
#include "../includes/rt.h"

void color_to_anaglyph(t_scene	*scene)
{
	int		i;
	int		j;
	int		p;
	int		p1;
	int		p2;

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
			//anaglyph(scene, p1, p2, p);
			m_b(scene, p1, p2, p);
			i++;
		}
		i = 0;
		j++;
	}
	//mlx_put_image_to_window(scene->mlx.init, scene->mlx.win, scene->mlx.filtered_img, 0, 0);
}

void		ft_threads(t_scene *scene)
{
	int			i;
	pthread_t	threads[THREAD];
	t_scene		thread_data[THREAD];

	i = 0;
	while (i < THREAD)
	{
		ft_memcpy((void *)&thread_data[i], (void *)scene, sizeof(t_scene));
		thread_data[i].thrminwidth = ((double)(WIN_WIDTH / THREAD)) * i;
		thread_data[i].thrmaxwidth = ((double)(WIN_WIDTH / THREAD)) * (i + 1);
		i = i + 1;
	}
	i = 0;
	while (i < THREAD)
	{
		pthread_create(&(threads[i]), NULL, ft_traceray, &thread_data[i]);
		i = i + 1;
	}
	while (i--)
	{
		pthread_join(threads[i], NULL);
	}
	//if (scene->color_schema == 2)
	{	
		color_to_anaglyph(scene);
		mlx_put_image_to_window(scene->mlx.init, scene->mlx.win, scene->mlx.filtered_img, 0, 0);
	}
	//else
		//mlx_put_image_to_window(scene->mlx.init, scene->mlx.win, scene->mlx.img, 0, 0);
	//mlx_put_image_to_window(scene->mlx.init, scene->mlx.win, scene->mlx.img, 0, 0);
	//mlx_put_image_to_window(scene->mlx.init, scene->mlx.win, scene->mlx.filtered_img, 0, 0);
}
