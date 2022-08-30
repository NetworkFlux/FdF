/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npinheir <npinheir@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 11:43:29 by npinheir          #+#    #+#             */
/*   Updated: 2021/11/05 12:48:34 by npinheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	***tab_three_2(int x, int y, int z, int ***tab)
{
	int	i;
	int	j;

	i = -1;
	while (++i < y)
	{
		j = -1;
		while (++j < x)
		{
			tab[i][j] = (int *)malloc(sizeof(***tab) * z);
			if (!tab[i][j])
				return (NULL);
		}
	}
	return (tab);
}

int	***ft_tabnew_three(int x, int y, int z)
{
	int	i;
	int	***tab;

	i = -1;
	tab = (int ***)malloc(sizeof(*tab) * y);
	if (!tab)
		return (NULL);
	while (++i < y)
	{
		tab[i] = (int **)malloc(sizeof(**tab) * x);
		if (!tab[i])
			return (NULL);
	}
	return (tab_three_2(x, y, z, tab));
}

/*	Met à jour la heuteur maximum encontrée.	*/
void	update_max_h(int n, t_env *fdf)
{
	if (abs(n) > fdf->map.max_h)
		fdf->map.max_h = n;
	if (fdf->map.max_h == 0)
		fdf->map.max_h = 1;
}

/*	Détermine le nombre de caractères dans un string en fonction d'un
	séparateur.	*/
int	countwords(char *s, char c)
{
	int	count;
	int	i;

	if (!s || !s[0])
		return (0);
	count = 0;
	if (s[0] != c)
		count = 1;
	i = 1;
	while (s[i])
	{
		if (s[i - 1] == c && s[i] != c)
			count++;
		i++;
	}
	return (count);
}

/*	Vérification que le nom de fichier comporte bien l'extension .fdf.	*/
int	fdfinstr(const char *str)
{
	int	len;

	len = ft_strlen(str);
	return (str[len - 1] == 'f' && str[len - 2] == 'd' && str[len - 3] == 'f'
		&& str[len - 4] == '.');
}
