/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unload_level.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antheven <antheven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 15:31:31 by antheven          #+#    #+#             */
/*   Updated: 2024/04/10 10:47:31 by antheven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"
#include "mlx.h"
#include <stdlib.h>
#include <stdio.h>

void	unload_level(t_display *display)
{
	int	i;

	i = TEX_NB;
	while (i-- > 0)
	{
		if (display->level.textures[i].image.type == IMAGE
			&& display->level.textures[i].image.ptr != NULL
			&& display->level.textures[i].loaded)
			mlx_destroy_image(display->ptr,
				display->level.textures[i].image.ptr);
		if (display->level.textures[i].loaded)
			free(display->level.textures[i].prefix);
	}
	i = display->level.map_length;
	while (i-- > 0)
		free(display->level.map[i]);
	free(display->level.map);
}
