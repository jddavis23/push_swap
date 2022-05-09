/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 12:28:15 by jdavis            #+#    #+#             */
/*   Updated: 2022/05/09 18:50:10 by jdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_dup(int **a, int count)
{
	int	i;
	int	j;

	i = 0;
	while (i < count)
	{
		j = 1;
		while (i + j < count)
		{
			if ((*a)[i] == (*a)[i + j])
			{
				ft_printf("dup\n");
				return (-1);
			}
			++j;
		}
		++i;
	}
	return (0);
}

int main(int argc, char *argv[])
{
	int	**a;
	int **b;
	int	i;
	int	len;

	i = 1;
	a = NULL;
	b = NULL;
	len = 0;
	if (argc > 1)
	{
		a = (int **) malloc((argc - 1) * sizeof(int *));
		b = (int **) malloc((argc - 1) * sizeof(int *));
		while (i < argc && a && b)
		{
			//if (!a[j])
				//delete all and malloc and exit
			while (len < (int)ft_strlen(argv[i]))
			{
				if ((argv[i][len] < '0' && argv[i][len] > '9') || (argv[i][len] == '-' && len != 0))
					//error message and wipe mem	
				ft_putchar('*');
				++len;
			}
			if (argv[i][0] == '-' && len >= 11 && ft_strcmp("-2147483648", argv[i]) < 0)
			{	
				//error message wipe mem
				ft_printf("Error");
			}
			if (ft_strcmp("2147483647", argv[i]) < 0 && len >= 10)
			{
				//error message 
				ft_printf("Error");
			}
			a[i - 1] = (int *) malloc(sizeof(int));
			if (a[i - 1])
			{
				(*a)[i - 1] = ft_atoi(argv[i]);
				++i;
			}
			len = 0;
		}
	}
	ft_dup(a, argc - 1);
	i = 0;
	while (i < argc - 1)
		ft_printf("%i\n", ((*a)[i++]));
	return (0);
}
