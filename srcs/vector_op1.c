/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_op1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditsch <aditsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 08:51:41 by aditsch           #+#    #+#             */
/*   Updated: 2017/02/04 15:48:09 by aditsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "vector.h"

double	ft_norm(t_vector v)
{
	return((v.x * v.x) + (v.y * v.y) + (v.z * v.z));
}

double	ft_magnitude(t_vector v)
{
	return (sqrt((v.x * v.x) + (v.y * v.y) + (v.z * v.z)));
}

double	ft_dot(t_vector a, t_vector b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}

t_vector	ft_normalize(void)
{
	t_vector	v;
	double	magnitude;
	double	factor;

	magnitude = sqrt((v.x * v.x) + (v.y * v.y) + (v.z * v.z));
	if (magnitude > 0)
	{
		factor = 1 / magnitude;
		v.x *= factor;
		v.y *= factor;
		v.z *= factor;
	}
	return (v);
}

t_vector	ft_cross(t_vector a, t_vector b)
{
	return ((t_vector){a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z,
		a.x * b.y - a.y * b.x});
}
