
#include "../includes/rt.h"

void	sepia(t_scene *scene, int p)
{
	int		rgb[3];
	int		rgb_start[3];
	rgb_start[0] = scene->cur_prop.color.r;
	rgb_start[1] = scene->cur_prop.color.g;
	rgb_start[2] = scene->cur_prop.color.b;

	if (rgb_start[0] < 0)
		rgb_start[0] = -rgb_start[0];
	if (rgb_start[1] < 0)
		rgb_start[1] = -rgb_start[1];
	if (rgb_start[2] < 0)
		rgb_start[2] = -rgb_start[2];

	rgb[0] = (rgb_start[0] * .393) + (rgb_start[1] * .769) + (rgb_start[2] * .189);
	rgb[1] = (rgb_start[0] * .349) + (rgb_start[1] * .686) + (rgb_start[2] * .168);
	rgb[2] = (rgb_start[0] * .272) + (rgb_start[1] * .354) + (rgb_start[2] * .131);
	scene->image.data[p + 2] = rgb[0];
	scene->image.data[p + 1]= rgb[1];
	scene->image.data[p] = rgb[2];
}

void	ft_put_pixel(t_scene *scene, int i, int j)
{
	int p;

	p = 4 * (WIN_WIDTH * j + i);
	if (scene->color_schema == 0)
	{
		scene->image.data[p + 2] = scene->cur_prop.color.r;
		scene->image.data[p + 1] = scene->cur_prop.color.g;
		scene->image.data[p] = scene->cur_prop.color.b;
	}
	if (scene->color_schema == 1)
		sepia(scene, p);

}

void	ft_changecolor(t_scene *scene, t_color color, double deep)
{
	if (deep > 1)
		deep = 1;
	scene->cur_prop.color.r = color.r + deep * 90;
	scene->cur_prop.color.g = color.g + deep * 90;
	scene->cur_prop.color.b = color.b + deep * 90;
}

void	ft_initcolor(t_scene *scene)
{
	scene->cur_prop.color.r = scene->bkg_color.r;
	scene->cur_prop.color.g = scene->bkg_color.g;
	scene->cur_prop.color.b = scene->bkg_color.b;
}
