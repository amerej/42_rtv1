/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditsch <aditsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/04 11:51:39 by aditsch           #+#    #+#             */
/*   Updated: 2017/02/16 17:10:06 by aditsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHT_H
# define LIGHT_H

# include "rtv1.h"
# include "object.h"
# include "vector.h"
# include "ray.h"
# include "color.h"

typedef struct	s_light
{
	t_vector	pos;
	t_vector	dir;
	t_ray		ray;
	double		to_obj_dist;
	double		to_intersect_dist;
}				t_light;

t_color			ft_add_light(t_light *light, t_object *obj);
void			ft_intersect_light(t_light *light, t_list *objects,
					t_object *closest_obj, int *light_blocked);
t_color			ft_ray_trace_light(t_list *lights, t_list *objects,
					t_object *closest_obj);
#endif
