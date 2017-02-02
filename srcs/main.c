/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditsch <aditsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 09:14:54 by aditsch           #+#    #+#             */
/*   Updated: 2017/02/02 13:25:40 by aditsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int			main(int argc, char *argv[])
{
	t_env	*env;
	int		fd;

	fd = open(argv[1], O_RDONLY);

	if (!(env = ft_init_env()))
		ft_exit_perror("error : init env");
	if (!(env->scene = ft_init_scene(fd)))
	{
		ft_destroy_env(env);
		ft_exit_perror("error : init scene");
	}

	ft_display_scene_value(env->scene); // DEBUG

	if (!(env->win = ft_init_window(env)))
	{
		ft_destroy_env(env);
		ft_exit_perror("error : init window");
	}
	mlx_key_hook(env->win, ft_key_hook, env);
	mlx_expose_hook(env->win, ft_expose_hook, env);
	mlx_loop(env->mlx);
	return (FALSE);
}
