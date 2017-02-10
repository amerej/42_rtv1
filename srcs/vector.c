/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditsch <aditsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/04 16:20:47 by aditsch           #+#    #+#             */
/*   Updated: 2017/02/10 15:55:08 by aditsch          ###   ########.fr       */
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

t_vector		ft_unit_vector(t_vector vec)
{
	double	length;

	length = ft_length(vec);
	return ((t_vector){vec.x / length, vec.y / length, vec.z / length});
}

t_vector	ft_negative(t_vector v)
{
	return ((t_vector){-v.x, -v.y, -v.z});
}

t_vector	ft_add(t_vector a, t_vector b)
{
	return ((t_vector){a.x + b.x, a.y + b.y, a.z + b.z});
}

t_vector	ft_sub(t_vector a, t_vector b)
{
	return ((t_vector){a.x - b.x, a.y - b.y, a.z - b.z});
}

t_vector	ft_mult(t_vector v, double r)
{
	return ((t_vector){v.x * r, v.y * r, v.z * r});
}

t_vector	ft_div(t_vector v, double r)
{
	return ((t_vector){v.x / r, v.y / r, v.z / r});
}
