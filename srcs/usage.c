/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usage.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebaudet <ebaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/07 21:45:25 by ebaudet           #+#    #+#             */
/*   Updated: 2014/03/07 21:45:25 by ebaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "al-cu.h"

int		usage(int ac, char **av)
{
	int		ret;

	ret = 0;
	if (ac != 3)
		ret = eb_error3("usage : ", av[0], " lines columns");
	if ((ret == 0) && !ft_is_number(av[1]))
		ret = eb_error3("usage : ", av[0]
			, " lines columns.\nline have to be a number");
	if ((ret == 0) && !ft_is_number(av[2]))
		ret = eb_error3("usage : ", av[0]
			, " lines columns\ncolumns have to be a number");
	return (ret);
}
