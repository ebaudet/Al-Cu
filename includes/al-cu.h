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

typedef struct		s_data
{
	int				lines;
	int				columns;
	char			**tab;
	char			player;
	char			computer;
	char			turn;
}					t_data;

/*
** error.c
*/
int		eb_error1(char *msg1);
int		eb_error2(char *msg1, char *msg2);
int		eb_error3(char *msg1, char *msg2, char *msg3);

/*
** success.c
*/
int		eb_success1(char *msg1, int ret);
int		eb_success2(char *msg1, char *msg2, int ret);
int		eb_success3(char *msg1, char *msg2, char *msg3, int ret);

/*
** usage.c
*/
int		usage(int ac, char **av);

/*
** ft_is_number.c
*/
int		ft_is_number(char *str);

/*
** get_data.c
*/
int		get_data(t_data *d, char **av);
int		init_tab(t_data *d);
void	clear_tab(t_data *d);

/*
** print_p4.c
*/
void	print_nb(int nb, int width, int center);
void	print_p4(t_data *d);
void	print_player(char player);

/*
** random.c
*/
int		eb_random();

/*
** option.c
*/
int		information(t_data *d, char *line);

/*
** play_game.c
*/
int		play_game(t_data *d);
int		eb_put_piece(t_data *d, int pos);

/*
** game_analyses.c
*/
int		game_analyse(t_data *d, char player);
int		diag_analyse(t_data *d, char player);
int		diag_inverse_analyse(t_data *d, char player);
int		vertical_analyse(t_data *d, char player);
int		horizontal_analyse(t_data *d, char player);

#endif /* !AL_CU_H */
