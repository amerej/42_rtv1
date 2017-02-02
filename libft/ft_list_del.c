/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_del.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditsch <aditsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/22 16:44:19 by aditsch           #+#    #+#             */
/*   Updated: 2017/01/26 18:57:48 by aditsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_list_del(t_list **p_list, void (*del)(void *, size_t))
{
	if (!(p_list && *p_list && del))
		return ;
	ft_list_del(&((*p_list)->next), del);
	del((*p_list)->content, (*p_list)->content_size);
	free(*p_list);
	*p_list = NULL;
}
