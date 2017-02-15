/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditsch <aditsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 20:20:25 by aditsch           #+#    #+#             */
/*   Updated: 2017/02/15 15:42:05 by aditsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

typedef struct	s_color
{
	float		r;
	float		g;
	float		b;
}				t_color;

t_color			ft_mult_color(t_color c, float r);
t_color			ft_cross_color(t_color a, t_color b);
t_color			ft_add_color(t_color a, t_color b);
t_color			ft_unit_color(t_color c);
void			ft_normalize_color(t_color *c);
#endif
