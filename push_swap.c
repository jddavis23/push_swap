/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 11:44:30 by jdavis            #+#    #+#             */
/*   Updated: 2022/06/14 13:26:36 by jdavis           ###   ########.fr       */
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
int	ft_moves(t_info *pass, int hold, int choice, int *ptr)
{
	int	i;

	i = 0;
	if (pass->a[0] < hold)
	{
		while (i < pass->a_len)
		{
			if (pass->a[i] > hold || ((hold < pass->min || hold > pass->max) && pass->a[i] == pass->min))
			{
				hold = pass->a[i];
				break;
			}
			++i;
		}
	}
	else if ((pass->a[0] > hold && pass->a[pass->a_len - 1] < hold) || (pass->a[0] == pass->min && (hold < pass->min || hold > pass->max)))
	{
		hold = pass->a[i];
	}
	else if (pass->a[0] > hold)
	{
		//ft_printf("a[0] %i  a[last] %i  b[0] %i\n", pass->a[0], pass->a[pass->a_len - 1], pass->b[0]);
		while (pass->a[i] > hold)
		{
			//ft_printf("a[i] %i   i %i   b[0] %i\n", pass->a[i], i, pass->b[0]);
			if ((hold < pass->min || hold > pass->max) && pass->a[i] == pass->min)
				break;
			++i;
		}
		while (i < pass->a_len)
		{
			if (pass->a[i] > hold || ((hold < pass->min || hold > pass->max) && pass->a[i] == pass->min) )
			{
				hold = pass->a[i];
				break;
			}
			++i;
		}
	}
	if (choice == 1)
		return (i);
	else
	{
		*ptr = hold;
		return (i);
	}
}

int	ft_find_it(t_info *pass)
{
	int	i;
	int	ret;

	i = 0;
	ret = 0;
	while (i < pass->b_len - 1)
	{
		if (pass->b[i] <= pass->mid)
			ret = 2;
		if (pass->b[i] <= pass->mid && pass->b[i] >= pass->quad)
			return (1);
		++i;
	}
	return (ret);
}

int	ft_close_mid(t_info *pass)
{
	int	i;
	int	ret;

	i = 0;
	ret = pass->b[0];
	while (pass->b[i] <= pass->quad)
	{
		if (pass->b[i] > ret)
			ret = pass->b[i];
		++i;
	}
	return (ret);
}

void	ft_next_up(t_info *pass)
{
	int	i;
	int	hold;
	int	j = 0;
	/*int k;
	int	j;
	int l;

	j = 0;
	i = 0;
	k = 0;
	l = 0;
	ft_iniit(pass);
	while (i <= pass->a_len / 2 && j <= pass->b_len / 2)// && (i < 10 || j < 10))
	{
		//ft_printf("i %i   j %i\n", i, j);
		if (pass->a[i] > pass->b[j])
			break;
		if (i < pass->a_len)
			++i;
		if (j < pass->b_len)
			++j;
	}
	while (pass->a[0] < hold && pass->b[0] != hold)
	{
		ft_rr(pass);
		ft_printf("rr\n");
	}
	while (pass->b[0] != hold)
	{
		ft_rb(pass);
		ft_printf("rb\n");
	//exit (0);
	}*/
	ft_iniit(pass); //look at calculating which is shorter (before or after median) and choose first 
	i = 0;
	while (pass->b_len > 1 && ft_find_it(pass) != 0) //looking for formular to find either mid or next closest 
	{
		j = 0;
		//ft_printf("HERE\n");
		while (pass->b[1] <= pass->mid)
		{
			++j;
			if (ft_find_it(pass) == 1)
			{
				if (pass->b[0] <= pass->mid && pass->b[0] >= pass->quad)
			   		break;
				//if (j  > 10)
				//	exit (0);
			}
			else if (ft_find_it(pass) != 1)
			{
				ft_printf("mid %i   quad %i  b[0] %i  len %i ret %i\n", pass->mid, pass->quad, pass->b[0], pass->b_len, ft_close_mid(pass));
				if (pass->b[0] == ft_close_mid(pass))
					break;
			}
			ft_rb(pass);
			ft_printf("rb\n");
			if (j  > 50)
				exit (0);
		}
		while (pass->b[pass->b_len - 1] <= pass->mid)
		{
		//	ft_printf("CLIFF\n");
			if (ft_find_it(pass) == 1)
			{
				if (pass->b[0] <= pass->mid && pass->b[0] >= pass->quad)
			   		break;
			}
			else if (ft_find_it(pass) != 1)
			{
				if (pass->b[0] == ft_close_mid(pass))
					break;
			}
			ft_rrb(pass);
			ft_printf("rrb\n");
		}
		if (ft_find_it(pass) == 1)
		{
			if (pass->b[0] <= pass->mid && pass->b[0] >= pass->quad)
				break;
		}
		else if (!ft_find_it(pass))
		{
			if (pass->b[0] == ft_close_mid(pass))
				break;
		}
	}
	hold = pass->b[0];
	if (pass->a[0] < hold)
	{
		while (i < pass->a_len)
		{
			if (pass->a[i] > hold || ((hold < pass->min || hold > pass->max) && pass->a[i] == pass->min))
			{
				hold = pass->a[i];
				break;
			}
			++i;
		}
	}
	else if ((pass->a[0] > hold && pass->a[pass->a_len - 1] < hold) || (pass->a[0] == pass->min && (hold < pass->min || hold > pass->max)))
	{
		hold = pass->a[i];
	}
	else if (pass->a[0] > hold)
	{
		while (pass->a[i] > hold)
		{
			if ((hold < pass->min || hold > pass->max) && pass->a[i] == pass->min)
			{
			//	hold = pass->a[i];
				break;
			}
			++i;
		}
		while (i < pass->a_len)
		{
			if (pass->a[i] > hold || ((hold < pass->min || hold > pass->max) && pass->a[i] == pass->min) )
			{
				hold = pass->a[i];
				break;
			}
			++i;
		}
	}
	if (i < pass->a_len / 2)
	{
		while (pass->a[0] != hold)
		{
				ft_ra(pass);
				ft_printf("ra\n");
		}
	}
	else
	{
		while (pass->a[0] != hold)
		{
				ft_rra(pass);
				ft_printf("rra\n");
		}
	}

	/*while (pass->a[0] < hold)
	{
		//ft_printf("2\n");
			//ft_printf("a[0] %i   b[0] %i  hold %i\n", pass->a[0], pass->b[0], hold);
		if ((hold > pass->max && pass->a[0] == pass->min) || (hold < pass->min && pass->a[0] == pass->min))
			break;
		ft_ra(pass);
		ft_printf("ra\n");
	}
	while (pass->a[pass->a_len - 1] > hold)
	{
		//ft_printf("3\n");
		//	ft_printf("a[0] %i   b[0] %i  hold %i\n", pass->a[0], pass->b[0], hold);
		if ((hold > pass->max && pass->a[0] == pass->min) || (hold < pass->min && pass->a[0] == pass->min))
			break;
		ft_rra(pass);
		ft_printf("rra\n");
	}*/
	ft_pa(pass);
	ft_printf("pa\n");
}





void ft_next_up_b(t_info *pass)  //optimise this function to place piece efficiently
{
	ft_pb(pass);
	ft_printf("pb\n");
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
		if (arr[i] <= arr[i - 1])
			return (-1);
		++i;
	}
	return (1);
}


void	ft_build_lis(t_info *pass, int complete, int i)
{
	int flag = 0;

	while (complete < pass->lis)
	{
		while (i <= pass->lis_pos && (ft_all_order(pass->sequence, pass->lis) != 1 ||  pass->sequence[pass->lis - 1] != pass->a[pass->lis_pos]))
		{
			if (pass->lis_arr[i] == complete + 1)
			{
				pass->sequence[complete] = pass->a[i];
				flag = 1;
			}
			if (flag && ft_all_order(pass->sequence, complete + 1) == 1 && complete == pass->lis - 1 && pass->sequence[complete] == pass->a[pass->lis_pos])
			{
				/*int j = 0;
				while (j < pass->lis)
					ft_printf("%i  ", pass->sequence[j++]);
				ft_printf("END\n");*/
				break ;
			}
			else if (flag && ft_all_order(pass->sequence, complete + 1) == 1)
			{
				ft_build_lis(pass, complete + 1, i + 1);
			}
			flag = 0;
			++i;
		}
		return;
	}
}

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
	pass->mid = pass->b[pass->a_len / 2];
	pass->quad = pass->b[pass->a_len / 4];
}

int	main(int argc, char *argv[])
{
	t_info *pass;
	int j = 0;
	//int mid;

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
	//ft_printf("mid %i\n", mid);
	while (j < pass->lis)
		pass->sequence[j++] = pass->min - 1;
	if (!pass->sequence)
	{
		//delete and return
		return (0);
	}
	ft_build_lis(pass, 0, 0);
	/*j = 0;
	while (j < pass->lis)
		ft_printf("%i  lis_pos %i    value in sequence %i\n", pass->sequence[j++], pass->lis_pos, pass->a[pass->lis_pos]);
	j = 0;
	while (j < pass->a_len)
	{
		ft_printf("%i   %i\n", pass->a[j], pass->lis_arr[j]);
		++j;
	}
	//exit (0);*/
	j = 0;
	//mid = ft_median(pass);
	if (ft_all_order(pass->a, pass->a_len) == -1)// && pass->a_len > 4)
	{
		while (ft_all_order(pass->a, pass->a_len) == -1)// && pass->a_len > 4)
		{
				//ft_printf("a0 = %i   seq j = %i %i\n", pass->a[0], pass->sequence[j], j);
			while (j < pass->lis && pass->a[0] == pass->sequence[j])
			{
				if (pass->b_len > 1 && pass->b[0] > pass->mid)
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
			ft_next_up_b(pass);
			if (pass->b_len > 1 && pass->b[0] > pass->mid)
			{
				ft_rb(pass);
				ft_printf("rb\n");
			} //look at possibly swapping last element if it fits between lis 1 and 2
			/*if (j - 1 > 0 && pass->a[0] < pass->sequence[j - 1] && pass->a[0] > pass->sequence[j] && ft_all_order(pass->a, pass->a_len) == -1)
			{
				ft_sb(pass);
				ft_printf("sb\n");
			}*/
		}
	}
	//exit (0);
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
	{
		ft_next_up(pass);
		//ft_printf("a_len %i   b_len %i\n", pass->a_len, pass->b_len);
	}
	ft_iniit(pass);
	while (pass->a[0] != pass->min)
	{
		if (pass->min_pos < pass->a_len / 2)
		{
			ft_ra(pass);
			ft_printf("ra\n");
		}
		else
		{
			ft_rra(pass);
			ft_printf("rra\n");
		}
	}
	return (0);

}
