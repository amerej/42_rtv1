/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_light.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditsch <aditsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 22:59:18 by aditsch           #+#    #+#             */
/*   Updated: 2017/02/16 17:13:49 by aditsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		ft_parse_light(t_list **lights, char *line)
{
	char		*str;
	char		**tab_str;
	t_light		*light;
	static int 	id = 1;

	str = ft_strchr(line, ':');
	str = ft_strtrim(str + 1);
	tab_str = ft_strsplit(str, ',');
	if (ft_tabstrlen(tab_str) == 1)
	{
		light = (t_light *)malloc(sizeof(t_light));
		ft_init_vector(&light->pos, tab_str[0]);
		ft_free_tabstr(tab_str);
		ft_free_ptr((void **)&str);
		ft_list_push_back(lights, ft_list_new(light, sizeof(t_light)));
		ft_free_ptr((void **)&light);
		return (TRUE);
	}
	ft_free_ptr((void **)&str);
	return (FALSE);
}
