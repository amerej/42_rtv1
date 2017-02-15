/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditsch <aditsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 17:33:19 by aditsch           #+#    #+#             */
/*   Updated: 2017/02/15 21:50:32 by aditsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"

t_color		ft_mult_color(t_color c, double r)
{
	return ((t_color){c.r * r, c.g * r, c.b * r});
}

t_color		ft_cross_color(t_color a, t_color b)
{
	return ((t_color){a.g * b.b - a.b * b.g,
		a.b * b.r - a.r * b.b,
		a.r * b.g - a.g * b.r});
}

t_color		ft_add_color(t_color a, t_color b)
{
	return ((t_color){a.r += b.r, a.g += b.g, a.b += b.b});
}

t_color		ft_unit_color(t_color c)
{
	t_color		color;
	color.r = (c.r > 1.0) ? 1.0 : c.r;
	color.g = (c.g > 1.0) ? 1.0 : c.g;
	color.b = (c.b > 1.0) ? 1.0 : c.b;
	return (color);
}
