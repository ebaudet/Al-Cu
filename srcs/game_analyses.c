/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_analyses.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebaudet <ebaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/09 05:08:25 by ebaudet           #+#    #+#             */
/*   Updated: 2014/03/09 05:08:25 by ebaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "al-cu.h"

int		game_analyse(t_data *d, char player)
{
	if (diag_analyse(d, player) || diag_inverse_analyse(d, player)
		|| vertical_analyse(d, player) || horizontal_analyse(d, player))
		return (1);
	return (0);
}

int		diag_analyse(t_data *d, char player)
{
	int		x;
	int		y;
	int		count;

	y = -1;
	while (++y < (d->columns - 3))
	{
		x = -1;
		while (++x < (d->lines - 3))
		{
			count = 0;
			while (d->tab[y][x] == player)
			{
				x++;
				y++;
				if (count == 4)
					return (1);
			}
			y = y - count;
			x = x - count;
		}
	}
	return (0);
}

int		diag_inverse_analyse(t_data *d, char player)
{
	int		x;
	int		y;
	int		count;

	y = 2;
	while (++y < d->columns)
	{
		x = 2;
		while (++x < d->lines)
		{
			count = 0;
			while (d->tab[y][x] == player)
			{
				x++;
				y--;
				if (count == 4)
					return (1);
			}
			y = y + count;
			x = x - count;
		}
	}
	return (0);
}

int		vertical_analyse(t_data *d, char player)
{
	int		x;
	int		y;
	int		count;

	y = -1;
	while (++y < (d->columns - 3))
	{
		x = -1;
		while (++x < d->lines)
		{
			count = 0;
			while (d->tab[y][x] == player)
			{
				y++;
				if (count == 4)
					return (1);
			}
			y = y - count;
		}
	}
	return (0);
}

int		horizontal_analyse(t_data *d, char player)
{
	int		x;
	int		y;
	int		count;

	y = -1;
	while (++y < d->columns)
	{
		x = -1;
		while (++x < (d->lines - 3))
		{
			count = 0;
			while (d->tab[y][x] == player)
			{
				x++;
				if (count == 4)
					return (1);
			}
			x = x - count;
		}
	}
	return (0);
}
