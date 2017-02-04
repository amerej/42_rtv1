/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditsch <aditsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 09:14:54 by aditsch           #+#    #+#             */
/*   Updated: 2017/02/04 12:57:21 by aditsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int			main(int argc, char *argv[])
{
	t_app	*app;
	int		fd;

	fd = open(argv[1], O_RDONLY);

	if (!(app = ft_init_app()))
		ft_exit_perror("error : init app");
	if (!(app->scene = ft_init_scene(fd)))
	{
		ft_destroy_app(app);
		ft_exit_perror("error : init scene");
	}
	if (!(app->win = ft_init_window(app)))
	{
		ft_destroy_app(app);
		ft_exit_perror("error : init window");
	}
	mlx_key_hook(app->win, ft_key_hook, app);
	mlx_expose_hook(app->win, ft_expose_hook, app);
	mlx_loop(app->mlx);
	return (FALSE);
}
