# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jdavis <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/09 11:55:55 by jdavis            #+#    #+#              #
#    Updated: 2022/06/29 11:52:47 by jdavis           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CHECK = checker
PUSH = push_swap

CC = gcc -Wall -Wextra -Werror -L.

SRC = options.c
SRC += comp.c
SRC += collect_arg.c
SRC += error.c
SRC += solved.c
SRC += create.c
SRC += dup.c
SRC += moves.c
SRC += lis.c
SRC += shifts.c
SRC += five_or_less.c
SRC += options_2.c

all: $(CHECK) $(PUSH)

$(CHECK):
	@make -C libft/ fclean && make -C libft/
	@$(CC) libft/libftprintf.a -o checker $(SRC) checker.c

$(PUSH):
	@make -C libft/ fclean && make -C libft/
	@$(CC) libft/libftprintf.a -o push_swap  $(SRC) push_swap.c

clean:
	@rm -f *.o && make -C libft/ clean

fclean: clean
	@rm -f checker && make -C libft/ fclean
	@rm -f push_swap

re: fclean all
