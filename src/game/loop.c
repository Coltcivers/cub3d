/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coltcivers <coltcivers@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 10:12:48 by antheven          #+#    #+#             */
/*   Updated: 2024/03/30 16:03:32 by coltcivers       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "engine.h"
#include "mlx.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "utils.h"

void	handle_right(t_game *game)
{
	game->player.direction = game->player.direction + 1;
	if (game->player.direction > 360)
		game->player.direction -= 360;
}

void	handle_left(t_game *game)
{
	game->player.direction = game->player.direction - 1;
	if (game->player.direction < 0)
		game->player.direction += 360;
}

void	handle_esc(t_game *game)
{
	unload_game(&game->display);
	exit(0);
}

int	loop(void *param)
{
	t_game	*game;
	int		keycode;

	game = param;
	keycode = 65535;
	while (keycode-- > 0)
		loop_helper(game, keycode);
	if (operate_raycast(game))
		exit_game(game);
	return (mlx_put_image_to_window(game->display.ptr, game->display.win.ptr,
			game->display.win.buffer.ptr, 0, 0));
}
