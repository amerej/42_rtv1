/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_op1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditsch <aditsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 08:51:41 by aditsch           #+#    #+#             */
/*   Updated: 2017/02/04 19:27:55 by aditsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "vector.h"

double		ft_norm(t_vector v)
{
	return((v.x * v.x) + (v.y * v.y) + (v.z * v.z));
}

double		ft_magnitude(t_vector v)
{
	return (sqrt((v.x * v.x) + (v.y * v.y) + (v.z * v.z)));
}

double		ft_dot(t_vector a, t_vector b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}

t_vector	ft_normalize(t_vector v)
{
	t_vector	normalized;
	double		magnitude;
	double		factor;

	magnitude = sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
	if (magnitude > 0)
	{
		factor = 1 / magnitude;
		normalized.x *= factor;
		normalized.y *= factor;
		normalized.z *= factor;
	}
	return (normalized);
}

t_vector	ft_cross(t_vector a, t_vector b)
{
	return ((t_vector){a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z,
		a.x * b.y - a.y * b.x});
}
