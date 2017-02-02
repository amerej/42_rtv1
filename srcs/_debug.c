/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _debug.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditsch <aditsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 10:31:39 by aditsch           #+#    #+#             */
/*   Updated: 2017/02/02 16:23:37 by aditsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	ft_display_window_value(t_scene *sc)
{
	printf("\x1b[32mScene\x1b[0m\n");
	printf("\x1b[34mName:\x1b[0m %s\n", sc->title);
	printf("\x1b[34mWidth:\x1b[0m %d\n", sc->width);
	printf("\x1b[34mHeight:\x1b[0m %d\n", sc->height);
	printf("\n");
}

void	ft_display_cam_value(t_cam *cam)
{
	printf("\x1b[32mCamera\x1b[0m\n");
	printf("\x1b[34mPos X:\x1b[0m %lf\n", cam->pos.x);
	printf("\x1b[34mPos Y:\x1b[0m %lf\n", cam->pos.y);
	printf("\x1b[34mPos Z:\x1b[0m %lf\n", cam->pos.z);
	printf("\x1b[34mRot X:\x1b[0m %lf\n", cam->rot.x);
	printf("\x1b[34mRot Y:\x1b[0m %lf\n", cam->rot.y);
	printf("\x1b[34mRot Z:\x1b[0m %lf\n", cam->rot.z);
	printf("\n");
}

void	ft_display_light_list(t_list *light_list)
{
	while (light_list)
	{
		printf("\x1b[32mLight %d\x1b[0m\n", ((t_light *)light_list->content)->id);
		printf("\x1b[34mPos X:\x1b[0m %lf\n", ((t_light *)light_list->content)->pos.x);
		printf("\x1b[34mPos Y:\x1b[0m %lf\n", ((t_light *)light_list->content)->pos.y);
		printf("\x1b[34mPos Z:\x1b[0m %lf\n", ((t_light *)light_list->content)->pos.z);
		printf("\x1b[34mIntensity:\x1b[0m %lf\n", ((t_light *)light_list->content)->intensity);
		printf("\n");
		light_list = light_list->next;
	}
}

void	ft_display_obj_list(t_list *obj_list)
{
	while (obj_list)
	{
		printf("\x1b[32m%s\x1b[0m\n", ((t_obj *)obj_list->content)->type);
		printf("\x1b[34mPos X:\x1b[0m %lf\n", ((t_obj *)obj_list->content)->pos.x);
		printf("\x1b[34mPos Y:\x1b[0m %lf\n", ((t_obj *)obj_list->content)->pos.y);
		printf("\x1b[34mPos Z:\x1b[0m %lf\n", ((t_obj *)obj_list->content)->pos.z);
		printf("\x1b[34mrot X:\x1b[0m %lf\n", ((t_obj *)obj_list->content)->rot.x);
		printf("\x1b[34mrot Y:\x1b[0m %lf\n", ((t_obj *)obj_list->content)->rot.y);
		printf("\x1b[34mrot Z:\x1b[0m %lf\n", ((t_obj *)obj_list->content)->rot.z);
		if (!ft_strcmp(((t_obj *)obj_list->content)->type, "Sphere"))
			printf("\x1b[34mRadius:\x1b[0m %lf\n", ((t_obj *)obj_list->content)->radius);
		printf("\x1b[34mColor:\x1b[0m %d\n", ((t_obj *)obj_list->content)->color);
		printf("\n");
		obj_list = obj_list->next;
	}
}

void	ft_display_scene_value(t_scene *sc)
{
	printf("\033[31mDEBUG\x1b[0m\n\n");
	ft_display_window_value(sc);
	ft_display_cam_value(sc->cam);
	ft_display_light_list(sc->light_list);
	ft_display_obj_list(sc->obj_list);
}
