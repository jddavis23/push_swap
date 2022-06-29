/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 11:44:30 by jdavis            #+#    #+#             */
/*   Updated: 2022/06/29 12:26:38 by jdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 * Soring int's using a bubble sort to be able to calculate the mid point,
 * to allow for quick sorting in stack b when pushed
 */

void	ft_median(t_info *pass)
{
	int	i;
	int	temp;

	i = -1;
	while (++i < pass->a_len)
		pass->b[i] = pass->a[i];
	while (ft_all_order(pass->b, pass->a_len) == -1)
	{
		i = 0;
		while (i + 1 < pass->a_len)
		{
			if (pass->b[i] > pass->b[i + 1])
			{
				temp = pass->b[i];
				pass->b[i] = pass->b[i + 1];
				pass->b[i + 1] = temp;
			}
			++i;
		}
	}
	pass->zero_et = pass->min;
	pass->range = (long int)pass->max - (long int)pass->min;
	pass->mid = pass->b[pass->a_len / 2];
}

/*
 * Rotating all numbers for the longest incrementing subsequent (lis) to 
 * the bottom.
 * Pushing others not part of lis to stack b, quick-sorting values
 * greater than the median to the bottom of stack b.
 */

void	ft_push_b(t_info *pass)
{
	int	j;

	j = 0;
	if (ft_all_order(pass->a, pass->a_len) == -1)
	{
		while (ft_all_order(pass->a, pass->a_len) == -1 && pass->a_len > 5)
		{
			while (j < pass->lis && pass->a[0] == pass->sequence[j])
			{
				if (pass->b_len > 1 && pass->b[0] > pass->mid)
					ft_rr(pass, 1);
				else
					ft_ra(pass, 1);
				++j;
			}
			ft_pb(pass, 1);
			if (pass->b_len > 1 && pass->b[0] > pass->mid)
				ft_rb(pass, 1);
		}
	}
}

/*
 * Pushing all int's in stack b, back to a, in the correct position.
 * After everything is pushed to a, move the min to the top of a.
 */

void	ft_push_a(t_info *pass)
{
	while (pass->b_len > 0)
		ft_next_up(pass);
	ft_iniit(pass);
	while (pass->a[0] != pass->min)
	{
		if (pass->min_pos < pass->a_len / 2)
			ft_ra(pass, 1);
		else
			ft_rra(pass, 1);
	}
	free(pass->a);
	free(pass->b);
	free(pass->lis_arr);
	free(pass->sequence);
	free(pass);
}

int	main(int argc, char *argv[])
{
	t_info	*pass;
	int		j;

	j = 0;
	pass = NULL;
	pass = ft_create(pass, argc, argv);
	if (!pass)
		return (-1);
	if (ft_dup(pass) == -1)
		return (ft_error(pass));
	ft_lis(pass);
	ft_iniit(pass);
	pass->sequence = (int *)malloc(pass->lis * sizeof(int));
	if (!pass->sequence)
		return (ft_error(pass));
	while (j < pass->lis)
		pass->sequence[j++] = pass->min - 1;
	ft_median(pass);
	ft_build_lis(pass, 0, 0);
	ft_push_b(pass);
	ft_five_or_less(pass);
	ft_iniit(pass);
	ft_push_a(pass);
	return (0);
}
