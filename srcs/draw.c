/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditsch <aditsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 09:21:33 by aditsch           #+#    #+#             */
/*   Updated: 2017/02/09 22:50:42 by aditsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include "ray.h"
#include "intersect.h"
#include "common.h"

static void		ft_put_pixel_img(t_scene *sc, t_point_i p, t_color color)
{
	int	i;

	i = p.x * 4 + p.y * sc->img->size_line;
	sc->img->data[i] = (unsigned char)(255 * (int)color.r);
	sc->img->data[++i] = (unsigned char)(255 * (int)color.g);
	sc->img->data[++i] = (unsigned char)(255 * (int)color.b);
}

int		ft_hit_sphere(t_ray ray, t_object *obj)
{

	obj->oc = ft_sub(ray.origin, obj->pos);
	obj->b = ft_dot(obj->oc, ray.dir);
	obj->c = ft_squared_length(obj->oc) - obj->radius * obj->radius;
	obj->delta = ((obj->b * obj->b) - obj->c);
	if (obj->delta >= 0)
	{
		if (obj->delta != 0)
		{
			obj->delta = (double)sqrt(obj->delta);
			obj->t1 = (-obj->b + obj->delta);
			if (obj->t1 < 0)
				return (FALSE);
			obj->t2 = (-obj->b - obj->delta);
			if (obj->t2 < 0)
				return (FALSE);

			if (obj->t1<obj->t2)
				obj->t = obj->t1;
			else
				obj->t = obj->t2;
		}
		else
			obj->t = (-obj->b);
		obj->inter_data.inter = ft_mult(ft_add(ray.origin, ray.dir), obj->t);
		obj->inter_data.inter = ft_div(ft_sub(obj->inter_data.inter, obj->pos), obj->radius);
		return (TRUE);
	}
	return (FALSE);
}

int			ft_hit_object(t_ray ray, t_object *obj)
{
	if (obj->type == SPHERE)
	{
		if (ft_hit_sphere(ray, obj))
			return (TRUE);
	}
	return (FALSE);
}

t_object	*ft_get_closest_object(t_ray ray, t_list *objects)
{
	t_object	cur_obj;
	t_object	*obj;
	double		dist;
	double		tmp_dist;

	dist = 999999.9;
	obj = NULL;
	while (objects)
	{
		cur_obj = *(t_object *)objects->content;
		if (ft_hit_object(ray, &cur_obj))
		{
			tmp_dist = ft_squared_length(ft_sub(cur_obj.inter_data.inter, ray.origin));
			if (tmp_dist < dist)
			{
				dist = tmp_dist;
				obj = &cur_obj;
			}
		}
		objects = objects->next;
	}
	return (obj);
}

t_color		ft_ray_trace(t_scene *sc, t_ray ray)
{
	t_color		color;
	t_object	*obj;

	color = (t_color){0.0, 0.0, 0.0};
	obj = ft_get_closest_object(ray, sc->objects);
	if (obj)
	{
		color = (t_color){1.0, 1.0, 1.0};
	}
	return (color);
}

static void		ft_draw_img(t_scene *sc)
{
	t_ray		ray;
	t_vector	dir;
	t_point_i	p;

	ft_cam_new(sc->cam);
	p.y = 0;
	while (p.y < sc->height)
	{
		p.x = 0;
		while (p.x < sc->width)
		{
			ray.origin = sc->cam->pos;
			dir = ft_cam_get_dir(sc->cam, p, sc->width, sc->height);
			ft_normalize(&dir);
			ray.dir = dir;
			ft_put_pixel_img(sc, p, ft_ray_trace(sc, ray));
			++p.x;
		}
		++p.y;
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
