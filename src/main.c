/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npinheir <npinheir@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 10:57:39 by npinheir          #+#    #+#             */
/*   Updated: 2021/11/08 13:25:48 by npinheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_env *fdf, int x, int y, int color)
{
	char	*dst;

	dst = fdf->addr + (y * fdf->size_line + x * (fdf->bpp / 8));
	*(unsigned int *)dst = color;
}

/*	Fonction qui va s'occuper de tous ce qui est graphique.	*/
static void	mlx_start(t_env *fdf)
{
	fdf->mlx_p = mlx_init();
	mlx_settings(fdf);
	fdf->win_p = mlx_new_window(fdf->mlx_p, WIN_L, WIN_H, "FdF");
	fdf->img = mlx_new_image(fdf->mlx_p, WIN_L, WIN_H);
	fdf->addr = mlx_get_data_addr(fdf->img, &fdf->bpp,
			&fdf->size_line, &fdf->endian);
	draw_points(fdf);
	draw_line_h(fdf->map.nb_l - 1, fdf->map.nb_c, fdf);
	draw_line_v(fdf->map.nb_l, fdf->map.nb_c - 1, fdf);
	mlx_put_image_to_window(fdf->mlx_p, fdf->win_p, fdf->img, 0, 0);
	mlx_destroy_image(fdf->mlx_p, fdf->img);
	mlx_key_hook(fdf->win_p, key_hook, fdf);
	mlx_loop(fdf->mlx_p);
}

/*	Fonction éffectuant tout le travail.	*/
static void	ft_fdf(char *argv)
{
	t_env	fdf;

	ft_bzero(&fdf, sizeof(t_env));
	create_map(argv, &fdf);
	mlx_start(&fdf);
}

/*	Vérification des cas d'erreurs et lancement du programme en cas de
	réussite.	*/
int	main(int argc, char **argv)
{
	if (argc != 2)
		ft_putendl_fd("[USAGE]: ./fdf <fdf file>", 2);
	else if (error_check(argv[1]))
		return (1);
	else
		ft_fdf(argv[1]);
	return (0);
}
