/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_op2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditsch <aditsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 08:51:41 by aditsch           #+#    #+#             */
/*   Updated: 2017/02/04 12:50:36 by aditsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "vector.h"

t_vector_3	ft_add(t_vector_3 a, t_vector_3 b)
{
	return ((t_vector_3){a.x + b.x, a.y + b.y, a.z + b.z});
}

t_vector_3	ft_sub(t_vector_3 a, t_vector_3 b)
{
	return ((t_vector_3){a.x - b.x, a.y - b.y, a.z - b.z});
}

t_vector_3	ft_mult(t_vector_3 v, double r)
{
	return ((t_vector_3){v.x * r, v.y * r, v.z * r});
}
