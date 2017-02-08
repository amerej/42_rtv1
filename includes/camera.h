/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditsch <aditsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/04 11:51:39 by aditsch           #+#    #+#             */
/*   Updated: 2017/02/08 19:09:17 by aditsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAM_H
# define CAM_H

# include "vector.h"

typedef struct	s_cam
{
	t_vector	pos;
	t_vector	dir;
	t_vector	up;
	t_vector	right;
	t_vector	vp_up_left;
	double		vp_dist;
	double		vp_height;
	double		vp_width;
}				t_cam;

t_vector		ft_cam_get_dir(t_point_d p, t_point_i res);
#endif
