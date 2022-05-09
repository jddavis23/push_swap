# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jdavis <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/09 11:55:55 by jdavis            #+#    #+#              #
#    Updated: 2022/05/09 12:09:40 by jdavis           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = checker

CC = gcc -Wall -Wextra -Werror -L.

SRC = 

all: $(NAME)

$(NAME):
	@make -C libft/ fclean && make -C libft/
	#@$(CC) libft/libftprintf.a (compile c files for checker)
	#@$(CC) libft/libftprintf.a (compile c files for push_swap)
