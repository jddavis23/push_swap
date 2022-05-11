/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 12:28:15 by jdavis            #+#    #+#             */
/*   Updated: 2022/05/11 13:56:49 by jdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_error(int **a, int **b, int index)
{
	int	i;

	i = 0;
	if (a && b)
		index = 0;
	/*while (i <= index)
	{
		if (a)
			free(a[i]);
		if (b)
			free(b[i++]);
	}
	free(a);
	free(b);
	a = NULL;
	b = NULL;
	USE ft_double_arrdel*/
	ft_printf("Error\n");
	return (-1);
}

static int	ft_dup(int **a, int total)
{
	int	i;
	int	j;

	i = 0;
	while (i < total)
	{
		ft_printf("%i--\n", (*a)[i]);
		j = 1;
		while (i + j < total)
		{
			if ((*a)[i] == (*a)[i + j])
				return (-1);
			++j;
		}
		++i;
	}
	ft_printf("1\n");
	return (0);
}

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

static int	ft_dup_option_check(int **a, int **b, int total)
{
	int		ret;
	char	*option;
	int		error;

	ret = 1;
	error = 0;
	while (ret == 1)
	{
		ret = get_next_line(0, &option);
		if (!ft_options(option))
			error = -1;

	}
	if (ft_dup(a, total + 1) == -1 || error == -1)
	{
		ft_printf("2\n");
		return (ft_error(a, b, total + 1));
	}
	return (0);
}


int main(int argc, char *argv[])
{
	int		i;
	int		len;
	char	*proc;
	int		ret;
	t_info	*pass;
	int		th[] = {23, 3 ,4};

	i = 1;
	len = 0;
	proc = NULL;
	ret = 1;
	pass = (t_info *) malloc(sizeof(t_info));
	if (!pass)
		return (-1);
	pass->a = (int **) malloc((argc - 1) * sizeof(int *));
	pass->b = (int **) malloc((argc - 1) * sizeof(int *));
	if (!pass->a || !pass->b)
	{
		//free whichever
		//return
	}
	while (i < argc)
	{
		pass->a[i - 1] = (int *) malloc(sizeof(int));
		pass->b[i - 1] = (int *) malloc(sizeof(int));
		if (!pass->a[i] || !pass->b[i])
		{
			//delete
			////return
		}
		++i;
	}
	pass->a_len = argc - 1;
	pass->b_len = 0;
	i = 1;
	if (argc > 1)
	{
		while (i < argc)
		{
			while (len < (int)ft_strlen(argv[i]))
			{
				if ((len > 0 && argv[i][len] == '-' && (argv[i][len] < '0' || argv[i][len] > '9'))) //not workin as should
					return (ft_error(pass->a, pass->b, argc));
				++len;
			}
			if (argv[i][0] == '-' && len >= 11 && ft_strcmp("-2147483648", argv[i]) < 0)
				return (ft_error(pass->a, pass->b, argc));
			if (ft_strcmp("2147483647", argv[i]) < 0 && len >= 10)
				return (ft_error(pass->a, pass->b, argc));
			(*pass->a[i - 1]) = ft_atoi(argv[i]);
			++i;
			len = 0;
		}
	}
	i = 0;
	while (i < argc - 1)
		ft_printf("%i\n", pass->a[i++][0]);
	if (ft_dup_option_check(pass->a, pass->b, argc - 1) == -1)
		return (1);
	i = 0;
	//while (i < argc - 1)
	//	ft_printf("%i\n", pass->a[i++][0]);
	return (0);
}
