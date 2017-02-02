/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_del_one.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditsch <aditsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/22 16:45:49 by aditsch           #+#    #+#             */
/*   Updated: 2017/01/26 15:52:35 by aditsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_list_del_one(t_list **p_list, void (*del)(void *, size_t))
{
	if (p_list && *p_list && del)
	{
		(*del)((*p_list)->content, (*p_list)->content_size);
		free(*p_list);
		*p_list = NULL;
	}
}
