/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_render.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditsch <aditsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 18:33:49 by aditsch           #+#    #+#             */
/*   Updated: 2017/02/08 14:53:25 by aditsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		ft_parse_render(t_scene *sc, char *line)
{
	char	*str;
	char	**tab_str;

	str = ft_strchr(line, ':');
	str = ft_strtrim(str + 1);
	tab_str = ft_strsplit(str, ',');
	if (ft_tabstrlen(tab_str) == 2)
	{
		sc->width = ft_atoi(tab_str[0]);
		sc->height = ft_atoi(tab_str[1]);
		ft_free_tabstr(tab_str);
		ft_free_ptr((void **)&str);
		return (TRUE);
	}
	ft_free_ptr((void **)&str);
	return (FALSE);
}