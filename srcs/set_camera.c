/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_camera.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditsch <aditsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 19:25:24 by aditsch           #+#    #+#             */
/*   Updated: 2017/02/03 11:10:18 by aditsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		ft_set_v3(t_v3 *v, char *str)
{
	char	**tab_str;

	if ((tab_str = ft_strsplit(str, ' ')))
	{
		if (ft_tabstrlen(tab_str) == 3)
		{
			v->x = atof(tab_str[0]);
			v->y = atof(tab_str[1]);
			v->z = atof(tab_str[2]);
		}
		ft_free_tabstr(tab_str);
	}
}

int		ft_set_camera(t_cam *cam, char *line)
{
	char	*str;
	char	**tab_str;

	str = ft_strchr(line, ':');
	str = ft_strtrim(str + 1);
	tab_str = ft_strsplit(str, ',');
	if (ft_tabstrlen(tab_str) == 2)
	{
		ft_set_v3(&cam->pos, tab_str[0]);
		ft_set_v3(&cam->rot, tab_str[1]);
		ft_free_tabstr(tab_str);
		ft_free_ptr((void **)&str);
		return (TRUE);
	}
	ft_free_ptr((void **)&str);
	return (FALSE);
}
