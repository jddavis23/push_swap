/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 13:11:35 by jdavis            #+#    #+#             */
/*   Updated: 2022/06/17 13:22:59 by jdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
static int	ft_less_than(t_info *pass)
{
	int	i;

	i = 0;
	while (i < pass->a_len)
	{
		if (pass->a[i] > pass->b_hold || ((pass->b_hold < pass->min ||
						pass->b_hold > pass->max) && pass->a[i] == pass->min))
		{
			pass->a_hold = pass->a[i];
			break;
		}
		++i;
	}
	return (i);
}

static int	ft_greater_than(t_info *pass)
{
	int	i;

	i = 0;
	while (pass->a[i] > pass->b_hold)
	{
		if ((pass->b_hold < pass->min || pass->b_hold > pass->max) && pass->a[i] == pass->min)
			break;
		++i;
	}
	while (i < pass->a_len)
	{
		if (pass->a[i] > pass->b_hold || ((pass->b_hold < pass->min ||
						pass->b_hold > pass->max) && pass->a[i] == pass->min))
		{
			pass->a_hold = pass->a[i];
			break;
		}
		++i;
	}
	return (i);
}

int	ft_moves(t_info *pass)
{
	int	i;

	i = 0;
	if (pass->a[0] < pass->b_hold)
		i = ft_less_than(pass);
	else if ((pass->a[0] > pass->b_hold && pass->a[pass->a_len - 1] <
				pass->b_hold) || (pass->a[0] == pass->min && (pass->b_hold <
						pass->min || pass->b_hold > pass->max)))
		pass->a_hold = pass->a[i];
	else if (pass->a[0] > pass->b_hold)
		i = ft_greater_than(pass);
	return (i);
}
