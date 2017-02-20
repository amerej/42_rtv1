/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditsch <aditsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 09:09:08 by aditsch           #+#    #+#             */
/*   Updated: 2017/02/20 10:53:35 by aditsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static t_img	*ft_init_img(void)
{
	t_img	*img;

	if (!(img = (t_img *)malloc(sizeof(t_img))))
		perror("error : img memory allocation");
	return (img);
}

static t_cam	*ft_init_cam(void)
{
	t_cam	*cam;

	if (!(cam = (t_cam *)malloc(sizeof(t_cam))))
		perror("error : cam memory allocation");
	return (cam);
}

static t_scene	*ft_init_scene(void)
{
	t_scene		*sc;

	if (!(sc = (t_scene *)malloc(sizeof(t_scene))))
	{
		perror("error : scene memory allocation");
		return (NULL);
	}
	sc->width = 1280;
	sc->height = 960;
	sc->img = NULL;
	sc->cam = NULL;
	sc->objects = NULL;
	sc->lights = NULL;
	return (sc);
}

t_scene			*ft_new_scene(int fd)
{
	t_scene		*sc;

	if (!(sc = ft_init_scene()))
		return (NULL);
	else if (!(sc->img = ft_init_img()))
		return (NULL);
	else if (!(sc->cam = ft_init_cam()))
		return (NULL);
	else if (!ft_parse_scene(sc, fd))
		return (NULL);
	if (!(sc->mlx = mlx_init()))
	{
		ft_putstr_fd("error : mlx init\n", 2);
		return (NULL);
	}
	if (!(sc->win = mlx_new_window(sc->mlx, sc->width, sc->height, "rtv1")))
	{
		ft_putstr_fd("error : mlx new window\n", 2);
		return (NULL);
	}
	return (sc);
}

void			ft_destroy_scene(t_scene *sc)
{
	if (sc)
	{
		if (sc->img)
			ft_free_ptr((void **)&sc->img);
		if (sc->cam)
			ft_free_ptr((void **)&sc->cam);
		if (sc->lights)
			ft_list_del(&sc->lights, &ft_list_del_content);
		if (sc->objects)
			ft_list_del(&sc->objects, &ft_list_del_content);
	}
	ft_free_ptr((void **)&sc);
}
