/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setter_ray.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditsch <aditsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/04 16:20:47 by aditsch           #+#    #+#             */
/*   Updated: 2017/02/04 17:12:00 by aditsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

t_ray		ft_set_ray(t_vector origin, t_vector direction)
{
	return ((t_ray){origin, direction});
}
