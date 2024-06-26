/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antheven <antheven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 08:39:46 by antheven          #+#    #+#             */
/*   Updated: 2024/04/06 05:25:05 by antheven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

double	deg_to_rad(double d);
void	draw_circle(t_image *image, t_point pos, int r, int color);
int		ft_table_count(char **table);

#endif
