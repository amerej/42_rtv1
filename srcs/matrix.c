/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditsch <aditsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 11:16:05 by aditsch           #+#    #+#             */
/*   Updated: 2017/02/03 13:24:16 by aditsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

t_m4	ft_m4_translation(int tx, int ty, int tz)
{
	return ((t_m4){
	{1, 0, 0, tx},
	{0, 1, 0, ty},
	{0, 0, 1, tz},
	{0, 0, 0, 1}});
}

t_m4	ft_m4_rotation_x(double alpha)
{
	return ((t_m4){
	{1, 0, 0, 0},
	{0, cos(alpha), sin(alpha), 0},
	{0, -sin(alpha), cos(alpha), 0},
	{0, 0, 0, 1}});
}

t_m4	ft_m4_rotation_y(double beta)
{
	return ((t_m4){
	{cos(beta), 0, -sin(beta), 0},
	{0, 1, 0, 0},
	{sin(beta), 0, cos(beta), 0},
	{0, 0, 0, 1}});
}

t_m4	ft_m4_rotation_z(double gamma)
{
	return ((t_m4){
	{cos(gamma), sin(gamma), 0, 0},
	{-sin(gamma), cos(gamma), 0, 0},
	{0, 0, 1, 0},
	{0, 0, 0, 1}});
}

t_m4	ft_m4_scale(double s)
{
	return ((t_m4){
	{s, 0, 0, 0},
	{0, s, 0, 0},
	{0, 0, s, 0},
	{0, 0, 0, 1}});
}
