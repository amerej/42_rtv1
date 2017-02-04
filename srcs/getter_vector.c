/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getter_vector.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditsch <aditsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/04 15:38:54 by aditsch           #+#    #+#             */
/*   Updated: 2017/02/04 17:05:57 by aditsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

double	ft_get_vector_x(t_vector v)
{
	return (v.x);
}

double	ft_get_vector_y(t_vector v)
{
	return (v.y);
}

double	ft_get_vector_z(t_vector v)
{
	return (v.z);
}
