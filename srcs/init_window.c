/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditsch <aditsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 18:29:37 by aditsch           #+#    #+#             */
/*   Updated: 2017/02/04 12:29:34 by aditsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void			*ft_init_window(t_app *app)
{
	void	*win;

	if (!app->scene)
	{
		ft_putstr_fd("error : scene not set\n", 2);
		return (NULL);
	}
	if (!(app->mlx = mlx_init()))
	{
		ft_putstr_fd("error : mlx init\n", 2);
		return (NULL);
	}
	if (!(win = mlx_new_window(app->mlx, app->scene->width,
		app->scene->height, "rtv1")))
	{
		ft_putstr_fd("error : mlx new window\n", 2);
		return (NULL);
	}
	return (win);
}
