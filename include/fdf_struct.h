/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_struct.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npinheir <npinheir@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 10:58:24 by npinheir          #+#    #+#             */
/*   Updated: 2021/11/08 13:10:30 by npinheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_STRUCT_H
# define FDF_STRUCT_H

typedef struct s_map
{
	int		***grid;
	int		cur_x;
	int		cur_y;
	int		nb_l;
	int		nb_c;
	int		max_h;
	int		x0;
	int		y0;
	int		x1;
	int		y1;
}	t_map;

typedef struct s_draw
{
	int		space_h;
	int		space_v;
	int		scale_z;
	int		dx;
	int		dy;
	int		sx;
	int		sy;
	int		err;
	int		e2;
}	t_draw;

typedef struct s_env
{
	t_map	map;
	t_draw	draw;
	void	*mlx_p;
	void	*win_p;
	void	*img;
	char	*addr;
	int		bpp;
	int		size_line;
	int		endian;
}	t_env;

#endif