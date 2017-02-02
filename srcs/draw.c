/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditsch <aditsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 09:21:33 by aditsch           #+#    #+#             */
/*   Updated: 2017/02/02 14:14:44 by aditsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void		ft_put_pixel_img(t_env *env, t_point *p, int color)
{
	int	i;

	i = ((int)p->x * 4) + ((int)p->y * env->scene->img->size_line);
	env->scene->img->data[i] = color;
	env->scene->img->data[++i] = color >> 8;
	env->scene->img->data[++i] = color >> 16;
}

static void		ft_draw_img(t_env *env)
{
	t_point		p;

	p.y = 0;
	while (p.y < env->scene->height)
	{
		p.x = 0;
		while (p.x < env->scene->width)
		{
			ft_put_pixel_img(env, &p, 0x00ffff00);
			++p.x;
		}
		++p.y;
	}
}

void	ft_draw_window(t_env *env)
{
	env->scene->img->img_ptr = mlx_new_image(env->mlx,
		env->scene->width, env->scene->height);
	env->scene->img->data = mlx_get_data_addr(env->scene->img->img_ptr,
		&(env->scene->img->bpp),
		&(env->scene->img->size_line),
		&(env->scene->img->endian));
	ft_draw_img(env);
	mlx_put_image_to_window(env->mlx, env->win,
		env->scene->img->img_ptr, 0, 0);
	mlx_destroy_image(env->mlx, env->scene->img->img_ptr);
}
