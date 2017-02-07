/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditsch <aditsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/04 11:19:49 by aditsch           #+#    #+#             */
/*   Updated: 2017/02/07 15:31:35 by aditsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_H
 #define OBJECT_H

# include "vector.h"
# include "../libft/libft.h"

typedef	struct		s_sphere
{
	t_vector		position;
	t_vector		rotation;
	double			radius;
	int				color;
}					t_sphere;

typedef	struct		s_plane
{
	t_vector		position;
	t_vector		rotation;
	int				color;
}					t_plane;

typedef struct		s_object
{
	t_list			*sphere_list;
	t_list			*plane_list;
}					t_object;
#endif
