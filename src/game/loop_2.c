/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coltcivers <coltcivers@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 13:00:23 by coltcivers        #+#    #+#             */
/*   Updated: 2024/03/30 16:02:52 by coltcivers       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "engine.h"
#include "mlx.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "utils.h"

static void	handle_w(t_game *game)
{
	if (game->display.level.map
		[(int)(game->player.location.y
			+ sin(deg_to_rad(game->player.direction)))]
		[(int)(game->player.location.x
			+ cos(deg_to_rad(game->player.direction)))] == '1')
		return ;
	game->player.location.x
		+= cos(deg_to_rad(game->player.direction)) / 40;
	game->player.location.y
		+= sin(deg_to_rad(game->player.direction)) / 40;
}

static void	handle_a(t_game *game)
{
	if (game->display.level.map
		[(int)(game->player.location.y
			- cos(deg_to_rad(game->player.direction)))]
		[(int)(game->player.location.x
			+ sin(deg_to_rad(game->player.direction)))] == '1')
		return ;
	game->player.location.x
		+= sin(deg_to_rad(game->player.direction)) / 40;
	game->player.location.y
		-= cos(deg_to_rad(game->player.direction)) / 40;
}

static void	handle_s(t_game *game)
{
	if (game->display.level.map
		[(int)(game->player.location.y
			- sin(deg_to_rad(game->player.direction)))]
		[(int)(game->player.location.x
			- cos(deg_to_rad(game->player.direction)))] == '1')
		return ;
	game->player.location.x
		-= cos(deg_to_rad(game->player.direction)) / 40;
	game->player.location.y
		-= sin(deg_to_rad(game->player.direction)) / 40;
}

static void	handle_d(t_game *game)
{
	if (game->display.level.map
		[(int)(game->player.location.y
			+ cos(deg_to_rad(game->player.direction)))]
		[(int)(game->player.location.x
			- sin(deg_to_rad(game->player.direction)))] == '1')
		return ;
	game->player.location.x
		-= sin(deg_to_rad(game->player.direction)) / 40;
	game->player.location.y
		+= cos(deg_to_rad(game->player.direction)) / 40;
}

void	loop_helper(t_game *game, int keycode)
{
	if (game->events.keys[119] && keycode == 119)
		handle_w(game);
	else if (game->events.keys[97] && keycode == 97)
		handle_a(game);
	else if (game->events.keys[115] && keycode == 115)
		handle_s(game);
	else if (game->events.keys[100] && keycode == 100)
		handle_d(game);
	else if (game->events.keys[65361] && keycode == 65361)
		handle_left(game);
	else if (game->events.keys[65363] && keycode == 65363)
		handle_right(game);
	else if (game->events.keys[65307] && keycode == 65307)
		handle_esc(game);
}
