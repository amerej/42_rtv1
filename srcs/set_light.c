/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_light.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditsch <aditsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 22:59:18 by aditsch           #+#    #+#             */
/*   Updated: 2017/02/02 15:06:40 by aditsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		ft_set_light(t_list **light_list, char *line)
{
	char		*str;
	char		**tab_str;
	t_light		*light;
	static int 	id = 1;

	str = ft_strchr(line, ':');
	str = ft_strtrim(str + 1);
	tab_str = ft_strsplit(str, ',');
	if (ft_tabstrlen(tab_str) == 2)
	{
		light = (t_light *)malloc(sizeof(t_light));
		light->id = id++;
		ft_set_vector3_value(&light->pos, tab_str[0]);
		light->intensity = atof(tab_str[1]);
		ft_free_tabstr(tab_str);
		ft_free_ptr((void **)&str);
		ft_list_push_back(light_list, ft_list_new(light, sizeof(t_light)));
		ft_free_ptr((void **)&light);
		return (TRUE);
	}
	ft_free_ptr((void **)&str);
	return (FALSE);
}
