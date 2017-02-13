/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditsch <aditsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 19:19:33 by aditsch           #+#    #+#             */
/*   Updated: 2017/02/13 20:37:39 by aditsch          ###   ########.fr       */
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

			if (obj->t1 < obj->t2)
				obj->t = obj->t1;
			else
				obj->t = obj->t2;
		}
		else
			obj->t = (-obj->b);
		obj->inter_p = ft_add(ray.o, ft_mult(ray.dir, obj->t));
		obj->normal = ft_div(ft_sub(obj->inter_p, obj->pos), obj->radius);
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
	// if (obj->type == PLANE)
	// {
	// 	if (ft_intersect_sphere(ray, obj))
	// 		return (TRUE);
	// }
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
