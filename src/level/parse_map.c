/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coltcivers <coltcivers@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 21:39:59 by antheven          #+#    #+#             */
/*   Updated: 2024/04/08 16:51:23 by coltcivers       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "level.h"
#include "libft.h"

int	parse_map(t_lvl *level, char *line)
{
	char	*line_addr;
	int		i;

	line_addr = line;
	if (ft_isspace(*line))
		while (ft_isspace(*line))
			*line++ = 'X';
	if (!ft_isdigit(*line))
		return (1);
	i = 0;
	line = line_addr;
	level->map = ft_calloc(i + 1, sizeof(line));
	if (level->map == NULL)
		return (1);
	level->map[i++] = line;
	while (!map_add(level, i++, ft_readline(level->fd), 0))
		;
	map_add(level, i, 0, 0);
	level->map_length = i;
	return (2);
}
