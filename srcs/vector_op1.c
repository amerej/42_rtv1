/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_op1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditsch <aditsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 08:51:41 by aditsch           #+#    #+#             */
/*   Updated: 2017/02/04 12:55:03 by aditsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "vector.h"

double	ft_norm(t_vector_3 v)
{
	return(v.x * v.x + v.y * v.y + v.z * v.z);
}

double	ft_length(t_vector_3 v)
{
	return (sqrt(ft_norm(v)));
}

double	ft_dot(t_vector_3 a, t_vector_3 b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}

t_vector_3	ft_normalize(void)
{
	t_vector_3	v;
	double	n;
	double	factor;

	n = ft_norm(v);
	if (n > 0)
	{
		factor = 1 / sqrt(n);
		v.x *= factor;
		v.y *= factor;
		v.z *= factor;
	}
	return (v);
}

t_vector_3	ft_cross(t_vector_3 a, t_vector_3 b)
{
	return ((t_vector_3){a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z,
		a.x * b.y - a.y * b.x});
}
