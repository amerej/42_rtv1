/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditsch <aditsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 21:06:04 by aditsch           #+#    #+#             */
/*   Updated: 2017/01/25 21:06:38 by aditsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double		ft_atof(const char *str)
{
	char	**split_str;
	int		nb_dec;
	char	*ret;
	int		ret_int;

	ret = NULL;
	split_str = NULL;
	if (!*str)
		return (0.0);
	split_str = ft_strsplit(str, '.');
	nb_dec = ft_strlen(split_str[1]);
	if (nb_dec == 0)
		nb_dec = 1;
	ret = ft_strjoin_free(split_str[0], split_str[1], FREE_PTR_1 | FREE_PTR_2);
	if (split_str)
	{
		free(split_str);
		split_str = NULL;
	}
	ret_int = ft_atoi(ret);
	free(ret);
	ret = NULL;
	return (ret_int / pow(10, nb_dec));
}
