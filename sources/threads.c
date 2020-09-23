/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msole <msole@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/09 19:10:39 by msole             #+#    #+#             */
/*   Updated: 2020/08/09 19:11:14 by msole            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

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
	mlx_put_image_to_window(scene->mlx.init, \
	scene->mlx.win, scene->mlx.img, 0, 0);
}
