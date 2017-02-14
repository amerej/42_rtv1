/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditsch <aditsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 19:19:33 by aditsch           #+#    #+#             */
/*   Updated: 2017/02/14 22:35:10 by aditsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"

int				ft_intersect_sphere(t_ray ray, t_object *obj)
{
	obj->oc = ft_sub(ray.o, obj->pos);
	obj->b = ft_dot(obj->oc, ray.dir);
	obj->c = ft_squared_length(obj->oc) - (obj->radius * obj->radius);
	obj->delta = ((obj->b * obj->b) - obj->c);
	if (obj->delta >= 0)
	{
		if (obj->delta != 0)
		{
			obj->delta = (float)sqrt(obj->delta);
			obj->t1 = (-obj->b + obj->delta);
			if (obj->t1 < 0)
				return (FALSE);
			obj->t2 = (-obj->b - obj->delta);
			if (obj->t2 < 0)
				return (FALSE);
			obj->t = (obj->t1 < obj->t2) ? obj->t1 : obj->t2;
		}
		else
			obj->t = (-obj->b);
		obj->inter_p = ft_add(ray.o, ft_mult(ray.dir, obj->t));
		obj->normal = ft_div(ft_sub(obj->inter_p, obj->pos), obj->radius);
		return (TRUE);
	}
	return (FALSE);
}

/*
**	Ray
**	p = o + d * t
**
**	Plane Intersect
**	t = -x|v / d|v
**
**	x = ft_sub(ray.o, obj->pos)
**	v = ft_unit_vector(obj->rot)
**	d = ray.dir
**	dv = ft_dot(d, v)
**	xv = ft_dot(x, v)
**	t = (-xv) / dv
*/

int			ft_intersect_plane(t_ray ray, t_object *obj)
{
	t_vector	v;
	t_vector	d;
	t_vector	x;
	float		dv;
	float		xv;
	float		t;

	d = ray.dir;
	v = ft_unit_vector(obj->rot);
	x = ft_sub(ray.o, obj->pos);
	dv = ft_dot(d, v);
	if (dv == 0)
		return (FALSE);
	xv = ft_dot(x, v);
	t = -xv / dv;
	if (t < 0)
		return (FALSE);
	obj->inter_p = ft_add(ray.o, ft_mult(d, t));
	obj->normal = (dv < 0) ? v : ft_neg(v);
	return (TRUE);
}

int			ft_intersect_object(t_ray ray, t_object *obj)
{
	if (obj->type == SPHERE)
	{
		if (ft_intersect_sphere(ray, obj))
			return (TRUE);
	}
	if (obj->type == PLANE)
	{
		if (ft_intersect_plane(ray, obj))
			return (TRUE);
	}
	// if (obj->type == CYLINDER)
	// {
	// 	if (ft_intersect_sphere(ray, obj))
	// 		return (TRUE);
	// }
	// if (obj->type == CONE)
	// {
	// 	if (ft_intersect_sphere(ray, obj))
	// 		return (TRUE);
	// }
	return (FALSE);
}

t_object	*ft_get_closest_object(t_ray ray, t_list *objects)
{
	t_object	*i_obj;
	t_object	*obj;
	float		dist;
	float		tmp_dist;

	dist = 999999.9;
	obj = NULL;
	while (objects)
	{
		i_obj = (t_object *)objects->content;
		if (ft_intersect_object(ray, i_obj))
		{
			tmp_dist = ft_squared_length(ft_sub(i_obj->inter_p, ray.o));
			if (tmp_dist < dist)
			{
				dist = tmp_dist;
				obj = i_obj;
			}
		}
		objects = objects->next;
	}
	return (obj);
}
