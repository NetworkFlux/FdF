/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npinheir <npinheir@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 11:08:06 by npinheir          #+#    #+#             */
/*   Updated: 2021/11/08 13:25:09 by npinheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*	Suite de l'algorithme de Bresenham.	*/
static void	bresenham_2(t_env *fdf)
{
	while (1)
	{
		my_mlx_pixel_put(fdf, fdf->map.x0, fdf->map.y0, 0x0ffffff);
		if (fdf->map.x0 == fdf->map.x1 && fdf->map.y0 == fdf->map.y1)
			break ;
		fdf->draw.e2 = fdf->draw.err;
		if (fdf->draw.e2 > -fdf->draw.dx)
		{
			fdf->draw.err -= fdf->draw.dy;
			fdf->map.x0 += fdf->draw.sx;
		}
		if (fdf->draw.e2 < fdf->draw.dy)
		{
			fdf->draw.err += fdf->draw.dx;
			fdf->map.y0 += fdf->draw.sy;
		}
	}
}

/*	Algorithme de Bresenham, celle-ci dessine les lignes entre
	deux points.	*/

void	bresenham_1(t_env *fdf)
{
	fdf->draw.dx = abs(fdf->map.x1 - fdf->map.x0);
	fdf->draw.dy = abs(fdf->map.y1 - fdf->map.y0);
	if (fdf->map.x0 < fdf->map.x1)
		fdf->draw.sx = 1;
	else
		fdf->draw.sx = -1;
	if (fdf->map.y0 < fdf->map.y1)
		fdf->draw.sy = 1;
	else
		fdf->draw.sy = -1;
	if (fdf->draw.dx > fdf->draw.dy)
		fdf->draw.err = fdf->draw.dx / 2;
	else
		fdf->draw.err = -fdf->draw.dy / 2;
	bresenham_2(fdf);
}

/*	Libère les grosse structures.	*/
void	ft_free(t_env *fdf)
{
	int	i;
	int	j;

	i = 0;
	while (i < fdf->map.nb_l)
	{
		j = 0;
		while (j < fdf->map.nb_c)
		{
			free(fdf->map.grid[i][j]);
			j++;
		}
		free(fdf->map.grid[i]);
		i++;
	}
	free(fdf->map.grid);
}

/*	Fonction qui gère la fermeture de la fenêtre une fois la touxhe ESC
	appuyée.	*/

int	key_hook(int keycode, t_env *fdf)
{
	if (keycode == ESC)
	{
		mlx_destroy_window(fdf->mlx_p, fdf->win_p);
		ft_free(fdf);
		exit(EXIT_SUCCESS);
	}
	return (0);
}
