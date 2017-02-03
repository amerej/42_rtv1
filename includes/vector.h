/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditsch <aditsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 10:49:00 by aditsch           #+#    #+#             */
/*   Updated: 2017/02/03 13:53:39 by aditsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

typedef struct	s_v3
{
	double		x;
	double		y;
	double		z;
	double		w;
}				t_v3;

double			ft_norm(t_v3 v);
double			ft_length(t_v3 v);
double			ft_dot(t_v3 a, t_v3 b);
void			ft_normalize(t_v3 v);
t_v3			ft_cross(t_v3 a, t_v3 b);
t_v3			ft_add(t_v3	a, t_v3 b);
t_v3			ft_sub(t_v3	a, t_v3 b);
t_v3			ft_mult(t_v3 v, double r);
#endif
