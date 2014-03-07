/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebaudet <ebaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/07 21:37:37 by ebaudet           #+#    #+#             */
/*   Updated: 2014/03/07 21:37:37 by ebaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		eb_error(char *msg1, char *msg2, char *msg3)
{
	ft_putstr_fd(msg1, 0);
	ft_putstr_fd(msg2, 0);
	ft_putendl_fd(msg3, 0);
	return (-1);
}
