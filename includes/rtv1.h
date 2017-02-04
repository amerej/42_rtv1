/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditsch <aditsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 17:37:31 by aditsch           #+#    #+#             */
/*   Updated: 2017/02/04 18:59:04 by aditsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H

# include <math.h>
# include "../libft/libft.h"
# include "../minilibx/osx/mlx.h"
# include "parser.h"
# include "keycode_osx.h"
# include "image.h"
# include "vector.h"
# include "camera.h"
# include "light.h"
# include "object.h"
# include "ray.h"

typedef struct		s_scene
{
	int				width;
	int				height;
	t_camera		*camera;
	t_image			*image;
	t_list			*object;
	t_list			*light;
}					t_scene;

typedef struct		s_app
{
	void			*mlx;
	void			*win;
	t_scene			*scene;
}					t_app;

t_scene				*ft_init_scene(int fd);
t_app				*ft_init_app(void);
void				ft_destroy_app(t_app *app);
void				*ft_init_window(t_app *app);
void				ft_draw_window(t_app *app);
int					ft_expose_hook(t_app *app);
int					ft_key_hook(int keycode, t_app *app);
/*
**	Parser
*/
int					ft_parse_scene(t_scene *scene, int fd);
int					ft_parse_window(t_scene *scene, char *line);
int					ft_parse_camera(t_camera *scene, char *line);
int					ft_parse_light(t_list **light, char *line);
int					ft_parse_object(t_list **object, char *line);
void				ft_init_vector(t_vector *v, char *line);
char				*ft_get_value(char *line);
#endif
