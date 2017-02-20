/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_scene.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aditsch <aditsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 12:04:43 by aditsch           #+#    #+#             */
/*   Updated: 2017/02/20 10:52:40 by aditsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int			ft_set_scene(t_scene *sc, char *line, t_section *section)
{
	int ret;

	if (*section == CAMERA)
		ret = ft_parse_camera(sc->cam, line);
	else if (*section == LIGHT)
		ret = ft_parse_light(&sc->lights, line);
	else if (*section == SPHERE || *section == PLANE ||
				*section == CYLINDER || *section == CONE)
		ret = ft_parse_object(&sc->objects, line);
	ret = 1;
	return (ret);
}

void		ft_get_section_object(char *line, t_section *section)
{
	if (!ft_strncmp(line, "Sphere:", 7))
		*section = SPHERE;
	else if (!ft_strncmp(line, "Plane:", 6))
		*section = PLANE;
	else if (!ft_strncmp(line, "Cylinder:", 9))
		*section = CYLINDER;
	else if (!ft_strncmp(line, "Cone:", 5))
		*section = CONE;
}

int			ft_parse_scene(t_scene *sc, int fd)
{
	char		*line;
	t_section	section;

	while (ft_get_next_line(fd, &line))
	{
		if (!ft_strncmp(line, "Camera:", 7))
			section = CAMERA;
		else if (!ft_strncmp(line, "Light:", 6))
			section = LIGHT;
		else
			section = NONE;
		ft_get_section_object(line, &section);
		if (!ft_set_scene(sc, line, &section))
		{
			ft_free_ptr((void **)&line);
			return (FALSE);
		}
		ft_free_ptr((void **)&line);
	}
	ft_free_ptr((void **)&line);
	return (TRUE);
}
