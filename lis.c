/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 13:29:01 by jdavis            #+#    #+#             */
/*   Updated: 2022/06/29 13:10:28 by jdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 * Return the max of two intergers
 */

static int	ft_max_of(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

/*
 * Helper function for ft_lis dynamically finding the longest
 * incrimenting subsequence (lis); addng up the values of previous int's
 * that are less than current value in the pass->lis_arr.
 */

static void	ft_helper_lis(t_info *pass)
{	
	int	i;
	int	j;

	i = 0;
	while (i < pass->a_len)
		pass->lis_arr[i++] = 1;
	i = 1;
	while (i < pass->a_len)
	{
		j = 0;
		while (j < i)
		{
			if (pass->a[j] < pass->a[i])
				pass->lis_arr[i] = ft_max_of(pass->lis_arr[i], pass->lis_arr[j]
						+ 1);
			++j;
		}
		++i;
	}
}

/*
 *  After finding the lis, the position of the final value of the lis;
 *  this is used as an end condition to collecting the values in the lis.
 */

void	ft_lis(t_info *pass)
{
	int	i;

	i = 0;
	ft_helper_lis(pass);
	i = 0;
	pass->lis = pass->lis_arr[0];
	pass->lis_pos = 0;
	while (i < pass->a_len)
	{
		if (pass->lis_arr[i] > pass->lis)
		{
			pass->lis_pos = i;
			pass->lis = pass->lis_arr[i];
		}
		++i;
	}
}

/*
 * Recursively finding the values of the lis, only collecting the values of 
 * the relative index in the pass->lis_arr. If a value is placed and the
 * function cannot complete pass->sequence array, the function returns and
 * retries new value.
 */

void	ft_build_lis(t_info *pass, int complete, int i)
{
	int			flag;
	static int	stop = 0;

	flag = 0;
	while (complete < pass->lis)
	{
		while (i <= pass->lis_pos && !stop && (ft_all_order(pass->sequence,
					pass->lis) != 1 || pass->sequence[pass->lis - 1]
				!= pass->a[pass->lis_pos]))
		{
			if (pass->lis_arr[i] == complete + 1)
			{
				pass->sequence[complete] = pass->a[i];
				flag = 1;
			}
			if (flag && ft_all_order(pass->sequence, complete + 1) == 1
				&& complete == pass->lis - 1 && pass->sequence[complete]
				== pass->a[pass->lis_pos] && ++stop == 1)
				break ;
			else if (flag && ft_all_order(pass->sequence, complete + 1) == 1)
			{
				ft_build_lis(pass, complete + 1, i + 1);
				if (!stop)
					pass->sequence[complete + 1] = pass->min - 1;
			}
			flag = 0;
			++i;
		}
		return ;
	}
}
