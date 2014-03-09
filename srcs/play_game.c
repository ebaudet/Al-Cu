/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebaudet <ebaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/09 17:10:31 by ebaudet           #+#    #+#             */
/*   Updated: 2014/03/09 17:10:31 by ebaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "al-cu.h"

int		play_game(t_data *d)
{
	char	*line;

	while (get_next_line(0, &line) > 0)
	{
		if (ft_strlen(line) == 0)
			continue ;
		if (information(d, line) == -1)
			return (-1);
		if (game_analyse(d, '1'))
			return (eb_success1("player 1 win", 1));
		if (game_analyse(d, '2'))
			return (eb_success1("player 2 win", 2));
	}
	return (0);
}

int		eb_put_piece(t_data *d, int pos)
{
	int		y;

	if (d->tab[0][pos] == ' ')
	{
		y = d->lines;
		while (--y >= 0)
		{
			if (d->tab[y][pos] == ' ')
			{
				d->tab[y][pos] = d->turn;
				break ;
			}
		}
		print_p4(d);
		d->turn = (d->turn == '1' ? '2' : '1');
	}
	else
	{
		ft_putendl("column is empty");
	}
	return (0);
}
