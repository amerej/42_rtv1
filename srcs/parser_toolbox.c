/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_toolbox.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditsch <aditsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 21:10:39 by aditsch           #+#    #+#             */
/*   Updated: 2017/02/07 23:23:24 by aditsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		ft_init_vector(t_vector *v, char *str)
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

char		*ft_get_value(char *line)
{
	char	*value;

	value = ft_strchr(line, ':');
	if (value[2] == '\0' || !ft_isalnum(value[2]))
		return (NULL);
	return (value + 2);
}
