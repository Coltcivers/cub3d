/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coltcivers <coltcivers@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 10:07:55 by antheven          #+#    #+#             */
/*   Updated: 2024/03/26 13:09:27 by coltcivers       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# include "display.h"
# include "events.h"
# include "entity.h"

typedef struct s_game	t_game;

struct s_game
{
	t_display	display;
	t_events	events;
	t_entity	player;
};

enum	e_direction
{
	D_NO=270,
	D_SO=90,
	D_EA=0,
	D_WE=180
};

int		loop(void *param);
int		load_game(t_game *game);
void	draw_minimap(t_game *game);
void	handle_right(t_game *game);
void	handle_left(t_game *game);
void	handle_esc(t_game *game);

#endif