/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_add.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coltcivers <coltcivers@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 22:23:56 by antheven          #+#    #+#             */
/*   Updated: 2024/04/09 00:41:40 by coltcivers       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "level.h"
#include "libft.h"
#include "game.h"

static void	check_for_player(t_lvl *level, char *line, int i)
{
	if (ft_strchr(line, 'N'))
	{
		level->player_start.y = i;
		level->player_start.x = ft_strchr(line, 'N') - line - 1;
		level->initial_direction = D_NO;
	}
	if (ft_strchr(line, 'S'))
	{
		level->player_start.y = i;
		level->player_start.x = ft_strchr(line, 'S') - line - 1;
		level->initial_direction = D_SO;
	}
	if (ft_strchr(line, 'E'))
	{
		level->player_start.y = i;
		level->player_start.x = ft_strchr(line, 'E') - line - 1;
		level->initial_direction = D_EA;
	}
	if (ft_strchr(line, 'W'))
	{
		level->player_start.y = i;
		level->player_start.x = ft_strchr(line, 'W') - line - 1;
		level->initial_direction = D_WE;
	}
}

int	map_add(t_lvl *level, int i, char *line, int j)
{
	char	**map_swap;

	j = 0;
	map_swap = level->map;
	level->map = ft_calloc(i + 1, sizeof(line));
	if (level->map == NULL)
		return (1);
	ft_memmove(level->map, map_swap, (i) * sizeof(line));
	if (line)
	{
		while (line[j])
		{
			if (ft_isspace(line[j]))
				line[j] = 'X';
			j++;
		}
	}
	level->map[i] = line;
	free(map_swap);
	if (ft_strlen(line) > (size_t)level->map_width)
		level->map_width = ft_strlen(line);
	check_for_player(level, line, i);
	if (line == 0)
		return (1);
	return (0);
}
