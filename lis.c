/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 13:29:01 by jdavis            #+#    #+#             */
/*   Updated: 2022/06/20 13:51:01 by jdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_max_of(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

static void	ft_helper(t_info *pass)
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
				pass->lis_arr[i] = ft_max_of(pass->lis_arr[i], pass->lis_arr[j] + 1);
			++j;
		}
		++i;
	}
}
void	ft_lis(t_info *pass)
{
	int	i;
	//int	j;

	i = 0;
	pass->lis_arr = (int *) malloc(pass->a_len * sizeof(int));
	if (!pass->lis_arr)
	{
		//printf error message
		return;
	}
	/*while (i < pass->a_len)
		pass->lis_arr[i++] = 1;
	i = 1;
	while (i < pass->a_len)
	{
		j = 0;
		while (j < i)
		{
			if (pass->a[j] < pass->a[i])
				pass->lis_arr[i] = ft_max_of(pass->lis_arr[i], pass->lis_arr[j] + 1);
			++j;
		}
		++i;
	}*/
	ft_helper(pass);
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

void	ft_build_lis(t_info *pass, int complete, int i)
{
	int flag = 0;
	static int stop = 0;

	while (complete < pass->lis)
	{
		while (i <= pass->lis_pos && !stop &&  (ft_all_order(pass->sequence,
						pass->lis) != 1 ||  pass->sequence[pass->lis - 1]
					!= pass->a[pass->lis_pos]))
		{
			if (pass->lis_arr[i] == complete + 1)
			{
				pass->sequence[complete] = pass->a[i];
				flag = 1;
			}
			if (flag && ft_all_order(pass->sequence, complete + 1) == 1 &&
					complete == pass->lis - 1 && pass->sequence[complete] ==
					pass->a[pass->lis_pos] && ++stop == 1)
			{
				//++stop;
				break ;
			}
			else if (flag && ft_all_order(pass->sequence, complete + 1) == 1)
			{
				ft_build_lis(pass, complete + 1, i + 1);
				if (!stop)
					pass->sequence[complete + 1] = pass->min - 1;
			}
			flag = 0;
			++i;
		}
		return;
	}
}
