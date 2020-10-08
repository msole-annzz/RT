
#include "../includes/rt.h"

void color_to_anaglyph(t_scene	*scene)
{
	int		i;
	int		j;
	int		p;
	int		p1;
	int		p2;
	
	scene->mlx.anaglyph_img = mlx_new_image(scene->mlx.init, WIN_WIDTH, WIN_HEIGHT);
	scene->image.anaglyph_data = (int *)mlx_get_data_addr(scene->mlx.anaglyph_img, &scene->image.bpp,&scene->image.size, &scene->image.endian);
	
	i = 0;
	j = 0;
	while (j < WIN_HEIGHT)
	{
		while (i < WIN_WIDTH)
		{
			p = WIN_WIDTH * j + i;
			if ((i - 3) < 0)
				p1 = WIN_WIDTH * j + i;// как правильно сдвигаться??
			else
				p1 = WIN_WIDTH * j + i - 3;
			if ((i + 3) >= WIN_WIDTH)
				p2 = WIN_WIDTH * j + i;// как правильно сдвигаться??
			else
				p2 = WIN_WIDTH * j + i + 3;
			anaglyph(scene, p1, p2, p);
			i++;
		}
		i = 0;
		j++;
	}
	mlx_put_image_to_window(scene->mlx.init, \
		scene->mlx.win, scene->mlx.anaglyph_img, 0, 0);
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
	if (scene->color_schema == 2)
		color_to_anaglyph(scene);
	else
		mlx_put_image_to_window(scene->mlx.init, \
		scene->mlx.win, scene->mlx.img, 0, 0);
}
