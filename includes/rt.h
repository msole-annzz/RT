
#ifndef RT_H
# define RT_H

# define WIN_WIDTH		1000
# define WIN_HEIGHT		1000
# define VIEW_WIDTH		1
# define VIEW_HEIGHT	1
# define THREAD			8
# define BUFF			1000
# define MAX_FILE_SIZE	81920

# include <fcntl.h>
# include <errno.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <pthread.h>
# include "../libft/libft.h"
# include "../minilibx/mlx.h"
# include "keys.h"
# include "structs.h"
# include "parsing.h"
# include "stdio.h" // DELETE ME

t_coord		ft_mult_num_vector(double k, t_coord v);
double		ft_dotprod(t_coord v1, t_coord v2);
double		ft_lengthv(t_coord v);
t_coord		ft_add_vector(t_coord v1, t_coord v2);
t_coord		ft_substrv(t_coord v1, t_coord v2);
double		ft_modul_vector(t_coord v);
t_coord 	ft_norm_vector(t_coord vector);
t_coord		ft_rotatex(t_angle angle, t_coord v);
t_coord		ft_rotatey(t_angle angle, t_coord v);
t_coord		ft_rotatez(t_angle angle, t_coord v);
t_quadreq	ft_quadrsolution(double a, double b, double c);
t_quadreq	ft_sfera(t_coord origin, t_coord direction, t_object object);
t_quadreq	ft_cylinder(t_coord origin, t_coord direction, t_object object);
t_quadreq	ft_cone(t_coord origin, t_coord direction, t_object object);
t_quadreq	ft_plane(t_coord origin, t_coord direction, t_object object);
t_quadreq	ft_paraboloid(t_coord origin, t_coord direction, t_object object);
t_corsol	ft_findnearobj(t_scene *scene, t_coord o, t_coord c, t_restr r);
int			scene_keys(int keycode, t_scene *scene);
int			expose_hook(t_scene *scene);
int			ft_legend(t_scene *scene);
void		ft_threads(t_scene *scene);
t_corsol	ft_intersect_sfera(t_scene *scene, t_coord o, t_coord c, t_restr r);
t_corsol	ft_intersect_cylinder(t_scene *scene, t_coord o, t_coord c, \
								t_restr r);
t_corsol	ft_intersect_cone(t_scene *scene, t_coord o, t_coord c, t_restr r);
t_corsol	ft_intersect_plane(t_scene *scene, t_coord o, t_coord c, t_restr r);
t_corsol	ft_intersect_paraboloid(t_scene *scene, t_coord o, t_coord c, t_restr r);
void		*ft_traceray(void *thread_data);
t_distcolor     ft_intersect(t_scene *scene, t_coord start_point, t_coord end_point, t_distcolor cur_prop);
double ft_ligth(t_scene *scene, t_coord normal, t_coord point,t_coord view, int s);
void		ft_put_pixel(t_scene *scene, int i, int j, t_distcolor cur_prop);
t_distcolor     ft_changecolor(t_scene *scene, t_color color, double deep);
t_distcolor     ft_initcolor(t_scene *scene);
t_quadreq	ft_quadrsolution(double a, double b, double c);
t_corsol	ft_get_correct_solution(t_quadreq t, t_restr r, int k);
t_coord         ft_conv2to3(t_scene *scene, int x, int y);
t_coord ft_getnorm_cylinder(t_object object, t_coord crossp);
t_coord ft_getnorm_cone(t_object object, t_coord crossp);
t_coord ft_getnorm_paraboloid(t_object object, t_coord crossp);
void		ft_getnorms_and_view (t_scene *scene, int i);
double		ft_shine(t_scene *scene, int s, t_coord vl, t_light *light);
double		ft_lights23(t_scene *scene, t_restr r, t_light *light, int s);
void		ft_threads(t_scene *scene);
// Dobavil function
int			close_window(void *param);

/*
**mouse.c
*/
int		ft_mouse(int mouse, int x, int y, t_scene *scene);
int		ft_mouse_release(int mouse, int x, int y, t_scene *scene);
int		ft_mouse_move(int x, int y, t_scene *scene);

void color_to_anaglyph(t_scene	*scene);
void	anaglyph(t_scene *scene, int p1, int p2, int p);
void color_to_anaglyph(t_scene	*scene);
void	m_b(t_scene *scene, int p1, int p2, int p);

t_color add_light_color(t_scene *scene, t_coord o, t_coord c);
//int add_light_color(t_scene *scene/*, t_coord o, t_coord c*/);

t_coord vector_mult(t_coord v1, t_coord v2);
#endif
