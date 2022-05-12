/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 12:28:15 by jdavis            #+#    #+#             */
/*   Updated: 2022/05/12 18:07:05 by jdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_error(t_info *pass)
{
	int	i;

	i = 0;
	if (pass->a && pass->b)
		pass->total = 0;
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

static int	ft_dup(t_info *pass)
{
	int	i;
	int	j;

	i = 0;
	while (i <= pass->total)
	{
		j = 1;
		while (i + j <= pass->total)
		{
			if (pass->a[i] == pass->a[i + j])
				return (-1);
			++j;
		}
		++i;
	}
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

int	ft_solved(t_info *pass)
{
	int	i;

	i = 0;
	if (pass->a_len == pass->total && pass->b_len == 0)
	{
		while (i < pass->total - 1 )
		{
			if (pass->a[i] >= pass->a[i + 1])
				return (-1);
			++i;
		}
	}
	return (0);
}

static void	ft_compare(t_info *pass, char **line)
{
	if (ft_strcmp("sa", *line) == 0 && *line)
		ft_sa(pass);
	if (ft_strcmp("sb", *line) == 0 && *line)
		ft_sb(pass);
	if (ft_strcmp("pa", *line) == 0 && *line)
		ft_pa(pass);
	if (ft_strcmp("pb", *line) == 0 && *line)
		ft_pb(pass);
	if (ft_strcmp("ra", *line) == 0 && *line)
		ft_ra(pass);
	if (ft_strcmp("rb", *line) == 0 && *line)
		ft_rb(pass);
	if (ft_strcmp("rr", *line) == 0 && *line)
		ft_rr(pass);
	if (ft_strcmp("rra", *line) == 0 && *line)
		ft_rra(pass);
	if (ft_strcmp("rrb", *line) == 0 && *line)
		ft_rrb(pass);
	if (ft_strcmp("rrr", *line) == 0 && *line)
		ft_rrr(pass);
}

static int	ft_dup_option_check(t_info *pass)
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

int	ft_collect(t_info *pass, char *argv[], int *i, int choice)
{
	int	len;

	len = 0;
	while (len < (int)ft_strlen(argv[*i]))
	{
		if ((len > 0 && argv[*i][len] == '-' && (argv[*i][len] < '0' || argv[*i][len] > '9')))
			return (ft_error(pass));
		++len;
	}
	if (argv[*i][0] == '-' && len >= 11 && ft_strcmp("-2147483648", argv[*i]) < 0)
		return (ft_error(pass));
	if (ft_strcmp("2147483647", argv[*i]) < 0 && len >= 10)
		return (ft_error(pass));
	if (choice == 1)
		pass->a[*i - 1]  = ft_atoi(argv[*i]);
	++(*i);
	return (1); //this should return a count of ints
}

t_info	*ft_create(t_info *pass, int argc, char *argv[])
{
	int	count;
	int	i;

	count = 0;
	i = 1;
	if (argc == 1 && argv)
		return (NULL);
	pass = (t_info *) malloc(sizeof(t_info));
	if (!pass)
		return (NULL);
	//while (
	pass->a = (int *) malloc((argc - 1) * sizeof(int *));
	pass->b = (int *) malloc((argc - 1) * sizeof(int *));
	if (!pass->a || !pass->b)
	{
		//free whichever
		//return
	}
	pass->a_len = argc - 1;
	pass->b_len = 0;
	pass->total = argc - 1;
	return (pass);
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
	if (argc > 1)
	{
		while (i < argc) //have while loop inside ft_collect
		{
			if (ft_collect(pass, argv, &i, 1) == -1)
				return (-1);
		}
		//if (ft_collect(pass, argv) == -1)  MAKE THIS WORK
		//	return (-1);
	}
	if (ft_dup_option_check(pass) == -1)
		return (1);


	i = 0;
	ft_printf("2nd stack a\n");
	while (i < pass->a_len)
	{
		ft_printf("%i\n", pass->a[i++]);
	}
	i = 0;
	ft_printf("stack b\n");
	while (i < pass->b_len)
	{
		ft_printf("%i\n", pass->b[i++]);
	}
	return (0);
}
