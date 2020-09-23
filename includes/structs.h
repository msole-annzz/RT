/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msole <msole@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/09 19:46:15 by msole             #+#    #+#             */
/*   Updated: 2020/09/23 12:55:27 by msole            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct	s_img
{
	char		*data;
	int			size;
	int			endian;
	int			bpp;
}				t_img;

typedef struct	s_mlx
{
	void		*init;
	void		*win;
	void		*img;
}				t_mlx;

typedef struct	s_quadreq
{
	int			eqcount;
	double		x1;
	double		x2;
}				t_quadreq;

typedef struct	s_coord
{
	double		x;
	double		y;
	double		z;
}				t_coord;

typedef struct	s_angle
{
	double		x;
	double		y;
	double		z;
}				t_angle;

typedef struct	s_rotate
{
	double		anglex;
	double		angley;
	double		anglez;
}				t_rotate;

typedef struct	s_camera
{
	t_coord		place;
	t_rotate	rotate;
}				t_camera;

typedef struct	s_color
{
	char		r;
	char		g;
	char		b;
}				t_color;

typedef struct	s_object
{
	int			type;
	double		radius;
	t_coord		center;
	t_color		color;
	int			specular;
	double		angle;
	double		tang;
	t_coord		vectorperp; // хочется поменять на axis_obj
	double		reflection;
	double		refraction; //преломление
	t_angle		axis_angle; // угол для нормали объекта, для удобства управления
	int			high; // высота объекта, для ограничений

}				t_object;

typedef struct	s_light
{
	int			type;
	t_coord		position;
	t_coord		direction;
	double		intens;
	t_color		color; // цвет света

}				t_light;

typedef struct	s_distcolor
{
	t_color		color;
	double		dist;
	int			objnum;
	t_coord		normal;
	t_coord		p;
	t_coord		view;
}				t_distcolor;

/*
** issol: 0 -no solution, 1 -- is solution
*/

typedef struct	s_corsol
{
	double		sol;
	int			kobj;
	int			issol;
}				t_corsol;

typedef struct	s_trestr
{
	double		tmin;
	double		tmax;
}				t_restr;

typedef struct	s_scene
{
	t_mlx		mlx;
	t_img		image;
	t_camera	camera;
	t_object	**object;
	t_light		**lights;
	t_coord		cur_point;
	t_distcolor	cur_prop;
	t_color		bkg_color;
	t_angle		angle;
	double		d;
	int			thrminwidth;
	int			thrmaxwidth;
	int			current_light;
	int			current_object;
	int			n_lights;
	int			n_objects;
}				t_scene;

#endif
