# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wbouwach <wbouwach@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/13 00:26:00 by wbouwach          #+#    #+#              #
#    Updated: 2022/12/17 02:23:41 by wbouwach         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
NAME_B= checker
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

SRC = check_args errors helpers init push_main pushs rot_rev rotates sort_max10 sort_tab sorting_alg stack_helpers swaps
SRC_B= get_next_line get_next_line_utils bonus_part check_args errors helpers init pushs rot_rev rotates sort_max10 sort_tab sorting_alg stack_helpers swaps

OBJ = $(SRC:=.o)
OBJ_B = $(SRC_B:=.o)

%.o:%.c
	$(CC) $(CFLAGS) -c $<

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

bonus: $(OBJ_B)
	$(CC) $(CFLAGS) -o $(NAME_B) $(OBJ_B)

clean:
	$(RM) $(OBJ) $(OBJ_B)

fclean: clean
	$(RM) $(NAME) $(NAME_B)
	
re: fclean all