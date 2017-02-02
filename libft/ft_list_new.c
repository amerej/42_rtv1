/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_new.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditsch <aditsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/16 04:17:50 by aditsch           #+#    #+#             */
/*   Updated: 2017/01/26 14:45:24 by aditsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_list_new(void const *content, size_t content_size)
{
	t_list	*list;

	list = (t_list *)malloc(sizeof(t_list));
	if (list)
	{
		if (content)
		{
			list->content_size = content_size;
			list->content = ft_memalloc(content_size);
			ft_memcpy(list->content, (void *)content, content_size);
		}
		else
		{
			list->content = NULL;
			list->content_size = 0;
		}
		list->next = NULL;
	}
	return (list);
}
