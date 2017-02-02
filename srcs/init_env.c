/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditsch <aditsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 09:41:09 by aditsch           #+#    #+#             */
/*   Updated: 2017/01/12 15:51:46 by aditsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static t_env	*ft_new_env(void)
{
	t_env	*env;

	env = NULL;
	if (!(env = (t_env *)malloc(sizeof(t_env))))
		ft_exit_perror("error : env memory allocation");
	return (env);
}

t_env			*ft_init_env(void)
{
	t_env	*env;

	if (!(env = ft_new_env()))
		return (NULL);
	return (env);
}
