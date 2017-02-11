/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditsch <aditsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 14:43:29 by aditsch           #+#    #+#             */
/*   Updated: 2017/02/11 05:03:50 by aditsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"

t_color	ft_mult_color(t_color c, double r)
{
	return ((t_color){c.r * r, c.g * r, c.b * r});
}

t_color	ft_cross_color(t_color c_1, t_color c_2)
{
	return ((t_color){c_1.g * c_2.b - c_1.b * c_2.g,
		c_1.b * c_2.r - c_1.r * c_2.b,
		c_1.r * c_2.g - c_1.g * c_2.r});
}

t_color	ft_add_color(t_color a, t_color b)
{
	return ((t_color){a.r += b.r, a.g += b.g, a.b += b.b});
}

void	ft_normalize_color(t_color *c)
{
	if (c->r > 1.0)
		c->r = 1.0;
	if (c->g > 1.0)
		c->g = 1.0;
	if (c->b > 1.0)
		c->b = 1.0;
}
