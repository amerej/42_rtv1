/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_op1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditsch <aditsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/04 16:20:47 by aditsch           #+#    #+#             */
/*   Updated: 2017/02/15 20:06:55 by aditsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "vector.h"

double		ft_length(t_vector v)
{
	return (sqrt(v.x * v.x + v.y * v.y + v.z * v.z));
}

double		ft_squared_length(t_vector v)
{
	return (v.x * v.x + v.y * v.y + v.z * v.z);
}

void		ft_normalize(t_vector *v)
{
	double	factor;

	factor = 1. / sqrt(v->x * v->x + v->y * v->y + v->z * v->z);
	v->x *= factor;
	v->y *= factor;
	v->z *= factor;
}

double		ft_dot(t_vector vec_1, t_vector vec_2)
{
	return (vec_1.x * vec_2.x + vec_1.y * vec_2.y + vec_1.z * vec_2.z);
}

t_vector	ft_cross(t_vector vec_1, t_vector vec_2)
{
	return ((t_vector){vec_1.y * vec_2.z - vec_1.z * vec_2.y,
		vec_1.z * vec_2.x - vec_1.x * vec_2.z,
		vec_1.x * vec_2.y - vec_1.y * vec_2.x});
}

t_vector	ft_unit_vector(t_vector v)
{
	return (t_vector)(ft_div(v, ft_length(v)));
}
