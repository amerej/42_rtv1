/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_camera.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditsch <aditsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 19:25:24 by aditsch           #+#    #+#             */
/*   Updated: 2017/02/16 20:27:23 by aditsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		ft_parse_camera(t_cam *cam, char *line)
{
	char	*str;
	char	**tab_str;

	str = ft_strchr(line, ':');
	str = ft_strtrim(str + 1);
	tab_str = ft_strsplit(str, ',');
	if (ft_tabstrlen(tab_str) == 2)
	{
		ft_init_vector(&cam->pos, tab_str[0]);
		ft_init_vector(&cam->rot, tab_str[1]);
		ft_free_tabstr(tab_str);
		ft_free_ptr((void **)&str);
		return (TRUE);
	}
	ft_free_ptr((void **)&str);
	return (FALSE);
}
