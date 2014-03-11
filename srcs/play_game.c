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

int		who_play(t_data *d)
{
	while (42)
	{
		print_p4(d);
		if (game_analyse(d, '1'))
			return (game_finish(d, '1'));
		if (game_analyse(d, '2'))
			return (game_finish(d, '2'));
		if (d->turn == d->computer)
		{
			ft_putendl("\nComputer turn :");
			if (computer_play(d) == -1)
				return (-1);
		}
		else
		{
			ft_putendl("\nYour turn :");
			if (play_game(d) == -1)
				return (-1);
		}
		d->turn = (d->turn == '1' ? '2' : '1');
	}
	return (0);
}

int		game_finish(t_data *d, char player)
{
	if (player == d->computer)
		ft_putendl("Computer Win !");
	else if (player == d->player)
		ft_putendl("You Win !");
	else
		ft_putendl("Match null.");
	return (0);
}

int		play_game(t_data *d)
{
	char	*line;
	int		ret;

	while (42)
	{
		if (d->turn == d->player)
			get_next_line(0, &line);
		if (d->turn != d->computer && ft_strlen(line) == 0)
			continue ;
		if (d->turn != d->computer && (ret = information(d, line)) == -1)
			return (-1);
		if (d->turn == d->player)
			ft_strdel(&line);
		if (ret == 0)
			break ;
	}
	return (0);
}

int		eb_put_piece(t_data *d, int pos, char print)
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
		/*if (print)
			print_p4(d);*/
	}
	else
	{
		if (print)
			ft_putendl("column is empty");
		return (1);
	}
	return (0);
}

int		eb_release_piece(t_data *d, int pos)
{
	int		y;

	y = -1;
	while (++y < d->lines)
	{
		if (d->tab[y][pos] != ' ')
		{
			d->tab[y][pos] = ' ';
			break ;
		}
	}
	return (0);
}
