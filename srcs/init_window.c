/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditsch <aditsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 18:29:37 by aditsch           #+#    #+#             */
/*   Updated: 2017/02/01 23:09:24 by aditsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void			*ft_init_window(t_env *env)
{
	void	*win;

	if (!env->scene)
	{
		ft_putstr_fd("error : scene not set\n", 2);
		return (NULL);
	}
	if (!(env->mlx = mlx_init()))
	{
		ft_putstr_fd("error : mlx_init\n", 2);
		return (NULL);
	}
	if (!(win = mlx_new_window(env->mlx, env->scene->width,
		env->scene->height, env->scene->title)))
	{
		ft_putstr_fd("error : mlx_new_window\n", 2);
		return (NULL);
	}
	return (win);
}
