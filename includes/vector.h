/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditsch <aditsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 10:49:00 by aditsch           #+#    #+#             */
/*   Updated: 2017/02/15 20:07:40 by aditsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

typedef struct	s_vector
{
	double		x;
	double		y;
	double		z;
}				t_vector;

double			ft_length(t_vector vec);
double			ft_squared_length(t_vector vec);
void			ft_normalize(t_vector *v);
double			ft_dot(t_vector vec_1, t_vector vec_2);
t_vector		ft_cross(t_vector vec_1, t_vector vec_2);
t_vector		ft_neg(t_vector v);
t_vector		ft_add(t_vector a, t_vector b);
t_vector		ft_sub(t_vector a, t_vector b);
t_vector		ft_mult(t_vector v, double r);
t_vector		ft_div(t_vector v, double r);
t_vector		ft_unit_vector(t_vector v);
#endif
