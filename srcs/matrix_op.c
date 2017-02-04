/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_op.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditsch <aditsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 11:48:45 by aditsch           #+#    #+#             */
/*   Updated: 2017/02/04 15:44:43 by aditsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

void	ft_mult_vec_matrix(t_m4 m, t_vector src, t_vector *dst)
{
	t_vector	v;

	v.x = src.x * m[0][0] + src.y * m[1][0] + src.z * m[2][0] + src.w * m[3][0];
	v.y = src.x * m[0][1] + src.y * m[1][1] + src.z * m[2][1] + src.w * m[3][1];
	v.z = src.x * m[0][2] + src.y * m[1][2] + src.z * m[2][2] + src.w * m[3][2];
	v.w = src.x * m[0][3] + src.y * m[1][3] + src.z * m[2][3] + src.w * m[3][3];
	dst->x = v.x / v.w;
	dst->y = v.y / v.w;
	dst->z = v.z / v.w;
}

void	ft_mult_dir_matrix(t_m4 m, t_vector src, t_vector *dst)
{
	t_vector	v;

	v.x = src.x * m[0][0] + src.y * m[1][0] + src.z * m[2][0];
	v.y = src.x * m[0][1] + src.y * m[1][1] + src.z * m[2][1];
	v.z = src.x * m[0][2] + src.y * m[1][2] + src.z * m[2][2];
	dst->x = v.x;
	dst->y = v.y;
	dst->z = v.z;
}
