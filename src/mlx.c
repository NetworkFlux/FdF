/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npinheir <npinheir@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 12:55:32 by npinheir          #+#    #+#             */
/*   Updated: 2021/11/08 13:19:53 by npinheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*	Fonction qui dessine les lignes verticales entre chaque
	points.	*/
void	draw_line_h(int a, int b, t_env *fdf)
{
	int	i;
	int	j;

	i = 0;
	while (i < a)
	{
		j = 0;
		while (j < b)
		{
			fdf->map.x0 = fdf->map.grid[i][j][0];
			fdf->map.y0 = fdf->map.grid[i][j][1];
			fdf->map.x1 = fdf->map.grid[i + 1][j][0];
			fdf->map.y1 = fdf->map.grid[i + 1][j][1];
			bresenham_1(fdf);
			j++;
		}
		i++;
	}
}

/*	Fonction qui dessine les lignes horizontales entre chaque
	points.	*/
void	draw_line_v(int a, int b, t_env *fdf)
{
	int	i;
	int	j;

	i = 0;
	while (i < a)
	{
		j = 0;
		while (j < b)
		{
			fdf->map.x0 = fdf->map.grid[i][j][0];
			fdf->map.y0 = fdf->map.grid[i][j][1];
			fdf->map.x1 = fdf->map.grid[i][j + 1][0];
			fdf->map.y1 = fdf->map.grid[i][j + 1][1];
			bresenham_1(fdf);
			j++;
		}
		i++;
	}
}

/*	Dessine tous les points de la grid et enregistre les coordonnées de chaques
	points après la rotation de 45 degrés.	*/
void	draw_points(t_env *fdf)
{
	int	i;
	int	j;
	int	x;
	int	y;

	i = 0;
	while (i < fdf->map.nb_l)
	{
		j = 0;
		while (j < fdf->map.nb_c)
		{
			x = (j * fdf->draw.space_h) + PAD;
			y = (i * fdf->draw.space_v) + PAD;
			fdf->map.grid[i][j][0] = x_rotate(x, y);
			fdf->map.grid[i][j][1] = y_rotate(x, y)
				- fdf->map.grid[i][j][2] * (fdf->draw.scale_z / 2);
			my_mlx_pixel_put(fdf, fdf->map.grid[i][j][0],
				fdf->map.grid[i][j][1], 0x0ffffff);
			j++;
		}
		i++;
	}
}

/*	Initialise les bon paramètres.	*/
void	mlx_settings(t_env *fdf)
{
	fdf->draw.space_h = (WIN_L / 2) / (fdf->map.nb_c - 1);
	fdf->draw.space_v = (WIN_H / 2) / (fdf->map.nb_l - 1);
	fdf->draw.scale_z = PAD / fdf->map.max_h;
}
