/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditsch <aditsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 09:14:54 by aditsch           #+#    #+#             */
/*   Updated: 2017/02/07 22:51:18 by aditsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int			main(int argc, char *argv[])
{
	t_scene		*sc;
	int			fd;

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
