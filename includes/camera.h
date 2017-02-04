/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditsch <aditsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/04 11:51:39 by aditsch           #+#    #+#             */
/*   Updated: 2017/02/04 19:19:02 by aditsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H

# include "vector.h"

typedef struct	s_camera
{
	t_vector	position;
	t_vector	direction;
	t_vector	right;
	t_vector	down;
	t_vector	look_at;
}				t_camera;

void			ft_set_camera(t_camera *cam);

t_vector		ft_get_camera_position(t_camera *camera);
t_vector		ft_get_camera_direction(t_camera *camera);
t_vector		ft_get_camera_right(t_camera *camera);
t_vector		ft_get_camera_down(t_camera *camera);
#endif
