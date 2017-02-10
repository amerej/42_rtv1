/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditsch <aditsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 09:21:33 by aditsch           #+#    #+#             */
/*   Updated: 2017/02/10 19:38:34 by aditsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include "ray.h"
#include "intersect.h"
#include "common.h"
#include "color.h"

static void		ft_put_pixel_img(t_scene *sc, t_point_i p, t_color color)
{
	int	i;

	i = p.x * 4 + p.y * sc->img->size_line;
	sc->img->data[i] = (unsigned char)(color.b * 255);
	sc->img->data[++i] = (unsigned char)(color.g * 255);
	sc->img->data[++i] = (unsigned char)(color.r * 255);
}

int		ft_hit_sphere(t_ray ray, t_object *obj)
{

	obj->oc = ft_sub(ray.origin, obj->pos);
	obj->b = ft_dot(obj->oc, ray.dir);
	obj->c = ft_squared_length(obj->oc) - (obj->radius * obj->radius);
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

			if (obj->t1 < obj->t2)
				obj->t = obj->t1;
			else
				obj->t = obj->t2;
		}
		else
			obj->t = (-obj->b);
		obj->inter_data.inter = ft_add(ray.origin, ft_mult(ray.dir, obj->t));
		obj->inter_data.normal = ft_div(ft_sub(obj->inter_data.inter, obj->pos), obj->radius);
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
	t_object	*cur_obj;
	t_object	*obj;
	double		dist;
	double		tmp_dist;

	dist = 999999.9;
	obj = NULL;
	while (objects)
	{
		cur_obj = (t_object *)objects->content;
		if (ft_hit_object(ray, cur_obj))
		{
			tmp_dist = ft_squared_length(ft_sub(cur_obj->inter_data.inter,
				ray.origin));
			if (tmp_dist < dist)
			{
				dist = tmp_dist;
				obj = cur_obj;
			}
		}
		objects = objects->next;
	}
	return (obj);
}

t_color		ft_get_light(t_light *light, t_object *obj)
{
	t_vector	v_light;
	double		angle;
	t_color		color;

	v_light = ft_sub(obj->inter_data.inter, light->position);
	ft_normalize(&v_light);
	angle = ft_dot(obj->inter_data.normal, ft_negative(v_light));
	if (angle <= 0)
		color = (t_color){0.0, 0.0, 0.0};
	else
	{
		color = ft_mult_color(ft_mult_color(obj->color, 1.0), angle);
		// printf("get_light = %lf, %lf, %lf\n", color.r, color.g, color.b);
	}
	return (color);
}

t_color		ft_ray_trace(t_scene *sc, t_ray ray)
{
	t_color		color;
	t_object	*obj;
	t_vector	v_light;
	t_light		*light;
	double		light_to_obj_dist;
	double		light_to_inter_dist;
	t_ray		light_ray;
	t_list		*iter_list = sc->lights;

	color = (t_color){0.0, 0.0, 0.0};
	obj = ft_get_closest_object(ray, sc->objects);
	if (obj)
	{
		while (iter_list)
		{
			light = ((t_list *)iter_list)->content;
			v_light = ft_sub(light->position, obj->inter_data.inter);
			light_to_obj_dist = ft_length(v_light);
			ft_normalize(&v_light);
			// printf("%lf, %lf, %lf\n", obj->color.r, obj->color.g, obj->color.b);
			color = ft_get_light(light, obj);
			// printf("%lf, %lf, %lf\n", color.r, color.g, color.b);
			iter_list = iter_list->next;
		}
		color = ft_add_color(obj->color, color);
		// printf("%lf, %lf, %lf\n", color.r, color.g, color.b);
	}
	// ft_normalize_color(&color);
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
