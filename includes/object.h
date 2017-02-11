/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditsch <aditsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/04 11:19:49 by aditsch           #+#    #+#             */
/*   Updated: 2017/02/11 00:02:57 by aditsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_H
 #define OBJECT_H

# include "../libft/libft.h"
# include "vector.h"
# include "parser.h"
# include "intersect.h"
# include "color.h"

typedef	struct		s_object
{
	int					id;
	t_section			type;
	t_vector			pos;
	t_vector			rot;
	double				radius;
	t_color				color;
	t_intersect_data	inter_data;
	double				a;
	double				b;
	double				c;
	double				delta;
	double				t;
	double				t1;
	double				t2;
	t_vector			oc;
}						t_object;
#endif
