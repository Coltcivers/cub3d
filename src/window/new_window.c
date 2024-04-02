/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_window.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coltcivers <coltcivers@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 08:37:11 by antheven          #+#    #+#             */
/*   Updated: 2024/04/02 16:19:21 by coltcivers       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"
#include "mlx.h"
#include <stddef.h>

static int	new_window_helper(t_display *display)
{
	display->win.ptr = mlx_new_window(display->ptr,
			display->win.size[WIDTH],
			display->win.size[HEIGHT],
			"cub3d");
	if (display->win.ptr == NULL)
		return (1);
	display->win.buffer.type = IMAGE;
	display->win.buffer.ptr = mlx_new_image(display->ptr,
			display->win.size[WIDTH],
			display->win.size[HEIGHT]);
	if (display->win.buffer.ptr == NULL)
		return (1);
	display->win.buffer.data = mlx_get_data_addr(display->win.buffer.ptr,
			&display->win.buffer.bits_per_pixel,
			&display->win.buffer.size_line,
			&display->win.buffer.endian);
	if (display->win.buffer.data == NULL)
		return (1);
	return (0);
}

int	new_window(t_display *display)
{
	int	x;

	display->win.size[WIDTH] = 800;
	display->win.size[HEIGHT] = 600;
	x = display->win.size[WIDTH];
	if (new_window_helper(display))
		return (1);
	while (x-- > 0)
		v_line(&display->win.buffer, x,
			(t_line){0, display->win.size[HEIGHT]}, 0xFFFFFF);
	mlx_put_image_to_window(display->ptr, display->win.ptr,
		display->win.buffer.ptr, 0, 0);
	return (0);
}
