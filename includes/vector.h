/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditsch <aditsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 10:49:00 by aditsch           #+#    #+#             */
/*   Updated: 2017/02/04 12:55:13 by aditsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

typedef struct	s_vector_3
{
	double		x;
	double		y;
	double		z;
	double		w;
}				t_vector_3;

double			ft_norm(t_vector_3 v);
double			ft_length(t_vector_3 v);
double			ft_dot(t_vector_3 a, t_vector_3 b);
t_vector_3		ft_normalize(void);
t_vector_3		ft_cross(t_vector_3 a, t_vector_3 b);
t_vector_3		ft_add(t_vector_3 a, t_vector_3 b);
t_vector_3		ft_sub(t_vector_3 a, t_vector_3 b);
t_vector_3		ft_mult(t_vector_3 v, double r);
#endif
