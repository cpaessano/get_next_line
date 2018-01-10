# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: csilva <csilva@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/21 19:03:13 by csilva            #+#    #+#              #
#    Updated: 2017/12/04 16:19:52 by csilva           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = get_next_line

SRC = get_next_line.c 

OBJS = get_next_line.o

CFLGAS = -Wall -Wextra -Werror

LDF = -L libft/ -lft

all: $(NAME)

$(NAME):
	@make -C libft/ all
	@gcc $(CFLGAS) $(LDF) $(SRC) -I ./ -I libft/includes -o $(NAME)

clean:
	@make -C libft/ clean
	@/bin/rm -f $(OBJS)

fclean: clean
	@make -C libft/ fclean
	@/bin/rm -f $(NAME)

re: fclean all