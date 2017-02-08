/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditsch <aditsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 09:17:26 by aditsch           #+#    #+#             */
/*   Updated: 2017/02/07 23:04:24 by aditsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		ft_expose_hook(t_scene *sc)
{
	ft_draw_window(sc);
	return (FALSE);
}

int		ft_key_hook(int keycode, t_scene *sc)
{
	if (keycode == KEY_ESC)
	{
		mlx_destroy_window(sc->mlx, sc->win);
		ft_destroy_scene(sc);
		exit(EXIT_SUCCESS);
	}
	ft_draw_window(sc);
	return (FALSE);
}
