/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyse_cell.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebaudet <ebaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/09 22:07:06 by ebaudet           #+#    #+#             */
/*   Updated: 2014/03/09 22:07:06 by ebaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "al-cu.h"

int		get_cell_value(t_data *d, int row, int col)
{
	int	rslt;
	int	coeff;

	coeff = (d->tab[row][col] == d->computer ? 1 : -1);
	coeff = (d->tab[row][col] == ' ' ? 0 : coeff);
	if (coeff && wins(d, row, col))
	{
		ft_putstr("condition de victoire : ");
		ft_putnbr(100000 / d->columns / d->lines * coeff);
		ft_putchar('\n');
		print_p4(d);
		return (100000 / d->columns / d->lines * coeff);
	}
	rslt = d->columns - ft_abs(d->columns / 2 - col);
	rslt += get_horizontal_number(d, row, col) * d->columns;
	rslt += get_vertical_number(d, row, col) * d->columns;
	rslt += get_diagonal_numbers(d, row, col) * d->columns;
	rslt *= coeff;
	return (rslt);
}

int		eb_can_play(t_data *d, int x)
{
	if (d->tab[0][x] == ' ')
		return (0);
	return (1);
}

int		ft_abs(int i)
{
	if (i >= 0)
		return (i);
	else
		return (-i);
}

int		get_horizontal_number(t_data *d, int row, int col)
{
	int		i;
	int		rslt;
	char	player;

	i = col;
	player = d->tab[row][col];
	while (i > 0 && d->tab[row][i] == player)
		i--;
	if (d->tab[row][i] != player)
		i++;
	rslt = 0;
	while (i < d->columns && d->tab[row][i] == player)
	{
		i++;
		rslt++;
	}
	return (rslt);
}

int		get_vertical_number(t_data *d, int row, int col)
{
	int		i;
	int		rslt;
	char	player;

	i = row;
	player = d->tab[row][col];
	while (i > 0 && d->tab[i][col] == player)
		i--;
	if (d->tab[i][col] != player)
		i++;
	rslt = 0;
	while (i < d->lines && d->tab[i][col] == player)
	{
		i++;
		rslt++;
	}
	return (rslt);
}
