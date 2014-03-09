/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebaudet <ebaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/08 23:10:06 by ebaudet           #+#    #+#             */
/*   Updated: 2014/03/08 23:10:06 by ebaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "al-cu.h"
#include "libft.h"

void	print_nb(int nb, int width, int center)
{
	int		size;
	int		i;

	size = 0;
	if ((nb / 10) == 0)
		size = 1;
	else if ((nb / 100) == 0)
		size = 2;
	else if ((nb / 1000) == 0)
		size = 3;
	else if ((nb / 10000) == 0)
		size = 4;
	i = -1;
	if (center)
		center = (width - size) % 2;
	while (size && (width >= size) && ++i < (width - size - center))
		ft_putchar(' ');
	ft_putnbr(nb);
	i = i - 1;
	while (center && size && (width >= size) && ++i < (width - size))
		ft_putchar(' ');
}

void	print_p4(t_data *d)
{
	int		x;
	int		y;

	y = -1;
	while (++y < d->lines)
	{
		x = -1;
		print_nb(d->lines - y, 4, 0);
		while (++x < d->columns)
		{
			ft_putstr(" | ");
			print_player(d->tab[y][x]);
		}
		ft_putendl(" |");
	}
	x = -1;
	ft_putstr("     ");
	while (++x < d->columns)
		print_nb(x + 1, 4, 1);
	ft_putchar('\n');
}

void	print_player(char player)
{
	if (player == '1')
	{
		ft_putstr("\033[33mx\033[0m");
	}
	if (player == '2')
	{
		ft_putstr("\033[31mo\033[0m");
	}
	if (player == ' ')
	{
		ft_putstr(" ");
	}
}
