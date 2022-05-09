# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jdavis <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/09 11:55:55 by jdavis            #+#    #+#              #
#    Updated: 2022/05/09 12:45:42 by jdavis           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = checker

CC = gcc -Wall -Wextra -Werror -L.

SRC = 

all: $(NAME)

$(NAME):
	@make -C libft/ fclean && make -C libft/
	@$(CC) libft/libftprintf.a -o checker checker.c
	#@$(CC) libft/libftprintf.a (compile c files for push_swap)

clean:
	@rm -f *.o && make -C libft/ clean

fclean: clean
	@rm -f checker && make -C libft/ fclean

re: fclean all
