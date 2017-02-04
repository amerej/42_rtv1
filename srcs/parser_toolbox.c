/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_toolbox.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditsch <aditsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 21:10:39 by aditsch           #+#    #+#             */
/*   Updated: 2017/02/04 12:35:57 by aditsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

char		*ft_get_value(char *line)
{
	char	*value;

	value = ft_strchr(line, ':');
	if (value[2] == '\0' || !ft_isalnum(value[2]))
		return (NULL);
	return (value + 2);
}
