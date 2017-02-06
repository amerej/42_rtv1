/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_object.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditsch <aditsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 22:59:18 by aditsch           #+#    #+#             */
/*   Updated: 2017/02/06 18:24:56 by aditsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		ft_parse_sphere(t_list **obj, char **tab_str)
{
	t_sphere	*sphere;

	if (ft_tabstrlen(tab_str) == 4)
	{
		sphere = (t_sphere *)malloc(sizeof(t_sphere));
		sphere->type = ft_strdup("sphere");
		ft_init_vector(&sphere->position, tab_str[0]);
		ft_init_vector(&sphere->rotation, tab_str[1]);
		sphere->radius = atof(tab_str[2]);
		sphere->color = ft_atoi_base(tab_str[3], 16);
		ft_list_push_back(obj, ft_list_new(sphere, sizeof(t_sphere)));
		ft_free_ptr((void **)&sphere);
		return (TRUE);
	}
	return (FALSE);
}

int		ft_parse_plane(t_list **obj, char **tab_str)
{
	t_plane		*plane;

	if (ft_tabstrlen(tab_str) == 3)
	{
		plane = (t_plane *)malloc(sizeof(t_plane));
		plane->type = ft_strdup("plane");
		ft_init_vector(&plane->position, tab_str[0]);
		ft_init_vector(&plane->rotation, tab_str[1]);
		plane->color = ft_atoi_base(tab_str[2], 16);
		ft_list_push_back(obj, ft_list_new(plane, sizeof(t_plane)));
		ft_free_ptr((void **)&plane);
		return (TRUE);
	}
	return (FALSE);
}

int		ft_parse_object(t_list **obj, char *line)
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
		ret = ft_parse_sphere(obj, tab_str);
	if (!ft_strcmp("Plane", type))
		ret = ft_parse_plane(obj, tab_str);
	ft_free_tabstr(tab_str);
	ft_free_ptr((void **)&str);
	ft_free_ptr((void **)&type);
	return (ret);
}
