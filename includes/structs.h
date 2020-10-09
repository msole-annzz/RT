
#ifndef STRUCTS_H
# define STRUCTS_H

typedef enum
{
	e_not,
	e_sphere,
	e_plane,
	e_cylindr,
	e_cone,
	e_hemisphere,
	e_ambient,
	e_point,
	e_direct,
	e_caps,
	e_body,
	e_pull,
	e_push,
	e_paraboloid,

}	t_name;

typedef struct	s_img
{
	int			*data;
	int			size;
	int			endian;
	int			bpp;
	int			*filtered_data;
}				t_img;

typedef struct	s_mlx
{
	void		*init;
	void		*win;
	void		*img;
	void		*filtered_img;
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
	int		r;
	int		g;
	int		b;
}				t_color;

typedef struct	s_torus
{
	double	a;
	double	b;
	double	c;
	double	d;
	double	e;
	double		m;
	double		n;
	double		o;
	double		p;
	double		q;
	double		sr2;//маленький радиус в квадрате
	double		br2;//большой радиус в квадрате

}				t_torus;

typedef struct	s_object
{
	int			type;
	double		radius;
	t_coord		center;
	t_color		color;
	int			specular;
	double		angle;
	double		k_paraboloid;//коэффициент для построения парабалоида
	t_coord		vectorperp; // хочется поменять на axis_obj
	double		reflection;
	double		refraction; //преломление
	t_coord		axis_angle; // угол для нормали объекта, для удобства управления
	int			high; // высота объекта, для ограничений
	double		small_tor_radius;// радус шарика, который крутиться вокруг оси
	double		big_tor_radius;//радиус окружности вращения


	double		tang;// тангенс angle, не парсится, а рассчитывается
	t_torus		tor; // структура для рассчета тора, не парсится


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

//is_press - 0/1 - key is/is not pressed
typedef struct	s_new_x_y
{
	double			x;
	double			y;
}				t_new_x_y;

typedef struct	s_mouse
{
	int			x;
	int			y;
	//t_new_x_y 		new_x_y;
//	int			new_y;
	int			is_press;
	int			num_obj;
}				t_mouse;

typedef struct	s_scene
{
	t_mlx		mlx;
	t_mlx		legend;
	t_img		image;
	//t_img		filtered_image;
	t_img		legend_image;
	//t_img		anaglyph_image;
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
	int			color_schema; // 0 - standart; 1 - sepia;

	t_mouse		*mouse;
	}				t_scene;

#endif
