/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   five_or_less.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 11:04:55 by jdavis            #+#    #+#             */
/*   Updated: 2022/06/29 11:35:58 by jdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 * ss or sa depending on if stack b is populated, trying to keep the smallest
 * value at the top.
 */

static void	ft_swap_b(t_info *pass, int choice)
{
	if (choice)
	{
		if (pass->a[1] < pass->a[0] && pass->a[0] < pass->a[pass->a_len - 1])
		{
			if (pass->b_len == 2 && pass->b[1] < pass->b[0])
				ft_ss(pass, 1);
			else
				ft_sa(pass, 1);
		}
	}
	else
	{
		if (pass->b_len == 2 && pass->b[1] < pass->b[0])
			ft_ss(pass, 1);
		else
			ft_sa(pass, 1);
	}
}

/*
 * Helper function for ft_five_or_less; moving larger values to bottom
 * of stack a and then deciding when to push to b, if a can't be sorted
 * if 2 moves or less.
 */

static void	ft_helper(t_info *pass)
{
	while (pass->a[0] > pass->a[pass->a_len - 1])
	{
		ft_ra(pass, 1);
		ft_swap_b(pass, 1);
	}
	if (ft_all_order(pass->a, pass->a_len) == -1
		&& pass->a[pass->a_len - 1] > pass->a[1])
		ft_pb(pass, 1);
	if (pass->a[pass->a_len - 1] > pass->a[0] && pass->a[pass->a_len - 1]
		< pass->a[1])
	{
		ft_rra(pass, 1);
		ft_swap_b(pass, 0);
	}
}

/*
 * Five or less int's 
 */

void	ft_five_or_less(t_info *pass)
{
	while (ft_all_order(pass->a, pass->a_len) == -1)
	{
		ft_iniit(pass);
		ft_swap_b(pass, 1);
		while (pass->a[pass->a_len - 1] < pass->a[0])
		{
			if (pass->a_len == 4 && ft_all_order(pass->a, pass->a_len - 1) == 1
				&& pass->a[pass->a_len - 1] == pass->min && pass->b[0]
				> pass->min && pass->b[0] < pass->a[1])
				break ;
			ft_rra(pass, 1);
			if (pass->a[1] < pass->a[0])
			{
				if (pass->b_len == 2 && pass->b[1] < pass->b[0])
					ft_ss(pass, 1);
				else
					ft_sa(pass, 1);
			}
		}
		if (pass->a_len == 4 && ft_all_order(pass->a, pass->a_len - 1) == 1
			&& pass->a[pass->a_len - 1] == pass->min && pass->b[0]
			> pass->min && pass->b[0] < pass->a[1])
			break ;
		ft_helper(pass);
	}
}
