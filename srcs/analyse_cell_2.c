/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyse_cell_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebaudet <ebaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/09 23:24:09 by ebaudet           #+#    #+#             */
/*   Updated: 2014/03/09 23:24:09 by ebaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "al-cu.h"

int	get_diagonal_numbers(t_data *d, int row, int col)
{
	int	rslt;
	int	first;
	int	second;
	int	third;
	int	fourth;

	rslt = 0;
	first = get_diagonal_number1(d, row, col);
	rslt = first > rslt ? first : rslt;
	second = get_diagonal_number2(d, row, col);
	rslt = second > rslt ? second : rslt;
	third = get_diagonal_number3(d, row, col);
	rslt = third > rslt ? third : rslt;
	fourth = get_diagonal_number4(d, row, col);
	rslt = fourth > rslt ? fourth : rslt;
	return (rslt);
}

int	get_diagonal_number1(t_data *d, int row, int col)
{
	int		i;
	int		j;
	int		rslt;
	char	player;

	rslt = 0;
	i = row;
	j = col;
	player = d->tab[row][col];
	while (d->tab[i][j] == player && i > 0 && j > 0)
	{
		i--;
		j--;
		rslt++;
	}
	if (d->tab[i][j] == player)
		rslt++;
	return (rslt);
}

int	get_diagonal_number2(t_data *d, int row, int col)
{
	int		i;
	int		j;
	int		rslt;
	char	player;

	rslt = 0;
	i = row;
	j = col;
	player = d->tab[row][col];
	while (d->tab[i][j] == player && i < d->lines - 1 && j > 0)
	{
		i++;
		j--;
		rslt++;
	}
	if (d->tab[i][j] == player)
		rslt++;
	return (rslt);
}

int	get_diagonal_number3(t_data *d, int row, int col)
{
	int		i;
	int		j;
	int		rslt;
	char	player;

	rslt = 0;
	i = row;
	j = col;
	player = d->tab[row][col];
	while (d->tab[i][j] == player && i > 0 && j < d->columns - 1)
	{
		i--;
		j++;
		rslt++;
	}
	if (d->tab[i][j] == player)
		rslt++;
	return (rslt);
}

int	get_diagonal_number4(t_data *d, int row, int col)
{
	int		i;
	int		j;
	int		rslt;
	char	player;

	rslt = 0;
	i = row;
	j = col;
	player = d->tab[row][col];
	while (d->tab[i][j] == player &&
			i < d->lines - 1 && j < d->columns - 1)
	{
		i++;
		j++;
		rslt++;
	}
	if (d->tab[i][j] == player)
		rslt++;
	return (rslt);
}
