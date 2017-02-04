/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditsch <aditsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 09:21:33 by aditsch           #+#    #+#             */
/*   Updated: 2017/02/04 18:16:23 by aditsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void		ft_put_pixel_img(t_app *app, t_vector *p, int color)
{
	int	i;

	i = ((int)p->x * 4) + ((int)p->y * app->scene->image->size_line);
	app->scene->image->data[i] = color;
	app->scene->image->data[++i] = color >> 8;
	app->scene->image->data[++i] = color >> 16;
}

static void		ft_draw_img(t_app *app)
{
	t_vector		point;
	t_camera		*cam;
	t_vector_dir	v_dir;

	cam = app->scene->camera;
	v_dir = (t_vector_dir){{1.0, 0.0, 0.0}, {0.0, 1.0, 0.0}, {0.0, 0.0, 1.0}};
	cam->look_at = (t_vector){0.0, 0.0, 0.0};

	point.y = 0.0;
	while (point.y < app->scene->height)
	{
		point.x = 0.0;
		while (point.x < app->scene->width)
		{
			ft_put_pixel_img(app, &point, 0x00ffff00);
			++point.x;
		}
		++point.y;
	}
}

void	ft_draw_window(t_app *app)
{
	app->scene->image->img_ptr = mlx_new_image(app->mlx,
		app->scene->width, app->scene->height);
	app->scene->image->data = mlx_get_data_addr(app->scene->image->img_ptr,
		&(app->scene->image->bpp),
		&(app->scene->image->size_line),
		&(app->scene->image->endian));
	ft_draw_img(app);
	mlx_put_image_to_window(app->mlx, app->win,
		app->scene->image->img_ptr, 0, 0);
	mlx_destroy_image(app->mlx, app->scene->image->img_ptr);
}
