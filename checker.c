/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 12:28:15 by jdavis            #+#    #+#             */
/*   Updated: 2022/06/30 12:05:42 by jdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 * Assignment function.
 */

static char	**ft_assign(char *opt[])
{
	opt[0] = "sa";
	opt [1] = "sb";
	opt[2] = "ss";
	opt[3] = "pa";
	opt[4] = "pb";
	opt[5] = "ra";
	opt[6] = "rb";
	opt[7] = "rr";
	opt[8] = "rra";
	opt[9] = "rrb";
	opt[10] = "rrr";
	return (opt);
}

/*
 * Comparing moves entered; if entry does not match allowed moves,
 * return 0 (error).
 */

int	ft_options(char *str)
{
	int		i;
	char	*opt[11];

	i = 0;
	ft_assign(opt);
	if (!str)
		return (1);
	while (i < 11)
	{
		if (ft_strcmp(opt[i], str) == 0)
			return (1);
		++i;
	}
	return (0);
}

/*
 * Error checking dupicated numbers, taking moves line by line and
 * applying moves too stack. 
 * After all moves have been applied, check if stack a is sorted.
 */

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
		ft_printf("KO\n");
	else
		ft_printf("OK\n");
	return (0);
}

/*
 * Creating struct with relevant data for parsing.
 * Collecting and application of moves.
 */

int	main(int argc, char *argv[])
{
	int		i;
	t_info	*pass;

	i = 1;
	pass = NULL;
	pass = ft_create(pass, argc, argv);
	if (!pass)
		return (-1);
	if (ft_dup_option_check(pass) == -1)
		return (-1);
	free(pass->a);
	free(pass->b);
	free(pass->lis_arr);
	free(pass);
	return (0);
}
