/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   class_ray.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditsch <aditsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/04 15:38:54 by aditsch           #+#    #+#             */
/*   Updated: 2017/02/06 15:58:46 by aditsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

t_ray		ft_set_ray(t_vector origin, t_vector direction)
{
	return ((t_ray){origin, direction});
}

t_vector	ft_point_at_parameter(t_ray *ray, double t)
{
	return (ft_add(ray->origin, ft_mult(ray->direction, t)));
}

t_vector	ft_get_origin(t_ray *ray)
{
	return (ray->origin);
}

t_vector	ft_get_direction(t_ray *ray)
{
	return (ray->direction);
}
