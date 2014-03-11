/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   computer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebaudet <ebaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/09 20:25:57 by ebaudet           #+#    #+#             */
/*   Updated: 2014/03/09 20:25:57 by ebaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "al-cu.h"

int		computer_play(t_data *d)
{
	int		x;
	int		bestcol;
	int		bestval;
	int		val;

	bestcol = 0;
	bestval = -100000;
	x = -1;
	while (++x < d->columns)
	{
		if (!eb_can_play(d, x))
		{
			val = min(d, x, d->turn, 0);
			if (val > bestval)
			{
				bestval = val;
				/*ft_putnbr(bestval);
				ft_putchar(' ');*/
				bestcol = x;
			}
		}
	}
	eb_put_piece(d, bestcol, 1);
	return (0);
}

int		min(t_data *d, int x, char player, int depth)
{
	int		i;
	int		bestval;
	int		val;

	eb_put_piece(d, x, 0);
	bestval = 100000;
	if ((!game_analyse(d, player)) && depth < 2)
	{
		i = -1;
		while (++i < d->columns)
		{
			if (!eb_can_play(d, i))
			{
				val = max(d, i, d->player, depth + 1);
				bestval = (val < bestval ? val : bestval);
			}
		}
		eb_release_piece(d, x);
		return (bestval);
	}
	val = get_map_value(d);
	eb_release_piece(d, x);
	return (val);
}

int		max(t_data *d, int x, char player, int depth)
{
	int		i;
	int		bestval;
	int		val;

	eb_put_piece(d, x, 0);
	bestval = -100000;
	if ((!game_analyse(d, player)) && depth < 2)
	{
		i = -1;
		while (++i < d->columns)
		{
			if (!eb_can_play(d, i))
			{
				val = min(d, i, d->computer, depth + 1);
				bestval = (val > bestval ? val : bestval);
			}
		}
		eb_release_piece(d, x);
		return (bestval);
	}
	val = get_map_value(d);
	eb_release_piece(d, x);
	return (val);
}

int		get_map_value(t_data *d)
{
	int		rslt;
	int		i;
	int		j;

	rslt = 0;
	i = -1;
	while (++i < d->lines)
	{
		j = -1;
		while (++j < d->columns)
		{
			rslt += get_cell_value(d, i, j);
		}
	}
	return (rslt);
}

int		wins(t_data *d, int row, int col)
{
	char	player;

	player = d->tab[row][col];
	if (get_horizontal_number(d, row, col) == 4)
		return (player);
	if (get_vertical_number(d, row, col) == 4)
		return (player);
	if (get_diagonal_numbers(d, row, col) == 4)
		return (player);
	return (0);
}
