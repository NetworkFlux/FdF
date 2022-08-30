/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npinheir <npinheir@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 15:40:22 by npinheir          #+#    #+#             */
/*   Updated: 2021/11/08 13:19:10 by npinheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <mlx.h>
# include <math.h>

# include "../libft/include/libft.h"
# include "fdf_define.h"
# include "fdf_struct.h"

// Main
int		main(int argc, char **argv);
void	my_mlx_pixel_put(t_env *fdf, int x, int y, int color);

// Errors
int		error_check(char *argv);

// Create map
void	create_map(char *argv, t_env *fdf);

// MLX
void	mlx_settings(t_env *fdf);
void	draw_points(t_env *fdf);
void	draw_line_v(int a, int b, t_env *fdf);
void	draw_line_h(int a, int b, t_env *fdf);

void	bresenham_1(t_env *fdf);

// Hook
int		key_hook(int keycode, t_env *fdf);

// Math
int		x_rotate(int x, int y);
int		y_rotate(int x, int y);

// Utils
int		fdfinstr(const char *str);
int		countwords(char *s, char c);
int		***ft_tabnew_three(int x, int y, int z);

void	update_max_h(int n, t_env *fdf);
void	ft_free(t_env *f);

#endif