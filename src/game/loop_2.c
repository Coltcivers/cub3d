/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coltcivers <coltcivers@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 13:00:23 by coltcivers        #+#    #+#             */
/*   Updated: 2024/03/26 13:02:58 by coltcivers       ###   ########.fr       */
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
