/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 12:28:15 by jdavis            #+#    #+#             */
/*   Updated: 2022/06/28 18:01:46 by jdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_options(char *str)
{
	int		i;
	int		choice;
	char	*opt[] = {
		"sa",
		"sb",
		"ss",
		"pa",
		"pb",
		"ra",
		"rb",
		"rr",
		"rra",
		"rrb",
		"rrr"};

	i = 0;
	choice = 0;
	if (!str)
		return (1);
	while (i < 11)
	{
		if (ft_strcmp(opt[i], str) == 0)
		{
			choice = 1;
			break ;
		}
		++i;
	}
	return (choice);
}

int	ft_dup_option_check(t_info *pass)
{
	int		ret;
	char	*line;
	int		error;

	ret = 1;
	error = 0;
	if (ft_dup(pass) == -1)
		return (ft_error(pass));
	while (ret == 1)
	{
		ret = get_next_line(0, &line);
		if (ft_options(line) == 0)
			error = -1;
		ft_compare(pass, &line);
		free(line);
	}
	if (error == -1)
		return (ft_error(pass));
	if (ft_solved(pass) == -1)
	{
		//delete & free structs
		ft_printf("KO\n");
	}
	else
		ft_printf("OK\n");
	return (0);
}

int main(int argc, char *argv[])
{
	int		i;
	t_info	*pass;

	i = 1;
	pass = NULL;
	pass = ft_create(pass, argc, argv);
	if (!pass)
	{
		//return
		return (0);
	}
	if (ft_dup_option_check(pass) == -1)
		return (1);
	return (0);
}
