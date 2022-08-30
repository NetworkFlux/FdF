/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npinheir <npinheir@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 11:12:36 by npinheir          #+#    #+#             */
/*   Updated: 2021/11/08 13:25:28 by npinheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*	Vérification du nombre de lignes et de colonnes dans le fichier.	*/
static int	lines_check(char *argv)
{
	int		fd;
	char	*line;
	int		nb_n;

	fd = open(argv, O_RDONLY);
	if (fd == -1)
		return (1);
	get_next_line(fd, &line);
	nb_n = countwords(line, ' ');
	free(line);
	while (get_next_line(fd, &line))
	{
		if (nb_n != countwords(line, ' '))
		{
			ft_putendl_fd("This fdf file looks weird ...", 2);
			return (1);
		}
		free(line);
	}
	free(line);
	if (close(fd) == -1)
		return (1);
	return (0);
}

/*	Vérification de l'extension du fichier ainsi que la vérification 
	que le fichier ne soit pas vide.	*/
static int	data_check(char *argv)
{
	int		fd;
	char	*line;
	int		ret;

	fd = open(argv, O_RDONLY);
	if (!fdfinstr(argv) || fd == -1)
	{
		ft_putendl_fd("Not a valid fdf file ...", 2);
		return (1);
	}
	ret = get_next_line(fd, &line);
	free(line);
	if (ret == 0 || ret == -1)
	{
		ft_putendl_fd("No data found in the fdf file ...", 2);
		return (1);
	}
	if (close(fd) == -1)
		return (1);
	return (0);
}

/*	Lancement des 2 gros tests d'erreurs.	*/
int	error_check(char *argv)
{
	if (data_check(argv))
		return (1);
	if (lines_check(argv))
		return (1);
	return (0);
}
