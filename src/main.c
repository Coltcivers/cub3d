/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coltcivers <coltcivers@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 08:19:10 by antheven          #+#    #+#             */
/*   Updated: 2024/04/08 18:15:52 by coltcivers       ###   ########.fr       */
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

int	exit_game(t_game *game)
{
	unload_game(&game->display);
	exit(EXIT_SUCCESS);
}

int	main(int argc, char **argv)
{
	t_game		game;

	if (argc != 2)
		return (1);
	game.display.ptr = mlx_init();
	if (game.display.ptr == NULL)
		return (1);
	if (new_window(&game.display))
		return (1);
	if (feed_level(&game.display, argv[1]))
	{
		unload_game(&game.display);
		return (1);
	}
	game.player.direction = game.display.level.initial_direction;
	register_events(&game);
	mlx_clear_window(game.display.ptr, game.display.win.ptr);
	mlx_hook(game.display.win.ptr, 17, 1L << 0, exit_game, &game);
	load_game(&game);
	mlx_loop_hook(game.display.ptr, loop, &game);
	mlx_loop(game.display.ptr);
	unload_game(&game.display);
	return (0);
}
