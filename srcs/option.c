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

int		information(t_data *d, char *line)
{
	if (!line || !ft_strcmp(line, "h"))
	{
		ft_putendl("information :\n\th : help\n\tq : quit\n\tr : restart game");
		ft_putstr("bon chance ");
		ft_putstr(d->name);
		ft_putendl(" !");
	}
	else if (line && !ft_strcmp(line, "q"))
		return (eb_error1("Game quit"));
	else if (line && !ft_strcmp(line, "r"))
	{
		ft_putendl("restart game");
		clear_tab(d);
	}
	else if (line && ft_is_number(line))
	{
		ft_putendl("proceed");
	}
	else
	{
		ft_putendl("try an another commande");
	}
	return (0);
}
