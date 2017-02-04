/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditsch <aditsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 09:41:09 by aditsch           #+#    #+#             */
/*   Updated: 2017/02/04 12:22:44 by aditsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static t_app	*ft_new_app(void)
{
	t_app	*app;

	app = NULL;
	if (!(app = (t_app *)malloc(sizeof(t_app))))
		ft_exit_perror("error : app memory allocation");
	return (app);
}

t_app			*ft_init_app(void)
{
	t_app	*app;

	if (!(app = ft_new_app()))
		return (NULL);
	return (app);
}
