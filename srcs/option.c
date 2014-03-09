/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebaudet <ebaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/09 04:33:44 by ebaudet           #+#    #+#             */
/*   Updated: 2014/03/09 04:33:44 by ebaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "al-cu.h"
#include "libft.h"

static void	print_information(t_data *d)
{
	ft_putendl("\t\033[4mInformation :\033[0m\n\ti : information\n\tq : quit");
	ft_putendl("\tr : restart game\n\tp : print game");
	ft_putstr("\tjoueur ");
	if (d->player == '1')
	{
		ft_putchar(d->player);
		ft_putstr(" : player : ");
		print_player(d->player);
		ft_putstr("\n\tjoueur ");
		ft_putchar(d->computer);
		ft_putstr(" : computer : ");
		print_player(d->computer);
	}
	else
	{
		ft_putchar(d->computer);
		ft_putstr(" : computer : ");
		print_player(d->computer);
		ft_putstr("\n\tjoueur ");
		ft_putchar(d->player);
		ft_putstr(" : player : ");
		print_player(d->player);
	}
	ft_putendl("\n\tbon chance !");
}

int			information(t_data *d, char *line)
{
	if (!line || !ft_strcmp(line, "i"))
		print_information(d);
	else if (line && !ft_strcmp(line, "q"))
		return (eb_error1("Game quit"));
	else if (line && !ft_strcmp(line, "r"))
	{
		ft_putendl("restart game");
		clear_tab(d);
	}
	else if (line && !ft_strcmp(line, "p"))
		print_p4(d);
	else if (line && ft_is_number(line)
			&& (ft_atoi(line) < 1 || ft_atoi(line) > d->columns))
	{
		ft_putstr("the value have to be between 1 and ");
		ft_putnbr(d->columns);
		ft_putchar('\n');
	}
	else if (line && ft_is_number(line))
		return (eb_put_piece(d, ft_atoi(line) - 1));
	else
		ft_putendl("try an another commande");
	return (0);
}
