/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditsch <aditsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 17:37:31 by aditsch           #+#    #+#             */
/*   Updated: 2017/02/03 13:24:29 by aditsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H

# include <math.h>
# include "../libft/libft.h"
# include "../minilibx/osx/mlx.h"
# include "keycode_osx.h"
# include "vector.h"
# include "matrix.h"

# define MIN_H 0
# define MAX_H 1440
# define MIN_W 0
# define MAX_W 2560

typedef	enum			e_section
{
						NONE,
						WINDOW,
						CAMERA,
						SPHERE,
						PLANE,
						LIGHT,
}						t_section;

typedef struct			s_img
{
	void				*img_ptr;
	char				*data;
	int					bpp;
	int					size_line;
	int					endian;
}						t_img;

typedef struct			s_cam
{
	t_v3				pos;
	t_v3				rot;
}						t_cam;

typedef struct			s_obj
{
	char				*type;
	t_v3				pos;
	t_v3				rot;
	double				radius;
	int					color;
}						t_obj;

typedef struct			s_light
{
	int					id;
	t_v3				pos;
	double				intensity;
}						t_light;

typedef struct			s_scene
{
	char				*title;
	int					width;
	int					height;
	t_cam				*cam;
	t_img				*img;
	t_list				*obj_list;
	t_list				*light_list;
}						t_scene;

typedef struct			s_env
{
	void				*mlx;
	void				*win;
	t_scene				*scene;
}						t_env;

t_scene					*ft_init_scene(int fd);
t_env					*ft_init_env(void);
void					ft_destroy_env(t_env *env);
void					*ft_init_window(t_env *env);
void					ft_draw_window(t_env *env);
int						ft_expose_hook(t_env *env);
int						ft_key_hook(int keycode, t_env *env);
/*
**	Parser
*/
int						ft_parse_scene(t_scene *scene, int fd);
int						ft_set_window(t_scene *sc, char *line);
int						ft_set_camera(t_cam *sc, char *line);
int						ft_set_light(t_list **light_list, char *line);
int						ft_set_object(t_list **object_list, char *line);
void					ft_set_v3(t_v3 *v, char *line);
char					*ft_get_value(char *line);
/*
**	debug.c
*/
void					ft_display_scene_value(t_scene *sc);
void					ft_display_window_value(t_scene *sc);
#endif
