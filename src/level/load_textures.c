/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antheven <antheven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 19:12:29 by antheven          #+#    #+#             */
/*   Updated: 2024/04/06 05:24:44 by antheven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"
#include "libft.h"
#include "level.h"
#include "images.h"
#include "utils.h"
#include "mlx.h"
#include <stdio.h>

static int	load_argb(t_display *display, t_tex_type tex)
{
	t_lvl		*level;
	char		**color;

	level = &(display)->level;
	color = ft_split(level->textures[tex].path, ',');
	if (!color || ft_table_count(color) != 3)
		return (1);
	level->textures[tex].image.color[A] = 255;
	level->textures[tex].image.color[R] = ft_atoi(color[0]);
	level->textures[tex].image.color[G] = ft_atoi(color[1]);
	level->textures[tex].image.color[B] = ft_atoi(color[2]);
	printf("Added %s color as R=%d G=%d B=%d\n",
		level->textures[tex].prefix, ft_atoi(color[0]),
		ft_atoi(color[1]), ft_atoi(color[2]));
	free(*color);
	free(color);
	return (0);
}

static int	load_image(t_display *display, t_tex_type tex)
{
	t_lvl		*level;

	level = &(display)->level;
	level->textures[tex].image.ptr = mlx_xpm_file_to_image(
			display->ptr,
			level->textures[tex].path,
			&level->textures[tex].image.size[WIDTH],
			&level->textures[tex].image.size[HEIGHT]);
	if (!level->textures[tex].image.ptr)
	{
		perror("load_textures()");
		return (1);
	}
	level->textures[tex].image.data = mlx_get_data_addr(
			level->textures[tex].image.ptr,
			&level->textures[tex].image.bits_per_pixel,
			&level->textures[tex].image.size_line,
			&level->textures[tex].image.endian);
	if (!level->textures[tex].image.data)
	{
		perror("load_textures()");
		return (1);
	}
	return (0);
}

int	load_textures(t_display *display)
{
	t_tex_type	tex;
	t_lvl		*level;

	level = &display->level;
	tex = TEX_NB;
	while (tex-- > 0)
	{
		if (level->textures[tex].image.type == IMAGE)
		{
			if (load_image(display, tex))
				return (1);
		}
		if (level->textures[tex].image.type == COLOR)
		{
			if (load_argb(display, tex))
				return (1);
		}
	}
	return (0);
}
