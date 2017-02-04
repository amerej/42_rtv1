/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setter_camera.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditsch <aditsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/04 14:52:49 by aditsch           #+#    #+#             */
/*   Updated: 2017/02/04 17:00:33 by aditsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_camera	ft_set_camera(t_vector position, t_vector direction,
				t_vector right, t_vector down)
{
	return ((t_camera){position, direction, right, down});
}
