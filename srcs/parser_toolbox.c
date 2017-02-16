/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_toolbox.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditsch <aditsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 21:10:39 by aditsch           #+#    #+#             */
/*   Updated: 2017/02/16 19:36:30 by aditsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int	ft_init_vector(t_vector *v, char *str)
{
	char	**tab_str;
	int		ret;

	ret = TRUE;
	tab_str = ft_strsplit(str, ' ');
	if (!(ft_tabstrlen(tab_str) == 3))
		ret = FALSE;
	if (ret)
	{
		v->x = (double)ft_atoi(tab_str[0]);
		v->y = (double)ft_atoi(tab_str[1]);
		v->z = (double)ft_atoi(tab_str[2]);
	}
	ft_free_tabstr(tab_str);
	return (ret);
}
