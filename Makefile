# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ebaudet <ebaudet@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/03/07 21:06:22 by ebaudet           #+#    #+#              #
#    Updated: 2014/03/07 21:06:22 by ebaudet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= puissance4
FILES	= main.c error.c usage.c ft_is_number.c get_data.c print_p4.c
SRCS	= $(addprefix srcs/, $(FILES))
OBJS	= $(SRCS:srcs/%.c=.obj/%.o)
INC		= -I includes -I libft/includes
FLAGS	= -Wall -Wextra -Werror
LIB		= -L libft -lft
CC		= cc

all: $(NAME)

$(NAME): $(OBJS)
	make -C libft
	$(CC) $(FLAGS) $(SRCS) -o $(NAME) $(INC) $(INC) $(LIB)

.obj/%.o: srcs/%.c
	mkdir -p .obj
	$(CC) -c $< -o $@ $(FLAGS) $(INC)

gdb:
	make -C libft
	cc -g $(FLAGS) $(SRCS) -o $(NAME) $(INC) $(INC) $(LIB)
	gdb $(NAME)

clean:
	rm -rf .obj

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all gdb clean fclean re
