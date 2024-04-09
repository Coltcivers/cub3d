/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unload_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coltcivers <coltcivers@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 19:29:38 by antheven          #+#    #+#             */
/*   Updated: 2024/04/08 18:19:20 by coltcivers       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"
#include "mlx.h"
#include <stdlib.h>
#include <unistd.h>
#include "libft.h"

void	unload_game(t_display *display)
{
	if (display->level.fd > 0)
	{
		close(display->level.fd);
		unload_level(display);
	}
	mlx_destroy_window(display->ptr, display->win.ptr);
	mlx_destroy_image(display->ptr, display->win.buffer.ptr);
	mlx_destroy_display(display->ptr);
	free(display->ptr);
}
