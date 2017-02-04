/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditsch <aditsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 09:21:33 by aditsch           #+#    #+#             */
/*   Updated: 2017/02/04 12:43:29 by aditsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void		ft_put_pixel_img(t_app *app, t_vector_3 *p, int color)
{
	int	i;

	i = ((int)p->x * 4) + ((int)p->y * app->scene->image->size_line);
	app->scene->image->data[i] = color;
	app->scene->image->data[++i] = color >> 8;
	app->scene->image->data[++i] = color >> 16;
}

static void		ft_draw_img(t_app *app)
{
	t_vector_3	p;

	p.y = 0;
	while (p.y < app->scene->height)
	{
		p.x = 0;
		while (p.x < app->scene->width)
		{
			ft_put_pixel_img(app, &p, 0x00ffff00);
			++p.x;
		}
		++p.y;
	}
}

void	ft_draw_window(t_app *app)
{
	app->scene->image->img_ptr = mlx_new_image(app->mlx,
		app->scene->width, app->scene->height);
	app->scene->image->data = mlx_get_data_addr(app->scene->image->img_ptr,
		&(app->scene->image->bpp),
		&(app->scene->image->size_line),
		&(app->scene->image->endian));
	ft_draw_img(app);
	mlx_put_image_to_window(app->mlx, app->win,
		app->scene->image->img_ptr, 0, 0);
	mlx_destroy_image(app->mlx, app->scene->image->img_ptr);
}
