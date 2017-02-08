/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditsch <aditsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 09:21:33 by aditsch           #+#    #+#             */
/*   Updated: 2017/02/08 20:28:43 by aditsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include "ray.h"

static void		ft_put_pixel_img(t_scene *sc, t_point_i p, t_color color)
{
	int	i;

	i = p.x * 4 + p.y * sc->img->size_line;
	sc->img->data[i] = (unsigned char)(255 * color.r);
	sc->img->data[++i] = (unsigned char)(255 * color.g);
	sc->img->data[++i] = (unsigned char)(255 * color.b);
}

double		ft_hit_sphere(t_vector center, double radius, t_ray ray)
{
	t_vector	oc;
	double		a;
	double		b;
	double		c;
	double		discriminant;

	oc = ft_sub(ray.origin, center);
	a = ft_dot(ray.direction, ray.direction);
	b = 2.0 * ft_dot(oc, ray.direction);
	c = ft_dot(oc, oc) - radius * radius;
	discriminant = b * b - 4 * a * c;
	if (discriminant < 0)
		return (-1.0);
	else
		return ((-b - sqrt(discriminant)) / (2.0 * a));
}

t_vector	ft_ray_trace(t_scene *sc, t_ray ray)
{
	double		t;
	t_vector	unit_direction;
	t_vector	n;
	t = ft_hit_sphere((t_vector){0.0, 0.0, -1.0}, 0.5, ray);
	if (t > 0.0)
	{
		n = ft_unit_vector(ft_sub(ft_point_at_parameter(&ray, t),
			(t_vector){0.0, 0.0, -1.0}));
		return ((t_vector){0.5 * (n.x + 1), 0.5 * (n.y + 1), 0.5 * (n.z + 1)});
	}
	unit_direction = ft_unit_vector(ray.direction);
	t = 0.5 * (unit_direction.y + 1.0);
	// return (ft_add(
	// 	ft_mult((t_vector){1.0, 1.0, 1.0}, 1.0 - t),
	// 	ft_mult((t_vector){0.5, 0.7, 1.0}, t)));
	return((t_vector){0.0, 0.0, 0.0});
}

static void		ft_draw_img(t_scene *sc)
{
	t_ray		ray;
	t_vector	vec_dir;
	int			color;
	t_point_i	p;

	p.y = 0;
	while (point.y < sc->height)
	{
		p.x = 0;
		while (point.x < sc->width)
		{
			ray->origin = sc->cam->pos;
			vec_dir = ft_get_cam_dir(sc->cam, p.x, p.y, sc->width, sc->height);
			ft_normalize(&vec_dir);
			ray->dir = vec_dir;
			ft_put_pixel_img(sc, point, ft_ray_trace(sc, ray));
			++point.x;
		}
		++point.y;
	}
}

void	ft_draw_window(t_scene *sc)
{
	sc->img->img_ptr = mlx_new_image(sc->mlx, sc->width, sc->height);
	sc->img->data = mlx_get_data_addr(sc->img->img_ptr,
		&(sc->img->bpp), &(sc->img->size_line), &(sc->img->endian));
	ft_draw_img(sc);
	mlx_put_image_to_window(sc->mlx, sc->win, sc->img->img_ptr, 0, 0);
	mlx_destroy_image(sc->mlx, sc->img->img_ptr);
}
