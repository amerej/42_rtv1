/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditsch <aditsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 10:49:00 by aditsch           #+#    #+#             */
/*   Updated: 2017/02/04 17:11:58 by aditsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

# include "vector.h"

typedef struct	s_ray
{
	t_vector	origin;
	t_vector	direction;
}				t_ray;

t_vector_dir	ft_new_ray(void);

double			ft_get_ray_x(t_vector v);
double			ft_get_ray_y(t_vector v);
double			ft_get_ray_z(t_vector v);
#endif
