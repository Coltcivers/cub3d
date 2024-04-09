/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   feed_level.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antheven <antheven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 08:25:12 by antheven          #+#    #+#             */
/*   Updated: 2024/04/08 09:54:34 by antheven         ###   ########.fr       */
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
	if (load_level(&display->level, level_file))
		return (1);
	print_level(&display->level);
	if (load_textures(display))
	{
		printf("Error while loading textures\n");
		return (1);
	}
	display->level.loaded = 1;
	if (check_map(&display->level))
	{
		return (1);
	}
	return (0);
}
