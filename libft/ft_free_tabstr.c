/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_tabstr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditsch <aditsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 22:13:56 by aditsch           #+#    #+#             */
/*   Updated: 2017/02/01 22:16:08 by aditsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "libft.h"

void	ft_free_tabstr(char **tab_str)
{
	int		i;

	i = 0;
	while (tab_str[i])
	{
		ft_free_ptr((void **)&tab_str[i]);
		++i;
	}
	ft_free_ptr((void **)&tab_str);
}
