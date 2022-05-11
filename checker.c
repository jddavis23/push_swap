/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 12:28:15 by jdavis            #+#    #+#             */
/*   Updated: 2022/05/11 16:20:30 by jdavis           ###   ########.fr       */
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

static int	ft_dup_option_check(t_info *pass)
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
	if (ft_dup(pass) == -1 || error == -1)
	{
		return (ft_error(pass));
	}
	return (0);
}

t_info	*ft_create(t_info *pass, int argc)
{
	pass = (t_info *) malloc(sizeof(t_info));
	if (!pass)
		return (NULL);
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
	int		len;
	t_info	*pass;

	i = 1;
	len = 0;
	pass = NULL;
	pass = ft_create(pass, argc);
	if (!pass)
	{
		//return
	}
	if (argc > 1)
	{
		while (i < argc)
		{
			while (len < (int)ft_strlen(argv[i]))
			{
				if ((len > 0 && argv[i][len] == '-' && (argv[i][len] < '0' || argv[i][len] > '9')))
					return (ft_error(pass));
				++len;
			}
			if (argv[i][0] == '-' && len >= 11 && ft_strcmp("-2147483648", argv[i]) < 0)
				return (ft_error(pass));
			if (ft_strcmp("2147483647", argv[i]) < 0 && len >= 10)
				return (ft_error(pass));
			pass->a[i - 1] = ft_atoi(argv[i]);
			++i;
			len = 0;
		}
	}
	if (ft_dup_option_check(pass) == -1)
		return (1);
	//i = 0;
	//while (i < argc - 1)
	//	ft_printf("%i\n", pass->a[i++][0]);
	return (0);
}
