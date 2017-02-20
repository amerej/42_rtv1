/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_sphere.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditsch <aditsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 13:31:44 by aditsch           #+#    #+#             */
/*   Updated: 2017/02/20 13:39:22 by aditsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"

static void		ft_compute_delta_sphere(t_ray ray, t_object *obj, t_op *op)
{
	op->a = ft_dot(ray.dir, ray.dir);
	op->b = ft_dot(ray.dir, op->x) * 2.0;
	op->c = ft_dot(op->x, op->x) - (obj->radius * obj->radius);
	op->delta = (op->b * op->b) - (4 * op->a * op->c);
}

int				ft_intersect_sphere(t_ray ray, t_object *obj)
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
