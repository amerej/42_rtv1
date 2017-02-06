/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setter_camera.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditsch <aditsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/04 14:52:49 by aditsch           #+#    #+#             */
/*   Updated: 2017/02/06 16:04:00 by aditsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_vector		ft_get_diff_btw(t_vector cam_pos, t_vector look_at)
{
	return ((t_vector){cam_pos.x - look_at.x, cam_pos.y - look_at.y,
		cam_pos.z - look_at.z});
}

// void	ft_set_camera(t_camera *cam)
// {
// 	t_vector_dir	v_dir;
// 	t_vector		diff_btw;
//
// 	v_dir = (t_vector_dir){{1.0, 0.0, 0.0}, {0.0, 1.0, 0.0}, {0.0, 0.0, 1.0}};
// 	cam->look_at = (t_vector){0.0, 0.0, 0.0};
// 	diff_btw = ft_get_diff_btw(cam->position, cam->look_at);
// 	cam->direction = ft_normalize(ft_negative(diff_btw));
// 	cam->right = ft_normalize(ft_cross(v_dir.x, cam->direction));
// 	cam->down = ft_cross(cam->right, cam->direction);
// }
