/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_del_content.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditsch <aditsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 16:19:59 by aditsch           #+#    #+#             */
/*   Updated: 2017/01/27 17:59:31 by aditsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_list_del_content(void *content, size_t content_size)
{
	if (content)
	{
		free(content);
		content = NULL;
	}
	content_size = 0;
}
