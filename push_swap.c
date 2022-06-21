/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 11:44:30 by jdavis            #+#    #+#             */
/*   Updated: 2022/06/21 13:38:07 by jdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 * Soring int's using a bubble sort to be able to calculate the mid point,
 * to allow for quick sorting in stack b when pushed
 */

void	ft_median(t_info *pass)
{
   	int i;
	int temp;

	i = 0;
    while (i < pass->a_len)
    {
        pass->b[i] = pass->a[i];
        ++i;
    }
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
	pass->range = pass->max - pass->min;
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
		while (ft_all_order(pass->a, pass->a_len) == -1)
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
 */

void	ft_push_a(t_info *pass)
{
	while (pass->b_len > 0)
		ft_next_up(pass);
	//ft_iniit(pass);
	while (pass->a[0] != pass->min)
	{
		if (pass->min_pos < pass->a_len / 2)
			ft_ra(pass, 1);
		else
			ft_rra(pass, 1);
	}
}

int	main(int argc, char *argv[])
{
	t_info *pass;
	int j = 0;

	j = 0;
	pass = NULL;
	pass = ft_create(pass, argc, argv);
	if (!pass)
		return (-1);
	if (ft_collect(pass, argv, argc) == -1)
		return (-1);
	if (ft_dup(pass) == -1)
		return (ft_error(pass));
	ft_lis(pass);
	ft_iniit(pass);
	pass->sequence = (int *)malloc(pass->lis * sizeof(int));
	if (!pass->sequence)
	{
		//delete and return
		return (0);
	}
	while (j < pass->lis)
		pass->sequence[j++] = pass->min - 1;
	ft_median(pass);
	ft_build_lis(pass, 0, 0);
	ft_push_b(pass);
	/*while (ft_all_order(pass->a, pass->a_len) == -1)
	{

			ft_printf("2\n");
		while (pass->a[0] > pass->a[1]  && pass->a[0] < pass->a[pass->a_len - 1]) //find away of getting the longest ascending sequence to the top
		{
			if (pass->b_len > 0 && pass->b[0] > pass->a[pass->a_len - 1] && pass->b[0] < pass->a[0])
			{
				ft_next_up(pass);
				ft_pa(pass);
				ft_printf("pa\n");
			}
			if (pass->b_len > 1 && pass->b[0] < pass->b[1])
			{
				ft_ss(pass);
				ft_printf("ss\n");
			}
			else
			{
				ft_sa(pass);
				ft_printf("sa\n");
			}
			while ((pass->a[pass->a_len - 1] > pass->a[0] && pass->a[1] > pass->a[pass->a_len  - 1]) || pass->a[pass->a_len - 1] < pass->a[0])
			{
				if (pass->b_len > 0 && pass->b[0] > pass->a[pass->a_len - 1] && pass->b[0] < pass->a[0])
				{
					ft_next_up(pass);
					ft_pa(pass);
					ft_printf("pa\n");
				}
				if (pass->b_len > 1 && pass->b[0] < pass->b[pass->b_len - 1])
				{
					ft_rrr(pass);
					ft_printf("rrr\n");
				}
				else
				{
					ft_rra(pass);
					ft_printf("rra\n");
				}
				if (pass->a[0] > pass->a[1])
					break ;
			}
		}
		if ((pass->a[0] > pass->a[pass->a_len - 1]) && ((pass->b_len > 0 && pass->b[0] > pass->a[0]) || pass->b_len == 0))	
		{
			while ((pass->a[0] > pass->a[pass->a_len - 1]))// && ((pass->b_len > 0 && pass->b[0] > pass->a[0]) || pass->b_len == 0))
			{
				if (pass->a[1] > pass->a[pass->a_len - 1] && pass->a[1] < pass->a[0] && pass->a_len > 3)
				{
					if (pass->b_len > 1 && pass->b[0] < pass->b[1])
					{
						ft_ss(pass);
						ft_printf("ss\n");
					}
					else
					{
						ft_sa(pass);
						ft_printf("sa\n");
					}
				}
				if (pass->b_len > 1 && pass->b[0] < pass->b[pass->b_len - 1])
				{
					ft_rr(pass);
					ft_printf("rr\n");
				}
				else
				{
					ft_ra(pass);
					ft_printf("ra\n");
				}
			}
		}
		else
		{
			while (pass->a[pass->a_len - 1] < pass->a[0] || (pass->a[pass->a_len - 1] > pass->a[0] && pass->a[1] > pass->a[pass->a_len  - 1]))
			{
				if (pass->b_len > 0 && pass->b[0] > pass->a[pass->a_len - 1] && pass->b[0] < pass->a[0])
				{
					ft_next_up(pass);
					ft_pa(pass);
					ft_printf("pa\n");
				}
				if (pass->b_len > 1 && pass->b[0] < pass->b[pass->b_len - 1])
				{
					ft_rrr(pass);
					ft_printf("rrr\n");
				}
				else if ((pass->b_len > 0 && pass->b[0] > pass->a[0]) || (pass->b_len == 0 || (pass->b_len > 0 && pass->b[0] < pass->a[0])))
				{
					ft_rra(pass);
					ft_printf("rra\n");
				}
				if (pass->a[0] > pass->a[1])
					break ;
			}
		}
		//while (ft_order(pass, 1, pass->a_len) == -1  && pass->a[0] < pass->a[1])//&& pass->a[0] < pass->a[pass->a_len - 1] && pass->a[0] < pass->a[1])
		//{
		//	if (pass->b_len > 2)
		//		ft_next_up_b(pass);
		//	ft_pb(pass);
		//	ft_printf("pb\n");
		//}
	}*/
	/*while (pass->b_len > 0)
		ft_next_up(pass);
	ft_iniit(pass);
	while (pass->a[0] != pass->min)
	{
		if (pass->min_pos < pass->a_len / 2)
			ft_ra(pass, 1);
		else
			ft_rra(pass, 1);
	}*/
	ft_push_a(pass);
	return (0);

}
