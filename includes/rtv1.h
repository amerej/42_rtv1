/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditsch <aditsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 17:37:31 by aditsch           #+#    #+#             */
/*   Updated: 2017/02/20 15:23:47 by aditsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H

# include <math.h>
# include "../libft/libft.h"
# include "../minilibx/osx/mlx.h"
# include "keycode_osx.h"
# include "parser.h"
# include "image.h"
# include "vector.h"
# include "camera.h"
# include "color.h"
# include "light.h"

typedef struct		s_scene
{
	void			*mlx;
	void			*win;
	t_img			*img;
	int				width;
	int				height;
	t_cam			*cam;
	t_list			*objects;
	t_list			*lights;
}					t_scene;

t_scene				*ft_new_scene(int fd);
void				ft_destroy_scene(t_scene *sc);
void				ft_draw_window(t_scene *sc);
int					ft_expose_hook(t_scene *sc);
int					ft_key_hook(int keycode, t_scene *sc);
int					ft_parse_scene(t_scene *sc, int fd);
int					ft_parse_render(t_scene *sc, char *line);
int					ft_parse_camera(t_scene *sc, char *line);
int					ft_parse_light(t_list **lights, char *line);
int					ft_parse_object(t_list **objects, char *line);
int					ft_init_vector(t_vector *v, char *line);
#endif
