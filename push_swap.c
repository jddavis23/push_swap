/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 11:44:30 by jdavis            #+#    #+#             */
/*   Updated: 2022/06/07 17:03:08 by jdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_order(t_info *pass, int i, int len)
{
	int	solved;

	solved = 0;
	while (i < len)
	{
		if (pass->a[i] < pass->a[i - 1])
			solved = -1;
		if (pass->a[i] < pass->min)
		{
			pass->min = pass->a[i];
			pass->min_pos = i;
		}
		++i;
	}
	return (solved);
}

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

int	ft_b_order(t_info *pass, int len)
{
	int	i;

	i = 1;
	while (i < len)
	{
		if (pass->b[i] > pass->b[i - 1])
			return (-1);
		++i;
	}
	return (0);
}

void	ft_next_up(t_info *pass)
{
	int	i;
	int	hold;

	i = 0;
	ft_iniit(pass);
	if (pass->b[0] < pass->min)
	{
		if (pass->min_pos <= pass->a_len / 2)// && (i != 1 || (ft_b_order(pass, 3) == 0 && pass->b_len > 3)))
		{
			//ft_printf("here\n");
			while (pass->a[0]  != pass->min)
			{
				if (pass->b_len > 1 && pass->b[0] < pass->b[pass->b_len - 1] && pass->b[1] < pass->min)
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
		else if (pass->min_pos > pass->a_len / 2)
		{
			while (pass->a[0] != pass->min)
			{
				if (pass->b_len > 1 && pass->b[0] < pass->b[pass->b_len - 1] && pass->b[pass->b_len - 1] < pass->min)
				{
					ft_rrr(pass);
					ft_printf("rrr\n");
				}
				else
				{
					ft_rra(pass);
					ft_printf("rra\n");
				}
			}
		}
			//ft_printf("b[0] %i  ***   a[0] %i     a[last] %i     min %i\n", pass->b[0], pass->a[0], pass->a[pass->a_len - 1], pass->min);
		return;
	}
	else if (pass->b[0] > pass->max)
	{
		if (pass->max_pos <= pass->a_len / 2)// && (i != 1 || (ft_b_order(pass, 3) == 0 && pass->b_len > 3)))
		{
			//ft_printf("here\n");
			while (pass->a[0]  != pass->min)
			{
				if (pass->b_len > 1 && pass->b[0] < pass->b[pass->b_len - 1] && pass->b[1] > pass->max)
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
		else if (pass->max_pos > pass->a_len / 2)
		{
			while (pass->a[0] != pass->min)
			{
				if (pass->b_len > 1 && pass->b[0] < pass->b[pass->b_len - 1] && pass->b[pass->b_len - 1] > pass->max)
				{
					ft_rrr(pass);
					ft_printf("rrr\n");
				}
				else
				{
					ft_rra(pass);
					ft_printf("rra\n");
				}
			}
		}
		//ft_printf("b[0] %i   +++  a[0] %i     a[last] %i\n", pass->b[0], pass->a[0], pass->a[pass->a_len - 1]);
		return;
	}
	while (i < pass->a_len)
	{
		if ((pass->b[0] > pass->a[i - 1] && pass->b[0] < pass->a[i] & i - 1 > 0) ||  (pass->b[0] < pass->a[0] && pass->b[0] && pass->b[0] > pass->a[pass->a_len - 1]))
		//if (pass->a[i] > pass->b[0] && pass->b[0] > pass->a[pass->a_len - 1])
			break ;
		++i;
	}
	//ft_printf("i   %i\n", i);
	if (i == pass->a_len)
		--i;
	if (pass->b[0] > pass->min && pass->b[0] < pass->max)
	{
		if (i <= pass->a_len / 2)// && (i != 1 || (ft_b_order(pass, 3) == 0 && pass->b_len > 3)))
		{
			while (i > 0)//pass->b[0] > pass->a[0])
			{
				if (pass->b_len > 1 && pass->b[0] < pass->b[pass->b_len - 1] && pass->b[1] < pass->a[i] && pass->b[1] > pass->a[i - 1] && i - 1 > 0)	
				{
					ft_rr(pass);
					ft_printf("rr\n");
				}
				else
				{
					ft_ra(pass);
					ft_printf("ra\n");
				}
				--i;
			}
		//	ft_printf("b[0] %i     a[0] %i     a[last] %i\n", pass->b[0], pass->a[0], pass->a[pass->a_len - 1]);
		}
		else if (i > pass->a_len / 2)
		{
			hold = pass->a[i];
			ft_iniit(pass);
			while (i < pass->a_len)// && (pass->a[pass->a_len - 1] < pass->b[0] || pass->b[0] > pass->max))//pass->a[0]  != hold)//pass->b[0] < pass->a[pass->a_len - 1])
			{
				if (pass->b_len > 1 && pass->b[0] < pass->b[pass->b_len - 1] && pass->b[pass->b_len - 1] < hold)
				{
					ft_rrr(pass);
					ft_printf("rrr\n");
				}
				else
				{
					ft_rra(pass);
					ft_printf("rra\n");
				}
				++i;
			}
		//	ft_printf("b[0] %i  --   a[0] %i\n", pass->b[0], pass->a[0]);
		}
	}
}

void ft_next_up_b(t_info *pass)  //optimise this function to place piece efficiently
{
	//if (pass->b == 0)
	//
	//if (pass->b == 1)
	//
	//if (pass->b == 2)
	//
	//if (pass->b == 3)
	//
	//if (pass->b > 3)
	int	i;

	i = 0;
	while (i < pass->b_len)
	{
		if (pass->b[i] < pass->a[0])
			break;
		++i;
	}
	if (pass->b_len == 0)
	{
		ft_pb(pass);
		ft_printf("pb\n");
	}
	else if (pass->b_len == 1)
	{
		ft_pb(pass);
		ft_printf("pb\n");
		if (pass->b[0] < pass->b[1])
		{
			ft_sb(pass);
			ft_printf("sb\n");
		}
	}
	else if (pass->b_len == 2)
	{
		ft_pb(pass);
		ft_printf("pb\n");
		if (i == 1)
		{
			ft_sb(pass);
			ft_printf("sb\n");
		}
		else if (i > 1)
		{
			ft_rb(pass);
			ft_printf("rb\n");
		}
	}
	else if (pass->b_len > 2)
	{
		if (pass->a[0] < pass->b[pass->b_len - 1])
		{
			ft_pb(pass);
			ft_printf("pb\n");
			ft_rb(pass);
			ft_printf("rb\n");
		}
		else if (pass->a[0] < pass->b[0])
		{
			ft_rb(pass);
			ft_printf("rb\n");
			ft_pb(pass);
			ft_printf("pb\n");
			if (pass->b[0] < pass->b[1])
			{
				ft_sb(pass);
				ft_printf("sb\n");
			}
		}
		else if (pass->a[0] > pass->b[0])
		{
			ft_pb(pass);
			ft_printf("pb\n");
		}
	}
}
			
	 /*int	i;
	 int	hold;

	 i = 0;
	 while (i < pass->b_len)
	 {
		 if (pass->b[i] < pass->a[0])
			 break ;
		 ++i;
	 }
	 if (i == pass->b_len)
	 	--i;
	 if ( i <= pass->b_len / 2 && (i != 1 || (ft_order(pass, 1, 3) == 0 && pass->a_len > 3)))
	 {
		 while (i > 0)
		 {*/
			 /*if (pass->a_len > 1 && pass->a[0] > pass->a[pass->a_len - 1])
			 {
				 ft_rr(pass);
				 ft_printf("rr\n");
			 }
			 else
			 {*/
		/*		 ft_rb(pass);
				 ft_printf("rb\n");
			 //}
			 --i;
		 }
	 }
	 else if (i > pass->b_len / 2) 
	 {
		hold = pass->b[i];
		while (pass->b[0] != hold)
		{*/
			/*if (pass->a_len > 1 && pass->a[0] > pass->a[pass->a_len - 1])
			{
				ft_rrr(pass);
				ft_printf("rrr\n");
			}
			else
			{*/
/*				ft_rrb(pass);
				ft_printf("rrb\n");
			//}
		}
	 }
}*/

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
				pass->lis_arr[i] = ft_max_of(pass->lis_arr[i], pass->lis_arr[j] + 1); //error is here
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
		if (arr[i] < arr[i - 1])
			return (-1);
		++i;
	}
	return (1);
}


void	ft_build_lis(t_info *pass, int complete, int i)
{
	int flag = 0;
	//int j = 0;

	while (complete < pass->lis)
	{
		while (i <= pass->lis_pos && ft_all_order(pass->sequence, pass->lis) != 1)// && pass->sequence[pass->lis - 1] != pass->a[pass->lis_pos])
		{
			if (pass->lis_arr[i] == complete + 1)
			{
				pass->sequence[complete] = pass->a[i];
				flag = 1;
			}
			if (flag && ft_all_order(pass->sequence, complete + 1) == 1 && complete == pass->lis - 1 && pass->sequence[complete] == pass->a[pass->lis_pos])
			{
				/*while (j < pass->lis)
					ft_printf("%i  ", pass->sequence[j++]);
				ft_printf("END\n");*/
				break ;
			}
			else if (flag && ft_all_order(pass->sequence, complete + 1) == 1)
			{
				ft_build_lis(pass, complete + 1, i + 1);
			}
			//else if (flag && ft_all_order(pass->sequence, complete + 1) == -1)
			//	return;
			flag = 0;
			++i;
		}
		return;
	}
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
	pass->sequence = (int *)malloc(pass->lis * sizeof(int));
	if (!pass->sequence)
	{
		//delete and return
		return (0);
	}
	ft_build_lis(pass, 0, 0);
	/*while (j < pass->lis)
		ft_printf("%i  lis_pos %i    value in sequence %i\n", pass->sequence[j++], pass->lis_pos, pass->a[pass->lis_pos]);
	while (j < pass->a_len)
	{
		ft_printf("%i   %i\n", pass->a[j], pass->lis_arr[j]);
		++j;
	}
	exit (0);*/
	j = 0;
	if (ft_all_order(pass->a, pass->a_len) == -1 && pass->a_len > 4)
	{
		while (ft_all_order(pass->a, pass->a_len) == -1 && pass->a_len > 4)
		{
			while (j < pass->lis && pass->a[0] == pass->sequence[j])
			{
				//ft_printf("a0 = %i   seq j = %i %i\n", pass->a[0], pass->sequence[j], j);
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
				++j;
			}
			if (j - 1 > 0 && pass->a[0] < pass->sequence[j] && pass->a[0] > pass->sequence[j - 1])
			{
				ft_sa(pass);
				ft_printf("sa\n");
			}
			ft_next_up_b(pass);
			if (j - 1 > 0 && pass->a[0] < pass->sequence[j - 1] && pass->a[0] > pass->sequence[j] && ft_all_order(pass->a, pass->a_len) == -1)
			{
				ft_ra(pass);
				ft_printf("ra\n");
			}
		}
	}
	//exit (0);
	while (ft_all_order(pass->a, pass->a_len) == -1)
	{

		while (pass->a[0] > pass->a[1]  && pass->a[0] < pass->a[pass->a_len - 1]) //find away of getting the longest ascending sequence to the top
		{
			//ft_printf("2\n");
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
	}
	while (pass->b_len > 0)
	{
		ft_next_up(pass);
		ft_pa(pass);
		ft_printf("pa\n");
	}
	return (0);

}
