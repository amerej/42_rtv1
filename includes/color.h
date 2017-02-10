/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditsch <aditsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 20:20:25 by aditsch           #+#    #+#             */
/*   Updated: 2017/02/10 19:33:03 by aditsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

typedef struct		s_color
{
	double			r;
	double			g;
	double			b;
}					t_color;

t_color	ft_mult_color(t_color c, double r);
t_color	ft_cross_color(t_color c_1, t_color c_2);
t_color	ft_add_color(t_color a, t_color b);
void	ft_normalize_color(t_color *c);
#endif
