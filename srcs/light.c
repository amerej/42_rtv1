/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditsch <aditsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 19:24:15 by aditsch           #+#    #+#             */
/*   Updated: 2017/02/14 19:18:57 by aditsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "light.h"

t_color		ft_add_light(t_light *light, t_object *obj)
{
	t_vector	vec;
	t_color		c;
	float		angle;

	vec = ft_sub(obj->inter_p, light->pos);
	ft_normalize(&vec);
	angle = ft_dot(obj->normal, ft_neg(vec));
	if (angle <= 0)
		return ((t_color){0., 0., 0.});
	else
		c = obj->color;
	return (ft_mult_color(ft_mult_color(c, 1.0), angle * light->intensity));
}

void		ft_intersect_light(t_light *light, t_list *objects,
					t_object *closest_obj, int *light_blocked)
{
	t_object	*obj;

	while (objects)
	{
		obj = (t_object *)objects->content;
		if (obj->id != closest_obj->id)
		{
			if (ft_intersect_object(light->ray, obj))
			{
				light->to_intersect_dist = ft_length(ft_sub(obj->inter_p,
					light->pos));
				if (light->to_intersect_dist < light->to_obj_dist)
					*light_blocked = TRUE;
			}
		}
		objects = objects->next;
	}
}

t_color		ft_ray_trace_light(t_list *lights, t_list *objects,
					t_object *closest_obj)
{
	t_vector	vec;
	t_color		color;
	t_light		*light;
	int			light_blocked;

	color = (t_color){0.0, 0.0, 0.0};
	while (lights)
	{
		light = (t_light *)lights->content;
		vec = ft_sub(closest_obj->inter_p, light->pos);
		light->to_obj_dist = ft_length(vec);
		ft_normalize(&vec);
		light->ray.o = light->pos;
		light->ray.dir = vec;
		light_blocked = FALSE;
		ft_intersect_light(light, objects, closest_obj, &light_blocked);
		if (!light_blocked)
			color = ft_add_color(color, ft_add_light(light, closest_obj));
		lights = lights->next;
	}
	return (color);
}
