/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditsch <aditsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/04 11:19:49 by aditsch           #+#    #+#             */
/*   Updated: 2017/02/13 20:37:05 by aditsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_H
 #define OBJECT_H

# include "parser.h"
# include "vector.h"
# include "color.h"
# include "ray.h"
# include "../libft/libft.h"

typedef	struct		s_object
{
	int				id;
	t_section		type;
	t_vector		pos;
	t_vector		rot;
	float			radius;
	t_color			color;
	t_vector		inter_p;
	t_vector		normal;
	float			a;
	float			b;
	float			c;
	float			delta;
	float			t;
	float			t1;
	float			t2;
	t_vector		oc;
}					t_object;

int				ft_intersect_sphere(t_ray ray, t_object *obj);
int				ft_intersect_object(t_ray ray, t_object *obj);
t_object		*ft_get_closest_object(t_ray ray, t_list *objects);
#endif
