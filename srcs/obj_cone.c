/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_cone.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditsch <aditsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 13:34:17 by aditsch           #+#    #+#             */
/*   Updated: 2017/02/20 13:41:48 by aditsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"

static void		ft_compute_delta_cone(t_ray ray, t_object *obj, t_op *op)
{
	op->v = ft_unit_vector(obj->rot);
	op->dv = ft_dot(ray.dir, op->v);
	op->x = ft_sub(ray.o, obj->pos);
	op->xv = ft_dot(op->x, op->v);
	op->a = ft_dot(ray.dir, ray.dir) - ((1 + obj->radius * obj->radius) *
		(op->dv * op->dv));
	op->b = (ft_dot(ray.dir, op->x) - ((1 + obj->radius * obj->radius) *
		(op->dv * op->xv))) * 2.0;
	op->c = ft_dot(op->x, op->x) - ((1 + obj->radius * obj->radius) *
		(op->xv * op->xv));
	op->delta = (op->b * op->b) - (4 * op->a * op->c);
}

int				ft_intersect_cone(t_ray ray, t_object *obj)
{
	t_op	op;

	ft_compute_delta_cone(ray, obj, &op);
	if (op.delta >= 0)
	{
		ft_get_distance(&op);
		obj->intersection = ft_add(ray.o, ft_mult(ray.dir, op.t));
		op.m = ft_dot(ray.dir, op.v) * op.t + ft_dot(op.x, op.v);
		obj->normal = ft_unit_vector(ft_sub(ft_add(
			ft_mult(ray.dir, op.t), op.x), ft_mult(
				ft_mult(op.v, 1 + obj->radius * obj->radius), op.m)));
		return (TRUE);
	}
	return (FALSE);
}
