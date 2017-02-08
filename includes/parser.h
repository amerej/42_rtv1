/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditsch <aditsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/04 11:51:39 by aditsch           #+#    #+#             */
/*   Updated: 2017/02/08 14:37:18 by aditsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

typedef	enum	e_section
{
				NONE,
				RENDER,
				CAMERA,
				SPHERE,
				PLANE,
				LIGHT,
}				t_section;
#endif
