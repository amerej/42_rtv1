/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditsch <aditsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 13:52:37 by aditsch           #+#    #+#             */
/*   Updated: 2017/02/10 15:42:25 by aditsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERSECT_H
# define INTERSECT_H

# include "vector.h"

typedef struct		s_intersect_data
{
	t_vector		inter;
	t_vector		normal;
}					t_intersect_data;
#endif
