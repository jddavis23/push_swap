/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 11:44:30 by jdavis            #+#    #+#             */
/*   Updated: 2022/06/17 16:50:21 by jdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_iniit(t_info *pass)
{
	int	i;

	i = 0;
	if (pass->b_len > 0)
	{
		pass->min_b_pos = 0;
		pass->min_b = pass->b[0];
	}
	else
		pass->min_b_pos = -1;
	while (i < pass->b_len)
	{
		if (pass->b[i] < pass->min_b)
		{
			pass->min_b = pass->b[i];
			pass->min_b_pos = i;
		}
		++i;
	}	
	i = 0;
	pass->min = pass->a[i];
	pass->max = pass->a[i];
	pass->max_pos = i;
	pass->min_pos = i;
	while (i < pass->a_len)
	{
		if (pass->a[i] < pass->min)
		{
			pass->min = pass->a[i];
			pass->min_pos = i;
		}
		if (pass->a[i] > pass->max)
		{
			pass->max = pass->a[i];
			pass->max_pos = i;
		}
		++i;
	}
}

int	ft_closer(t_info *pass, int min, int max)
{
	int i;
	int	j;

	i = 0;
	j = pass->b_len - 1;
	ft_iniit(pass);
	while (i < pass->b_len - 1)
	{
		if (pass->b[i] >= min && pass->b[i] <= max)
			break;
		++i;
	}
	while (j > 0)
	{
		if (pass->b[j] >= min && pass->b[j] <= max)
			break;
		--j;
	}
	if (pass->b[i] < min || pass->b[i] > max)
	   i = -1;
	if (pass->b[j] < min || pass->b[j] > max)
	   j = -1;
	if (j == -1 && i != -1)
	{
		pass->rev = 1;
		pass->b_hold = pass->b[i];
		return (1);
	}
	else if (i == -1 && j != -1)
	{
		pass->rev = 2;
		pass->b_hold = pass->b[i];
		return (1);
	}
	else if (i == -1 && j == -1)
		return (-1);
	if (pass->b_len - j < i)
	{
		pass->rev = 2;
		pass->b_hold = pass->b[j];
		return (1);
	}
	else
	{
		pass->rev = 1;
		pass->b_hold = pass->b[i];
		return (1);
	}
}

void	ft_shift(t_info *pass, int i)
{
	if (pass->rev == 1)
	{
		if (i < pass->a_len / 2)
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
	{
		if (i >= pass->a_len / 2)
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
}

void	ft_next_up(t_info *pass)
{
	int			i;
	static int	up = 1;

	if (ft_closer(pass, pass->zero_et, pass->zero_et + (int)((pass->range / 10.0) * up)) == -1)
		++up;
	if (ft_closer(pass, pass->zero_et, pass->zero_et + (int)((pass->range / 10.0) * up)) == 1)
	{
		i = ft_moves(pass);
		ft_shift(pass, i);
	}
	ft_pa(pass, 1);
}

int	ft_max_of(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

void	ft_lis(t_info *pass)
{
	int	i;
	int	j;

	i = 0;
	pass->lis_arr = (int *) malloc(pass->a_len * sizeof(int));
	if (!pass->lis_arr)
	{
		//printf error message
		return;
	}
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
		while (i <= pass->lis_pos && !stop &&  (ft_all_order(pass->sequence, pass->lis) != 1 ||  pass->sequence[pass->lis - 1] != pass->a[pass->lis_pos]))
		{
			if (pass->lis_arr[i] == complete + 1)
			{
				pass->sequence[complete] = pass->a[i];
				flag = 1;
			}
			if (flag && ft_all_order(pass->sequence, complete + 1) == 1 && complete == pass->lis - 1 && pass->sequence[complete] == pass->a[pass->lis_pos])
			{
				++stop;
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

void	ft_median(t_info *pass)
{
   	/*int i;
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
	pass->zero_et = pass->b[0];
	pass->one_et = pass->b[pass->a_len / 8];
	pass->two_et = pass->b[(pass->a_len / 8) * 2];
	pass->three_et = pass->b[(pass->a_len / 8) * 3];
	pass->mid = pass->b[pass->a_len / 2];
	pass->five_et = pass->b[(pass->a_len / 8) * 5];
	pass->six_et = pass->b[(pass->a_len / 8) * 6];
	pass->sev_et = pass->b[(pass->a_len / 8) * 7];
	pass->et_et = pass->b[pass->a_len - 1];
	pass->range = pass->b[pass->a_len - 1] - pass->b[0];*/
	pass->range = pass->max - pass->min;
	pass->mid = (int)((pass->range / 10.0) * 5);
}

int	main(int argc, char *argv[])
{
	t_info *pass;
	int j = 0;

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
	ft_median(pass);
	while (j < pass->lis)
		pass->sequence[j++] = pass->min - 1;
	if (!pass->sequence)
	{
		//delete and return
		return (0);
	}
	ft_build_lis(pass, 0, 0);
	j = 0;
	if (ft_all_order(pass->a, pass->a_len) == -1)// && pass->a_len > 4)
	{
		while (ft_all_order(pass->a, pass->a_len) == -1)// && pass->a_len > 4)
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
			{
				ft_rb(pass, 1);
			} //look at possibly swapping last element if it fits between lis 1 and 2
		}
	}
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
	return (0);

}
