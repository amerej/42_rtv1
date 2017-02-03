/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_object.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditsch <aditsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 22:59:18 by aditsch           #+#    #+#             */
/*   Updated: 2017/02/03 11:10:26 by aditsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		ft_set_sphere(t_list **obj_list, char **tab_str)
{
	t_obj	*obj;

	if (ft_tabstrlen(tab_str) == 4)
	{
		obj = (t_obj *)malloc(sizeof(t_obj));
		obj->type = ft_strdup("Sphere");
		ft_set_v3(&obj->pos, tab_str[0]);
		ft_set_v3(&obj->rot, tab_str[1]);
		obj->radius = atof(tab_str[2]);
		obj->color = ft_atoi_base(tab_str[3], 16);
		ft_list_push_back(obj_list, ft_list_new(obj, sizeof(t_obj)));
		ft_free_ptr((void **)&obj);
		return (TRUE);
	}
	return (FALSE);
}

int		ft_set_plane(t_list **obj_list, char **tab_str)
{
	t_obj	*obj;

	if (ft_tabstrlen(tab_str) == 3)
	{
		obj = (t_obj *)malloc(sizeof(t_obj));
		obj->type = ft_strdup("Plane");
		ft_set_v3(&obj->pos, tab_str[0]);
		ft_set_v3(&obj->rot, tab_str[1]);
		obj->color = ft_atoi_base(tab_str[2], 16);
		ft_list_push_back(obj_list, ft_list_new(obj, sizeof(t_obj)));
		ft_free_ptr((void **)&obj);
		return (TRUE);
	}
	return (FALSE);
}

int		ft_set_object(t_list **obj_list, char *line)
{
	char	*str;
	char	*type;
	char	**tab_str;
	int		ret;

	type = line;
	str = ft_strchr(line, ':');
	type = ft_strsub(type, 0, str - type);
	str = ft_strtrim(str + 1);
	tab_str = ft_strsplit(str, ',');
	if (!ft_strcmp("Sphere", type))
		ret = ft_set_sphere(obj_list, tab_str);
	if (!ft_strcmp("Plane", type))
		ret = ft_set_plane(obj_list, tab_str);
	ft_free_tabstr(tab_str);
	ft_free_ptr((void **)&str);
	ft_free_ptr((void **)&type);
	return (ret);
}
