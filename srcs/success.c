/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   success.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebaudet <ebaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/09 19:11:22 by ebaudet           #+#    #+#             */
/*   Updated: 2014/03/09 19:11:22 by ebaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		eb_success1(char *msg1, int ret)
{
	ft_putendl(msg1);
	return (ret);
}

int		eb_success2(char *msg1, char *msg2, int ret)
{
	ft_putstr(msg1);
	ft_putendl(msg2);
	return (ret);
}

int		eb_success3(char *msg1, char *msg2, char *msg3, int ret)
{
	ft_putstr(msg1);
	ft_putstr(msg2);
	ft_putendl(msg3);
	return (ret);
}
