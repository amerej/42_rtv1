/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditsch <aditsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 09:09:08 by aditsch           #+#    #+#             */
/*   Updated: 2017/02/02 14:07:47 by aditsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static t_img		*ft_new_img(void)
{
	t_img	*img;

	if (!(img = (t_img *)malloc(sizeof(t_img))))
		perror("error : img memory allocation");
	return (img);
}

static t_cam		*ft_new_cam(void)
{
	t_cam	*cam;

	if (!(cam = (t_cam *)malloc(sizeof(t_cam))))
	{
		perror("error : cam memory allocation");
		return (NULL);
	}
	return (cam);
}

static t_scene		*ft_new_scene(void)
{
	t_scene		*scene;

	if (!(scene = (t_scene *)malloc(sizeof(t_scene))))
		perror("error : scene memory allocation");
	scene->cam = NULL;
	scene->img = NULL;
	scene->obj_list = NULL;
	scene->light_list = NULL;
	return (scene);
}

t_scene				*ft_init_scene(int fd)
{
	t_scene		*scene;

	scene = NULL;
	if (!(scene = ft_new_scene()))
		return (NULL);
	else if (!(scene->cam = ft_new_cam()))
		return (NULL);
	else if (!(scene->img = ft_new_img()))
		return (NULL);
	else if (!ft_parse_scene(scene, fd))
		return (NULL);
	return (scene);
}
