/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getter_camera.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditsch <aditsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/04 14:52:49 by aditsch           #+#    #+#             */
/*   Updated: 2017/02/04 17:03:37 by aditsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"

t_vector	ft_get_camera_position(t_camera *camera)
{
	return (camera->position);
}

t_vector	ft_get_camera_direction(t_camera *camera)
{
	return (camera->direction);
}

t_vector	ft_get_camera_right(t_camera *camera)
{
	return (camera->right);
}

t_vector	ft_get_camera_down(t_camera *camera)
{
	return (camera->down);
}
