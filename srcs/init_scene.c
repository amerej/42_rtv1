/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditsch <aditsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 09:09:08 by aditsch           #+#    #+#             */
/*   Updated: 2017/02/07 16:07:30 by aditsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static t_image		*ft_new_image(void)
{
	t_image		*image;

	if (!(image = (t_image *)malloc(sizeof(t_image))))
		perror("error : image memory allocation");
	return (image);
}

static t_camera		*ft_new_camera(void)
{
	t_camera	*camera;

	if (!(camera = (t_camera *)malloc(sizeof(t_camera))))
		perror("error : camera memory allocation");
	return (camera);
}

static t_scene		*ft_new_scene(void)
{
	t_scene		*scene;

	if (!(scene = (t_scene *)malloc(sizeof(t_scene))))
	{
		perror("error : scene memory allocation");
		return (NULL);
	}
	*scene = (t_scene){0, 0, NULL, NULL, NULL, NULL};
	return (scene);
}

static	t_object	*ft_new_object(void)
{
	t_object	*object;
	if (!(object = (t_object *)malloc(sizeof(t_object))))
	{
		perror("error : object memory allocation");
		return (NULL);
	}
	*object = (t_object){NULL, NULL};
	return (object);
}

t_scene				*ft_init_scene(int fd)
{
	t_scene		*scene;

	scene = NULL;
	if (!(scene = ft_new_scene()))
		return (NULL);
	else if (!(scene->camera = ft_new_camera()))
		return (NULL);
	else if (!(scene->image = ft_new_image()))
		return (NULL);
	else if (!(scene->object = ft_new_object()))
		return (NULL);
	else if (!ft_parse_scene(scene, fd))
		return (NULL);
	return (scene);
}
