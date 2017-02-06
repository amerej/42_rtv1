/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditsch <aditsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 10:49:00 by aditsch           #+#    #+#             */
/*   Updated: 2017/02/06 14:56:05 by aditsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

# include "vector.h"

typedef struct	s_ray
{
	t_vector	origin;
	t_vector	direction;
}				t_ray;

t_ray			ft_set_ray(t_vector origin, t_vector direction);
t_vector		ft_point_at_parameter(t_ray *ray, double t);
t_vector		ft_get_origin(t_ray *ray);
t_vector		ft_get_direction(t_ray *ray);
#endif
