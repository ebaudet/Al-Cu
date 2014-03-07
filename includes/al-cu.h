/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   al-cu.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebaudet <ebaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/07 21:06:39 by ebaudet           #+#    #+#             */
/*   Updated: 2014/03/07 21:06:39 by ebaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AL_CU_H
# define AL_CU_H

/*
** error.c
*/
int		eb_error(char *msg1, char *msg2, char *msg3);

/*
** usage.c
*/
int		usage(int ac, char **av);

/*
** ft_is_number.c
*/
int		ft_is_number(char *str);

#endif /* !AL_CU_H */
