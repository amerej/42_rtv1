/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   class_vector.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditsch <aditsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/04 16:20:47 by aditsch           #+#    #+#             */
/*   Updated: 2017/02/06 15:59:17 by aditsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "vector.h"

t_vector	ft_set_vector(double x, double y, double z)
{
	return ((t_vector){x, y, z});
}

double		ft_get_x(t_vector v)
{
	return (v.x);
}

double		ft_get_y(t_vector v)
{
	return (v.y);
}

double		ft_get_z(t_vector v)
{
	return (v.z);
}

double		ft_length(t_vector vec)
{
	return (sqrt(vec.x * vec.x + vec.y * vec.y + vec.z * vec.z));
}

double		ft_squared_length(t_vector vec)
{
	return (vec.x * vec.x + vec.y * vec.y + vec.z * vec.z);
}

void		ft_make_unit_vector(t_vector *vec)
{
	double	factor;

	factor = 1. / ft_length(*vec);
	vec->x *= factor;
	vec->y *= factor;
	vec->z *= factor;
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
