/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unload_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coltcivers <coltcivers@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 19:29:38 by antheven          #+#    #+#             */
/*   Updated: 2024/03/31 18:56:44 by coltcivers       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"
#include "mlx.h"
#include <stdlib.h>
#include <unistd.h>

void	unload_game(t_display *display)
{
	if (display->level.loaded)
		unload_level(display);
	mlx_destroy_window(display->ptr, display->win.ptr);
	mlx_destroy_image(display->ptr, display->win.buffer.ptr);
	mlx_destroy_display(display->ptr);
	close(display->level.fd);
	free(display->ptr);
}
