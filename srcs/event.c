/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditsch <aditsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 09:17:26 by aditsch           #+#    #+#             */
/*   Updated: 2017/01/27 12:47:59 by aditsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		ft_expose_hook(t_env *env)
{
	ft_draw_window(env);
	return (FALSE);
}

int		ft_key_hook(int keycode, t_env *env)
{
	if (keycode == KEY_ESC)
	{
		mlx_destroy_window(env->mlx, env->win);
		ft_destroy_env(env);
		exit(EXIT_SUCCESS);
	}
	ft_draw_window(env);
	return (FALSE);
}
