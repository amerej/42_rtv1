/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditsch <aditsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 09:14:54 by aditsch           #+#    #+#             */
/*   Updated: 2017/02/20 13:51:13 by aditsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int			main(int argc, char *argv[])
{
	t_scene		*sc;
	int			fd;

	if (argc != 2)
	{
		ft_putstr("Error : No arguments\n");
		return (FALSE);
	}

	fd = open(argv[1], O_RDONLY);
	if (!(sc = ft_new_scene(fd)))
	{
		ft_destroy_scene(sc);
		return (FALSE);
	}
	mlx_key_hook(sc->win, ft_key_hook, sc);
	mlx_expose_hook(sc->win, ft_expose_hook, sc);
	mlx_loop(sc->mlx);
	return (FALSE);
}
