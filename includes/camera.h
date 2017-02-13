/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditsch <aditsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/04 11:51:39 by aditsch           #+#    #+#             */
/*   Updated: 2017/02/13 20:33:26 by aditsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAM_H
# define CAM_H

# include "vector.h"
# include "common.h"

typedef struct	s_cam
{
	t_vector	pos;
	t_vector	look_at;
	t_vector	up;
	t_vector	right;
	t_vector	vp_up_left;
	float		vp_dist;
	float		vp_height;
	float		vp_width;
}				t_cam;

void			ft_cam_new(t_cam *cam);
t_vector		ft_cam_get_dir(t_cam *cam, t_point_i p, int width, int height);
#endif
