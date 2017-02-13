/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_op2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditsch <aditsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/04 16:20:47 by aditsch           #+#    #+#             */
/*   Updated: 2017/02/13 17:11:42 by aditsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "vector.h"

t_vector	ft_neg(t_vector v)
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

t_vector	ft_mult(t_vector v, float r)
{
	return ((t_vector){v.x * r, v.y * r, v.z * r});
}

t_vector	ft_div(t_vector v, float r)
{
	return ((t_vector){v.x / r, v.y / r, v.z / r});
}
