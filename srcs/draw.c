/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditsch <aditsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 09:21:33 by aditsch           #+#    #+#             */
/*   Updated: 2017/02/06 17:23:55 by aditsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include "ray.h"

static void		ft_put_pixel_img(t_app *app, t_vector point, t_vector color)
{
	int	i;

	i = ((int)point.x * 4) + (((int)(app->scene->height - 1) - ((int)point.y)) * app->scene->image->size_line);
	app->scene->image->data[i] = (int)(255.99 * color.z);
	app->scene->image->data[++i] = (int)(255.99 * color.y);
	app->scene->image->data[++i] = (int)(255.99 * color.x);
}

t_vector	ft_color(t_ray ray)
{
	double		t;
	t_vector	unit_direction;

	unit_direction = ft_unit_vector(ray.direction);
	t = 0.5 * (unit_direction.y + 1.0);
	return (ft_add(
		ft_mult((t_vector){1.0, 1.0, 1.0}, 1.0 - t), ft_mult((t_vector){0.5, 0.7, 1.0}, t)));
}

static void		ft_draw_img(t_app *app)
{
	t_vector	point;
	t_vector	lower_left_corner;
	t_vector	horizontal;
	t_vector	vertical;
	t_vector	origin;
	t_ray		ray;
	double		u;
	double		v;

	lower_left_corner = (t_vector){-2.0, -1.0, -1.0};
	horizontal = (t_vector){4.0, 0.0, 0.0};
	vertical = (t_vector){0.0, 2.0, 0.0};
	origin = (t_vector){0.0, 0.0, 0.0};

	point.y = 0.0;
	while (point.y < app->scene->height)
	{
		point.x = 0.0;
		while (point.x < app->scene->width)
		{
			u = point.x / app->scene->width;
			v = point.y / app->scene->height;
			ray = ft_set_ray(origin,
				ft_add(ft_add(lower_left_corner,
					ft_mult(horizontal, u)), ft_mult(vertical, v)));
			ft_put_pixel_img(app, point, ft_color(ray));
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
