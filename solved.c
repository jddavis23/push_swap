/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solved.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 13:05:14 by jdavis            #+#    #+#             */
/*   Updated: 2022/06/21 13:16:08 by jdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 *	checking if stack a is sorted and all ints are accounted for.
 */

int	ft_solved(t_info *pass)
{
	int	i;

	i = 0;
	if (pass->a_len == pass->total && pass->b_len == 0)
	{
		while (i < pass->total - 1)
		{
			if (pass->a[i] >= pass->a[i + 1])
				return (-1);
			++i;
		}
		return (1);
	}
	return (-1);
}

/*
 * calculating min and max values in stack a.
 */

void	ft_iniit(t_info *pass)
{
	int	i;

	i = 0;
	pass->min = pass->a[i];
	pass->max = pass->a[i];
	pass->min_pos = i;
	while (i < pass->a_len)
	{
		if (pass->a[i] < pass->min)
		{
			pass->min = pass->a[i];
			pass->min_pos = i;
		}
		if (pass->a[i] > pass->max)
			pass->max = pass->a[i];
		++i;
	}
}

/*
 * checking int array's for incremental sorting status. 
 */

int	ft_all_order(int *arr, int len)
{
	int	i;

	i = 1;
	if (len == 1)
		return (1);
	while (i < len)
	{
		if (arr[i] <= arr[i - 1])
			return (-1);
		++i;
	}
	return (1);
}

/*
 * optimisation for rotating a stack with even and odd totals.
 */

int	ft_which_way(int len, int i)
{
	if (len % 2 == 0)
	{
		if (i < len / 2)
			return (1);
	}
	else if (len % 2 == 1)
	{
		if (i <= len / 2)
			return (1);
	}
	return (0);
}
