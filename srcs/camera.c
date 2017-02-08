/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditsch <aditsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/04 14:52:49 by aditsch           #+#    #+#             */
/*   Updated: 2017/02/08 17:24:29 by aditsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"

void			ft_cam_new(t_cam *cam, t_vector cam_pos, t_vector cam_up_vec)
{
	cam->pos = cam_pos;
	cam->up = cam_up_vec;
	cam->vp_dist = 1.0;
	cam->vp_height = 0.35;
	cam->vp_width = 0.5;
}

t_vector		ft_cam_get_dir(t_cam *cam, t_point_d p, t_point_i res)
{
	double		x_indent;
	double		y_indent;
	t_vector	right;
	t_vector	up;
	t_vector	vp_up_left;
	t_vector	dir;

	x_indent = cam->vp_width / (double)res.x;
	y_indent = cam->vp_height / (double)res.y;
	right = ft_mult(ft_mult(cam->right, x_indent), p.x);
	up_vec = ft_mult(ft_mult(cam->up, y_indent), p.y);
	vp_up_left = ft_add(cam->vp_up_left, ft_sub(right, up));
	dir = ft_sub(vp_up_left, cam->pos);
	return (dir);
}
