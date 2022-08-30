/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npinheir <npinheir@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 11:46:34 by npinheir          #+#    #+#             */
/*   Updated: 2021/11/08 11:49:51 by npinheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	*str_split(char *str)
{
	int		nb_words;
	int		*res;
	int		i;
	int		nb_len;

	nb_words = countwords(str, ' ');
	res = malloc(sizeof(int) * nb_words);
	i = 0;
	while (i < nb_words)
	{
		while (*str && *str == ' ')
			str++;
		res[i] = ft_atoi(str);
		nb_len = ft_intlen(res[i]);
		while (nb_len--)
			str++;
		i++;
	}
	return (res);
}

/*	Création et remplissage de la grid.	*/
static void	fill_map(int fd, t_env *fdf)
{
	char	*line;
	int		*line_split;
	int		i;

	while (get_next_line(fd, &line))
	{
		fdf->map.cur_x = 0;
		i = 0;
		line_split = str_split(line);
		while (i < fdf->map.nb_c)
		{
			fdf->map.grid[fdf->map.cur_y][fdf->map.cur_x][2]
				= line_split[fdf->map.cur_x];
			update_max_h(line_split[fdf->map.cur_x], fdf);
			fdf->map.cur_x++;
			i++;
		}
		free(line);
		free(line_split);
		fdf->map.cur_y++;
	}
	free(line);
}

/*	Cette fonction va retourner le nombre totale le lignes et de colonnes
	trouvés dans le fichier .fdf	*/
static void	map_max(char *argv, t_env *fdf)
{
	int		fd;
	char	*line;

	fd = open(argv, O_RDONLY);
	if (fd == -1)
		exit(EXIT_FAILURE);
	get_next_line(fd, &line);
	fdf->map.nb_l++;
	fdf->map.nb_c = countwords(line, ' ');
	free(line);
	while (get_next_line(fd, &line))
	{
		fdf->map.nb_l++;
		free(line);
	}
	free(line);
	if (close(fd) == -1)
		exit(EXIT_FAILURE);
}

/*	Relêve de toutes les informations contenues dans le fichier .fdf.	*/
void	create_map(char *argv, t_env *fdf)
{
	int	fd;

	map_max(argv, fdf);
	fd = open(argv, O_RDONLY);
	if (fd == -1)
		exit(EXIT_FAILURE);
	fdf->map.grid = ft_tabnew_three(fdf->map.nb_c, fdf->map.nb_l, 3);
	fill_map(fd, fdf);
	if (close(fd) == -1)
		exit(EXIT_FAILURE);
}
