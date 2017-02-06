/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditsch <aditsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/04 11:19:49 by aditsch           #+#    #+#             */
/*   Updated: 2017/02/06 18:20:04 by aditsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_H
 #define OBJECT_H

# include "vector.h"

typedef	struct		s_sphere
{
	char			*type;
	t_vector		position;
	t_vector		rotation;
	double			radius;
	int				color;
}					t_sphere;

typedef	struct		s_plane
{
	char			*type;
	t_vector		position;
	t_vector		rotation;
	int				color;
}					t_plane;
#endif
