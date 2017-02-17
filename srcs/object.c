/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditsch <aditsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 19:19:33 by aditsch           #+#    #+#             */
/*   Updated: 2017/02/17 11:55:18 by aditsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"
#include "float.h"

int			ft_intersect_sphere(t_ray ray, t_object *obj)
{
	double		a;
	double		b;
	double		c;
	double		t1;
	double		t2;
	double		t;
	double		delta;
	t_vector	x;

	x = ft_sub(ray.o, obj->pos);
	a = ft_dot(ray.dir, ray.dir);
	b = ft_dot(ray.dir, x) * 2.0;
	c = ft_dot(x, x) - (obj->radius * obj->radius);
	delta = (b * b) - (4 * a * c);
	if (delta >= 0)
	{
		t1 = (-b + sqrt(delta)) / (2 * a);
		t2 = (-b - sqrt(delta)) / (2 * a);
		t = (t1 < t2) ? t1 : t2;
		obj->intersection = ft_add(ray.o, ft_mult(ray.dir, t));
		obj->normal = ft_unit_vector(ft_add(ft_mult(ray.dir, t), x));
		return (TRUE);
	}
	return (FALSE);
}

int			ft_intersect_plane(t_ray ray, t_object *obj)
{
	t_vector	v;
	t_vector	d;
	t_vector	x;
	double		dv;
	double		xv;
	double		t;

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
	obj->intersection = ft_add(ray.o, ft_mult(d, t));
	obj->normal = (dv < 0) ? v : ft_neg(v);
	return (TRUE);
}

int			ft_intersect_cylinder(t_ray ray, t_object *obj)
{
	double		a;
	double		b;
	double		c;
	double		t1;
	double		t2;
	double		t;
	double		delta;
	t_vector	x;
	t_vector	v;
	double		dv;
	double		xv;
	double		m;

	v = ft_unit_vector(obj->rot);
	dv = ft_dot(ray.dir, v);
	x = ft_sub(ray.o, obj->pos);
	xv = ft_dot(x, v);
	a = ft_dot(ray.dir, ray.dir) - (dv * dv);
	b = (ft_dot(ray.dir, x) - (dv * xv)) * 2.0;
	c = ft_dot(x, x) - (xv * xv) - (obj->radius * obj->radius);
	delta = (b * b) - (4 * a * c);
	if (delta >= 0)
	{
		t1 = (-b + sqrt(delta)) / (2 * a);
		t2 = (-b - sqrt(delta)) / (2 * a);
		t = (t1 < t2) ? t1 : t2;
		obj->intersection = ft_add(ray.o, ft_mult(ray.dir, t));
		m = ft_dot(ray.dir, ft_mult(v, t)) + ft_dot(x, v);
		if (m >= 0 && m <= obj->length)
			obj->normal = ft_unit_vector(ft_sub(ft_add(ft_mult(ray.dir, t), x), ft_mult(v, m)));
		else
			return (FALSE);
		return (TRUE);
	}
	return (FALSE);
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
	if (obj->type == CYLINDER)
	{
		if (ft_intersect_cylinder(ray, obj))
			return (TRUE);
	}
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
	double		dist;
	double		tmp_dist;

	dist = DBL_MAX;
	obj = NULL;
	while (objects)
	{
		i_obj = (t_object *)objects->content;
		if (ft_intersect_object(ray, i_obj))
		{
			tmp_dist = ft_squared_length(ft_sub(i_obj->intersection, ray.o));
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
