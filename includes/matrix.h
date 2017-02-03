/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditsch <aditsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 11:12:02 by aditsch           #+#    #+#             */
/*   Updated: 2017/02/03 13:25:35 by aditsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_H
# define MATRIX_H

#include "matrix.h"

typedef double	t_m4[4][4];

t_m4			ft_m4_translation(int tx, int ty, int tz);
t_m4			ft_m4_rotation_x(double alpha);
t_m4			ft_m4_rotation_y(double beta);
t_m4			ft_m4_rotation_z(double gamma);
t_m4			ft_m4_scale(double s);
#endif
