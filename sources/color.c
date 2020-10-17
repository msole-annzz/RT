#include "../includes/rt.h"

void	sepia(t_scene *scene, int p, t_color color)
{
	int		rgb[3];
	int		rgb_start[3];
	rgb_start[0] = color.r;
	rgb_start[1] = color.g;
	rgb_start[2] = color.b;

	if ((rgb[0] = (rgb_start[0] * .393) + (rgb_start[1] * .769) + (rgb_start[2] * .189)) > 255)
		rgb[0]= 255;
	else
		rgb[0] = (rgb_start[0] * .393) + (rgb_start[1] * .769) + (rgb_start[2] * .189);

	if ((rgb[1] = (rgb_start[0] * .349) + (rgb_start[1] * .686) + (rgb_start[2] * .168)) > 255)
		rgb[1] = 255;
	else
		rgb[1] = (rgb_start[0] * .349) + (rgb_start[1] * .686) + (rgb_start[2] * .168);


	if ((rgb[2] = (rgb_start[0] * .272) + (rgb_start[1] * .354) + (rgb_start[2] * .131)) > 255)
		rgb[2] = 255;
	else
		rgb[2] = (rgb_start[0] * .272) + (rgb_start[1] * .354) + (rgb_start[2] * .131);

	scene->image.data[p] = ((rgb[0] << 16) | (rgb[1] << 8) | rgb[2]);
}

t_color int_to_rgb(int p)
{
	t_color c;

	c.r = (p >> 16) & 0xFF;
	c.g = (p >> 8) & 0xFF;
	c.b = (p >> 16) & 0xFF;
	return(c);
}

void	anaglyph(t_scene *scene, int p1, int p2, int p)
{
	t_color c1;
	t_color c2;
	t_color c;
	
	c1 = int_to_rgb(scene->image.data[p1]);
	c2 = int_to_rgb(scene->image.data[p2]);
	c = int_to_rgb(scene->image.data[p]);
	c.r = c1.r * 0.299 + c1.g * 0.587 + c1.b * 0.114;
	c.g = c2.g * 1;
	c.b = c2.b * 1;
	scene->image.filtered_data[p] = ((c.r << 16) | (c.g << 8) | c.b);
}

// работающий анаглиф
/*
void	anaglyph(t_scene *scene, int p1, int p2, int p)
{
	t_color c1;
	t_color c2;
	t_color c;
	
	c1 = int_to_rgb(scene->image.data[p1]);
	c2 = int_to_rgb(scene->image.data[p2]);
	c = int_to_rgb(scene->image.data[p]);
	c.r = c1.r * 0.299 + c1.g * 0.587 + c1.b * 0.114;
	c.g = 0;
	c.b = c2.r * 0.299 + c2.g * 0.587 + c2.b * 0.114;
	scene->image.filtered_data[p] = ((c.r << 16) | (c.g << 8) | c.b);
}
*/


/*
t_color	anaglyph(t_scene *scene, int p1, int p2, int p)
{
	int		rgb2[3];
	int		rgb1[3];
	int		rgb_fin[3];
	rgb1[0] = scene->image.data[p1];
	rgb1[1] = scene->image.data[p1 +1];
	rgb1[2] = scene->image.data[p1 + 2];

	rgb2[0] = scene->image.data[p2];
	rgb2[1] = scene->image.data[p2 +1];
	rgb2[2] = scene->image.data[p2 + 2];



	scene->image.data[p] = rgb1[0] * 0.299 + rgb1[1] * 0.587 + rgb1[2] * 0.114;
	scene->image.data[p+1] = 0;
	scene->image.data[p+2] = rgb2[0] * 0.299 + rgb2[1] * 0.587 + rgb2[2] * 0.114;



}
*/

t_color ft_clamp(t_color color)
{
t_color color_res;

color_res.r = MIN(255, MAX(0, color.r));
color_res.g = MIN(255, MAX(0, color.g));
color_res.b = MIN(255, MAX(0, color.b));

return(color_res);
}


void    ft_put_pixel(t_scene *scene, int i, int j, t_color color)
{
    int p;
    int red;
    int green;
    int blue;


    p = (WIN_WIDTH * j + i);
    if (scene->color_schema == 0)
    {


    red = color.r;
    green = color.g;
    blue = color.b;

    scene->image.data[p] = ((red << 16) | (green << 8) | blue);
	}
    if (scene->color_schema == 1)
      sepia(scene, p, color);
	//if (scene->color_schema == 2)
      //anaglyph (scene, p);

}


/*void	ft_changecolor(t_scene *scene, t_color color, double deep)
{
	if (deep > 1)
		deep = 1;
	if ((scene->cur_prop.color.r = color.r + deep * 90) > 255)
		scene->cur_prop.color.r = 255;
	else
		scene->cur_prop.color.r = color.r + deep * 90;
	if ((scene->cur_prop.color.g = color.g + deep * 90) > 255)
		scene->cur_prop.color.g = 255;
	else
		scene->cur_prop.color.g = color.g + deep * 90;

	if ((scene->cur_prop.color.b = color.b + deep * 90) > 255)
		scene->cur_prop.color.b = 255;
	else
		scene->cur_prop.color.b = color.b + deep * 90;

}*/

t_color	ft_changecolor(t_scene *scene, t_color color, double deep)
{
t_color	local_color;
	if (deep > 1)
		deep = 1;
	if ((local_color.r = color.r * deep) > 255)
		local_color.r = 255;
	else
		local_color.r = color.r * deep;
	if ((local_color.g = color.g * deep) > 255)
		local_color.g = 255;
	else
		local_color.g = color.g * deep;

	if ((local_color.b = color.b * deep) > 255)
		local_color.b = 255;
	else
		local_color.b = color.b * deep;
return(local_color);
}


t_color	ft_initcolor(t_scene *scene)
{
t_color color;
	color.r = scene->bkg_color.r;
	color.g = scene->bkg_color.g;
	color.b = scene->bkg_color.b;
return(color);
}
