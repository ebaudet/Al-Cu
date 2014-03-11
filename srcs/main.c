/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebaudet <ebaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/07 21:06:28 by ebaudet           #+#    #+#             */
/*   Updated: 2014/03/07 21:06:28 by ebaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "al-cu.h"
#include "libft.h"

int		main(int ac, char **av)
{
	t_data	d;

	if (usage(ac, av) == -1)
		return (-1);
	if (get_data(&d, av) == -1)
		return (-1);
	information(&d, NULL);
	who_play(&d);
	return (0);
}
