/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditsch <aditsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/04 11:19:49 by aditsch           #+#    #+#             */
/*   Updated: 2017/02/04 12:35:25 by aditsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_H
 #define OBJECT_H

# include "vector.h"

typedef	struct		s_sphere
{
	t_vector_3		position;
	t_vector_3		rotation;
	double			radius;
	int				color;
}					t_sphere;

typedef	struct		s_plane
{
	t_vector_3		position;
	t_vector_3		rotation;
	int				color;
}					t_plane;
#endif
