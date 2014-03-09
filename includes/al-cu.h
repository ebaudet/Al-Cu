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
void	random_player(t_data *d);

/*
** print_p4.c
*/
void	print_nb(int nb, int width, int center);
void	print_p4(t_data *d);
void	print_player(char player);

/*
** random.c
*/
int		eb_random(void);

/*
** option.c
*/
int		information(t_data *d, char *line);

/*
** play_game.c
*/
void	who_play(t_data *d);
int		game_finish(t_data *d, char player);
int		play_game(t_data *d);
int		eb_put_piece(t_data *d, int pos, char print);
int		eb_release_piece(t_data *d, int pos);

/*
** game_analyses.c
*/
int		game_analyse(t_data *d, char player);
int		diag_analyse(t_data *d, char player);
int		diag_inverse_analyse(t_data *d, char player);
int		vertical_analyse(t_data *d, char player);
int		horizontal_analyse(t_data *d, char player);

/*
** computer.c
*/
int		computer_play(t_data *d);
int		min(t_data *d, int x, char player, int depth);
int		max(t_data *d, int x, char player, int depth);
int		get_map_value(t_data *d);
int		wins(t_data *d, int row, int col);

/*
** analyse_cell.c
*/
int		get_cell_value(t_data *d, int row, int col);
int		eb_can_play(t_data *d, int x);
int		ft_abs(int i);
int		get_horizontal_number(t_data *d, int row, int col);
int		get_vertical_number(t_data *d, int row, int col);

/*
** analyse_cell.c
*/
int		get_diagonal_numbers(t_data *d, int row, int col);
int		get_diagonal_number1(t_data *d, int row, int col);
int		get_diagonal_number2(t_data *d, int row, int col);
int		get_diagonal_number3(t_data *d, int row, int col);
int		get_diagonal_number4(t_data *d, int row, int col);

#endif /* !AL_CU_H */
