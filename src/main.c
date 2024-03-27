/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coltcivers <coltcivers@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 08:19:10 by antheven          #+#    #+#             */
/*   Updated: 2024/03/26 13:43:43 by coltcivers       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "level.h"
#include "display.h"
#include "mlx.h"
#include "engine.h"
#include "events.h"
#include <stdio.h>
#include <stdlib.h>

static int	exit_game(t_game *game)
{
	printf("entered exit game \n");
	unload_game(&game->display);
	exit(EXIT_SUCCESS);
}

int	main(int argc, char **argv)
{
	t_game		game;

	if (argc != 2)
		return (1);
	game.display.ptr = mlx_init();
	new_window(&game.display);
	mlx_string_put(game.display.ptr, game.display.win.ptr, 106, 106, 0x0,
		"Loading game...");
	if (feed_level(&game.display, argv[1]))
	{
		unload_game(&game.display);
		return (1);
	}
	printf("initial dir : %d \n", game.display.level.initial_direction);
	game.player.direction = game.display.level.initial_direction;
	register_events(&game);
	mlx_clear_window(game.display.ptr, game.display.win.ptr);
	mlx_hook(game.display.win.ptr, 17, 1L << 0, exit_game, &game);
	mlx_loop_hook(game.display.ptr, loop, &game);
	load_game(&game);
	mlx_loop(game.display.ptr);
	unload_game(&game.display);
	return (0);
}
