/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditsch <aditsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 19:19:33 by aditsch           #+#    #+#             */
/*   Updated: 2017/02/20 12:06:55 by aditsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"
#include "float.h"

void		ft_compute_delta_sphere(t_ray ray, t_object *obj, t_op *op)
{
	op->a = ft_dot(ray.dir, ray.dir);
	op->b = ft_dot(ray.dir, op->x) * 2.0;
	op->c = ft_dot(op->x, op->x) - (obj->radius * obj->radius);
	op->delta = (op->b * op->b) - (4 * op->a * op->c);
}

void		ft_get_distance(t_op *op)
{
	op->t1 = (-op->b + sqrt(op->delta)) / (2 * op->a);
	op->t2 = (-op->b - sqrt(op->delta)) / (2 * op->a);
	op->t = (op->t1 < op->t2) ? op->t1 : op->t2;
}

int			ft_intersect_sphere(t_ray ray, t_object *obj)
{
	t_op	op;

	op.x = ft_sub(ray.o, obj->pos);
	ft_compute_delta_sphere(ray, obj, &op);
	if (op.delta >= 0)
	{
		ft_get_distance(&op);
		obj->intersection = ft_add(ray.o, ft_mult(ray.dir, op.t));
		obj->normal = ft_unit_vector(ft_add(ft_mult(ray.dir, op.t), op.x));
		return (TRUE);
	}
	return (FALSE);
}

int			ft_intersect_plane(t_ray ray, t_object *obj)
{
	t_op	op;

	op.d = ray.dir;
	op.v = ft_unit_vector(obj->rot);
	op.x = ft_sub(ray.o, obj->pos);
	op.dv = ft_dot(op.d, op.v);
	if (op.dv == 0)
		return (FALSE);
	op.xv = ft_dot(op.x, op.v);
	op.t = -op.xv / op.dv;
	if (op.t < 0)
		return (FALSE);
	obj->intersection = ft_add(ray.o, ft_mult(op.d, op.t));
	obj->normal = (op.dv < 0) ? op.v : ft_neg(op.v);
	return (TRUE);
}

void		ft_compute_delta_cylinder(t_ray ray, t_object *obj, t_op *op)
{
	op->a = ft_dot(ray.dir, ray.dir);
	op->b = ft_dot(ray.dir, op->x) * 2.0;
	op->c = ft_dot(op->x, op->x) - (obj->radius * obj->radius);
	op->delta = (op->b * op->b) - (4 * op->a * op->c);
}

int			ft_intersect_cylinder(t_ray ray, t_object *obj)
{
	// double		a;
	// double		b;
	// double		c;
	double		t1;
	double		t2;
	double		t;
	// double		delta;
	t_vector	x;
	t_vector	v;
	double		dv;
	double		xv;
	double		m;

	op.v = ft_unit_vector(obj->rot);
	dv = ft_dot(ray.dir, v);
	x = ft_sub(ray.o, obj->pos);
	xv = ft_dot(x, v);
	// a = ft_dot(ray.dir, ray.dir) - (dv * dv);
	// b = (ft_dot(ray.dir, x) - (dv * xv)) * 2.0;
	// c = ft_dot(x, x) - (xv * xv) - (obj->radius * obj->radius);
	// delta = (b * b) - (4 * a * c);
	if (delta >= 0)
	{
		t1 = (-b + sqrt(delta)) / (2 * a);
		t2 = (-b - sqrt(delta)) / (2 * a);
		t = (t1 < t2) ? t1 : t2;
		obj->intersection = ft_add(ray.o, ft_mult(ray.dir, t));
		m = ft_dot(ray.dir, ft_mult(v, t)) + ft_dot(x, v);
		obj->normal = ft_unit_vector(ft_sub(ft_add(ft_mult(ray.dir, t), x), ft_mult(v, m)));
		return (TRUE);
	}
	return (FALSE);
}

int			ft_intersect_cone(t_ray ray, t_object *obj)
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
	a = ft_dot(ray.dir, ray.dir) - ((1 + obj->radius * obj->radius) * (dv * dv));
	b = (ft_dot(ray.dir, x) - ((1 + obj->radius * obj->radius) * (dv * xv))) * 2.0;
	c = ft_dot(x, x) - ((1 + obj->radius * obj->radius) * (xv * xv));
	delta = (b * b) - (4 * a * c);
	if (delta >= 0)
	{
		t1 = (-b + sqrt(delta)) / (2 * a);
		t2 = (-b - sqrt(delta)) / (2 * a);
		t = (t1 < t2) ? t1 : t2;
		obj->intersection = ft_add(ray.o, ft_mult(ray.dir, t));
		m = ft_dot(ray.dir, v) * t + ft_dot(x, v);
		obj->normal = ft_unit_vector(ft_sub(ft_add(ft_mult(ray.dir, t), x), ft_mult(ft_mult(v, 1 + obj->radius * obj->radius), m)));
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
	if (obj->type == CONE)
	{
		if (ft_intersect_cone(ray, obj))
	 		return (TRUE);
	}
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
