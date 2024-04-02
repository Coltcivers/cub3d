/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   feed_level.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coltcivers <coltcivers@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 08:25:12 by antheven          #+#    #+#             */
/*   Updated: 2024/03/31 19:03:40 by coltcivers       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"
#include "libft.h"
#include <stdio.h>

int	feed_level(t_display *display, char *level_file)
{
	int	level_file_size;

	display->level.loaded = 0;
	level_file_size = ft_strlen(level_file);
	if (ft_strncmp((level_file + level_file_size - 5), ".cub", 4))
	{
		printf("Level file name must end with '.cub'.\n");
		return (1);
	}
	load_level(&display->level, level_file);
	print_level(&display->level);
	if (load_textures(display))
		return (1);
	display->level.loaded = 1;
	if (check_map(&display->level))
	{
		return (1);
	}
	return (0);
}
