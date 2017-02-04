/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getter_vector.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditsch <aditsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/04 15:38:54 by aditsch           #+#    #+#             */
/*   Updated: 2017/02/04 18:26:28 by aditsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

double	ft_get_x(t_vector v)
{
	return (v.x);
}

double	ft_get_y(t_vector v)
{
	return (v.y);
}

double	ft_get_z(t_vector v)
{
	return (v.z);
}
