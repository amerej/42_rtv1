/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditsch <aditsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 09:51:44 by aditsch           #+#    #+#             */
/*   Updated: 2017/02/02 16:45:59 by aditsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	ft_destroy_env(t_env *env)
{
	if (env->scene)
	{
		ft_free_ptr((void **)&env->scene->img);
		ft_free_ptr((void **)&env->scene->cam);
		if (env->scene->light_list)
			ft_list_del(&env->scene->light_list, &ft_list_del_content);
		if (env->scene->light_list)
			ft_list_del(&env->scene->obj_list, &ft_list_del_content);
	}
	ft_free_ptr((void **)&env->scene);
	ft_free_ptr((void **)&env);
}
