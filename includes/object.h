/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditsch <aditsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/04 11:19:49 by aditsch           #+#    #+#             */
/*   Updated: 2017/02/20 13:45:35 by aditsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_H
# define OBJECT_H

# include "parser.h"
# include "vector.h"
# include "color.h"
# include "ray.h"
# include "../libft/libft.h"

typedef struct		s_op
{
	double			a;
	double			b;
	double			c;
	double			t1;
	double			t2;
	t_vector		x;
	t_vector		v;
	t_vector		d;
	double			dv;
	double			xv;
	double			t;
	double			delta;
	double			m;
}					t_op;

typedef	struct		s_object
{
	int				id;
	t_section		type;
	t_vector		pos;
	t_vector		rot;
	double			radius;
	double			length;
	t_color			color;
	t_vector		intersection;
	t_vector		normal;
}					t_object;

int					ft_intersect_sphere(t_ray ray, t_object *obj);
int					ft_intersect_plane(t_ray ray, t_object *obj);
int					ft_intersect_cylinder(t_ray ray, t_object *obj);
int					ft_intersect_cone(t_ray ray, t_object *obj);
int					ft_intersect_object(t_ray ray, t_object *obj);
t_object			*ft_get_closest_object(t_ray ray, t_list *objects);
void				ft_get_distance(t_op *op);
#endif
