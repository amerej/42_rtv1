/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditsch <aditsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 09:51:44 by aditsch           #+#    #+#             */
/*   Updated: 2017/02/06 18:24:21 by aditsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	ft_destroy_app(t_app *app)
{
	if (app->scene)
	{
		ft_free_ptr((void **)&app->scene->image);
		ft_free_ptr((void **)&app->scene->camera);
		if (app->scene->light)
			ft_list_del(&app->scene->light, &ft_list_del_content);
		if (app->scene->object)
			ft_list_del(&app->scene->object, &ft_list_del_content);
	}
	ft_free_ptr((void **)&app->scene);
	ft_free_ptr((void **)&app);
}
