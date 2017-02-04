/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setter_vector.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditsch <aditsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/04 16:20:47 by aditsch           #+#    #+#             */
/*   Updated: 2017/02/04 17:35:50 by aditsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_vector_dir	ft_set_vector_dir(t_vector x, t_vector y, t_vector z)
{
	return ((t_vector_dir){x, y, z});
}

t_vector		ft_set_vector(double x, double y, double z)
{
	return ((t_vector){x, y, z});
}
