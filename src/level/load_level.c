/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_level.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antheven <antheven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 08:53:54 by antheven          #+#    #+#             */
/*   Updated: 2024/04/10 10:45:33 by antheven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "level.h"
#include "game.h"
#include <fcntl.h>
#include <stdio.h>

int	init_level(t_lvl *level)
{
	int	i;

	i = TEX_NB;
	while (i-- > 0)
		level->textures[i].loaded = 0;
	return (0);
}

static t_tex_type	get_token_type(char *s)
{
	t_tex_type	tex_type;

	tex_type = TEX_NB;
	if (ft_strncmp(s, "NO", 2) == 0)
		tex_type = NO;
	if (ft_strncmp(s, "SO", 2) == 0)
		tex_type = SO;
	if (ft_strncmp(s, "WE", 2) == 0)
		tex_type = WE;
	if (ft_strncmp(s, "EA", 2) == 0)
		tex_type = EA;
	if (ft_strncmp(s, "F", 1) == 0)
		tex_type = F;
	if (ft_strncmp(s, "C", 1) == 0)
		tex_type = C;
	return (tex_type);
}

static int	check_lvl_arg(t_lvl *level, char *line)
{
	char		**args;
	t_tex_type	tex_type;

	if (!(ft_strlen(line) && ft_strchr(line, ' ') && *line != ' '))
		return (2);
	args = ft_split(line, ' ');
	free(line);
	tex_type = get_token_type(args[0]);
	if (tex_type == TEX_NB)
		return (1);
	printf("[%s, %d] %s\n", args[0], tex_type, args[1]);
	if (level->textures[tex_type].loaded)
	{
		printf("Error: Texture already loaded\n");
		return (3);
	}
	level->textures[tex_type].loaded = 1;
	level->textures[tex_type].prefix = args[0];
	level->textures[tex_type].path = args[1];
	free(args);
	level->textures[tex_type].image.type = IMAGE;
	if (tex_type == F || tex_type == C)
		level->textures[tex_type].image.type = COLOR;
	return (0);
}

int	load_level(t_lvl *level, char *level_file)
{
	char	*line;
	int		lvl_arg;

	line = (char *)1;
	init_level(level);
	level->map_width = 0;
	while (line)
	{
		line = ft_readline(level->fd);
		if (!line)
		{
			break ;
			lvl_arg = check_lvl_arg(level, line);
			if (lvl_arg == 2)
				if (parse_map(level, line))
					break ;
			if (lvl_arg == 3)
				return(1);
		}
		else
			free(line);
	}
	if (fit_level(level))
		return (1);
	return (0);
}
