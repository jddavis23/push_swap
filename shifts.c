/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shifts.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 12:38:58 by jdavis            #+#    #+#             */
/*   Updated: 2022/06/21 13:07:55 by jdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*helper function for ft_closer*/

static int	ft_helper_closer(t_info *pass, int j, int i)
{
	if (pass->b_len - j < i)
	{
		pass->rev = 2;
		pass->b_hold = pass->b[j];
	}
	else
	{
		pass->rev = 1;
		pass->b_hold = pass->b[i];
	}
	return (1);
}

/*finding the closest int from top down and bottom up, deciding which way
 * stack be should be rotated*/

int	ft_closer(t_info *pass, int min, int max)
{
	int	i;
	int	j;

	i = 0;
	j = pass->b_len - 1;
	ft_iniit(pass);
	while (i < pass->b_len - 1)
	{
		if (pass->b[i] >= min && pass->b[i] <= max)
			break ;
		++i;
	}
	while (j > 0)
	{
		if (pass->b[j] >= min && pass->b[j] <= max)
			break ;
		--j;
	}
	if (pass->b[i] < min || pass->b[i] > max)
		i = -1;
	if (pass->b[j] < min || pass->b[j] > max)
		j = -1;
	if (i == -1 && j == -1)
		return (-1);
	return (ft_helper_closer(pass, j, i));
}

/*helper function for ft_shift. reverse rotating stack b
 * and moving stack a to match*/

static void	ft_helper_shift(t_info *pass, int i)
{
	if (!ft_which_way(pass->a_len, i))
	{
		while (pass->a[0] != pass->a_hold && pass->b[0] != pass->b_hold)
			ft_rrr(pass, 1);
		while (pass->a[0] != pass->a_hold)
			ft_rra(pass, 1);
	}
	else
	{
		while (pass->a[0] != pass->a_hold)
			ft_ra(pass, 1);
	}
	while (pass->b[0] != pass->b_hold)
		ft_rrb(pass, 1);
}

/*implimenting rotations on stack a and b. Utilizing double 
 * moves where ever possible. Rotating stack b and stack a to match*/

void	ft_shift(t_info *pass, int i)
{
	if (pass->rev == 1)
	{
		if (ft_which_way(pass->a_len, i))
		{
			while (pass->a[0] != pass->a_hold && pass->b[0] != pass->b_hold)
				ft_rr(pass, 1);
			while (pass->a[0] != pass->a_hold)
				ft_ra(pass, 1);
		}
		else
		{
			while (pass->a[0] != pass->a_hold)
				ft_rra(pass, 1);
		}
		while (pass->b[0] != pass->b_hold)
			ft_rb(pass, 1);
	}
	else
		ft_helper_shift(pass, i);
}

/*dividing range from min to max into subsections, to be able to specificy 
 * shifting of stack b to a, limiting over rotation of stack a */

void	ft_next_up(t_info *pass)
{
	int			i;
	static int	up = 1;
	float		percent;

	if (pass->total > 250)
		percent = 20.0;
	else
		percent = 10.0;
	if (ft_closer(pass, pass->zero_et, pass->zero_et + (int)((pass->range
				/ percent) * up)) == -1)
		++up;
	if (ft_closer(pass, pass->zero_et, pass->zero_et + (int)((pass->range
				/ percent) * up)) == 1)
	{
		i = ft_moves(pass);
		ft_shift(pass, i);
	}
	ft_pa(pass, 1);
}
