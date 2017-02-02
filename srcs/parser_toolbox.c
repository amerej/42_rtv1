/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_toolbox.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditsch <aditsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 21:10:39 by aditsch           #+#    #+#             */
/*   Updated: 2017/02/01 14:16:19 by aditsch          ###   ########.fr       */
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

// char		*ft_get_value(char *line, char *field_name)
// {
// 	char	*value;
// 	char	*field_tmp;
//
// 	field_tmp = ft_strtrim(line);
// 	if ((value = ft_strchr(field_tmp, ':')))
// 	{
// 		field_tmp = ft_strsub(field_tmp, 0, value - field_tmp);
// 		if (!(ft_strcmp(field_name, field_tmp)))
// 		{
// 			free(field_tmp);
// 			field_tmp = NULL;
// 			if (value[0] != ':' || value[1] == '\0' || !ft_isalnum(value[1]))
// 				return (NULL);
// 			return (value);
// 		}
// 		free(field_tmp);
// 		field_tmp = NULL;
// 	}
// 	return (NULL);
// }

// t_value		*ft_set_list_value(char *line)
// {
// 	t_value		*data;
// 	char		*value;
// 	char		*id;
//
// 	data = NULL;
// 	if (!(data = (t_value *)malloc(sizeof(t_value))))
// 		return (NULL);
// 	id = line;
// 	value = ft_strchr(id, ':');
// 	id = ft_strsub(id, 0, value - id);
// 	data->id = ft_strdup(id);
// 	data->value = ft_strdup(value + 2);
// 	free(id);
// 	id = NULL;
// 	return (data);
// }
//
// int			ft_set_double(double *dst, char *src)
// {
// 	int		tmp;
//
// 	tmp = ft_atof(src);
// 	*dst = tmp;
// 	return (TRUE);
// }
//
// int			ft_set_int(int *dst, char *src, int min, int max)
// {
// 	int		tmp;
//
// 	tmp = ft_atoi(src);
// 	if (tmp >= min && tmp <= max)
// 	{
// 		*dst = tmp;
// 		return (TRUE);
// 	}
// 	return (FALSE);
// }
//
// int			ft_set_str(char **dst, char *val)
// {
// 	int		len;
//
// 	len = ft_strlen(val);
// 	if (len > 0 && len <= 100)
// 	{
// 		*dst = ft_strdup(val);
// 		return (TRUE);
// 	}
// 	return (FALSE);
// }
