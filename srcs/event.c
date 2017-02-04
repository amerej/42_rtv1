/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditsch <aditsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 09:17:26 by aditsch           #+#    #+#             */
/*   Updated: 2017/02/04 12:22:08 by aditsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		ft_expose_hook(t_app *app)
{
	ft_draw_window(app);
	return (FALSE);
}

int		ft_key_hook(int keycode, t_app *app)
{
	if (keycode == KEY_ESC)
	{
		mlx_destroy_window(app->mlx, app->win);
		ft_destroy_app(app);
		exit(EXIT_SUCCESS);
	}
	ft_draw_window(app);
	return (FALSE);
}
