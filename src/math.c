/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npinheir <npinheir@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 13:11:37 by npinheir          #+#    #+#             */
/*   Updated: 2021/11/05 11:18:40 by npinheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	y_rotate(int x, int y)
{
	float	angle;

	angle = 45 * (M_PI / 180);
	return ((sin(angle) * (x - OX) + cos(angle) * (y - OY) + 600) / 1);
}

int	x_rotate(int x, int y)
{
	float	angle;

	angle = 45 * (M_PI / 180);
	return ((cos(angle) * (x - OX) - sin(angle) * (y - OY) + OX) / 1);
}
