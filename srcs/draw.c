/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditsch <aditsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 09:21:33 by aditsch           #+#    #+#             */
/*   Updated: 2017/02/09 18:09:08 by aditsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include "ray.h"
#include "intersect.h"

static void		ft_put_pixel_img(t_scene *sc, t_point_i p, t_color color)
{
	int	i;

	i = p.x * 4 + p.y * sc->img->size_line;
	sc->img->data[i] = (unsigned char)(255 * (int)color.r);
	sc->img->data[++i] = (unsigned char)(255 * (int)color.g);
	sc->img->data[++i] = (unsigned char)(255 * (int)color.b);
}

double		ft_hit_sphere(t_ray ray, t_object *sphere)
{
	obj->oc = ft_sub(ray.origin, obj->pos);
	obj->b = ft_dot(obj->oc, ray.dir);
	obj->c = ft_squared_length(obj->oc) - obj->radius * obj->radius;
	obj->delta = ((b * b) - c);
	if (obj->delta >= 0)
	{
		if (obj->delta != 0)
		{
			obj->delta = (float)sqrt(obj->delta);
			obj->t1 = (-obj->b + obj->delta); if (obj->t1<0) return false;
			obj->t2 = (-obj->b - obj->delta); if (obj->t2<0) return false;

			if (t1<t2)
				t = t1;
			else
				t = t2;
		}

		else
			t = (-b);
		}
	}


}

int			ft_hit_object(t_ray *ray, t_object *obj)
{
	if (obj->type == SPHERE)
	{
		ft_hit_sphere(ray, obj);
		return (TRUE);
	}
	// else if (obj->type == PLANE)
	// {
	// 	ft_hit_plane(ray, obj);
	// 	return (TRUE);
	// }
	return (FALSE);
}

t_object	ft_get_closest_object(t_ray ray, t_list *objects)
{
	t_object	*cur_obj;
	t_object	*obj;
	double		dist;
	double		tmp_dist;

	dist = MAX_DOUBLE;
	obj = NULL;
	while (objects)
	{
		cur_obj = ((t_object *)objects)->content;
		if (ft_hit_object(ray, cur_obj))
			tmp_dist = ft_squared_length(ft_sub(cur_obj->inter_data.inter, ray.origin));
			if (tmp_dist < dist)
			{
				dist = tmp_dist;
				obj = cur_obj;
			}
		objects = objects->next;
	}
	return (obj);
}

t_color		ft_ray_trace(t_scene *sc, t_ray ray)
{
	t_object			obj;
	t_color				color;

	color = (t_color){0.0, 0.0, 0.0};
	if ((obj = ft_get_closest_object(ray, sc->objects)))
	{
		// Parcours des lumieres
	}

}

static void		ft_draw_img(t_scene *sc)
{
	t_ray		ray;
	t_vector	vec_dir;
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
