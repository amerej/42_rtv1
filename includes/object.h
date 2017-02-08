/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditsch <aditsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/04 11:19:49 by aditsch           #+#    #+#             */
/*   Updated: 2017/02/08 15:20:59 by aditsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_H
 #define OBJECT_H

# include "../libft/libft.h"
# include "vector.h"
# include "ray.h"
# include "parser.h"

typedef	struct		s_sphere
{
	t_section		type;
	t_vector		position;
	t_vector		rotation;
	double			radius;
	int				color;
}					t_sphere;

typedef	struct		s_plane
{
	t_section		type;
	t_vector		position;
	t_vector		rotation;
	int				color;
}					t_plane;
#endif
