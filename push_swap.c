/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 11:44:30 by jdavis            #+#    #+#             */
/*   Updated: 2022/05/24 18:41:45 by jdavis           ###   ########.fr       */
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

/*void	ft_iniit(t_info *pass)
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
}*/

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
	while (i < pass->a_len)
	{
		if (pass->a[i] > pass->b[0])
			break ;
		++i;
	}
	if (i == pass->a_len)
		--i;
	if (i <= pass->a_len / 2 && (i != 1 || (ft_b_order(pass, 3) == 0 && pass->b_len > 3)))
	{
		//ft_printf("here\n");
		while (i > 0)
		{
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
			--i;
		}
	}
	else if (i > pass->a_len / 2)
	{
		hold = pass->a[i];
		while (pass->a[0] != hold)
		{
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
		}
	}
}

void ft_next_up_b(t_info *pass)
{
	 int	i;
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
		 {
			 if (pass->a_len > 1 && pass->a[0] > pass->a[pass->a_len - 1])
			 {
				 ft_rr(pass);
				 ft_printf("rr\n");
			 }
			 else
			 {
				 ft_rb(pass);
				 ft_printf("rb\n");
			 }
			 --i;
		 }
	 }
	 else if (i > pass->b_len / 2) 
	 {
		hold = pass->b[i];
		while (pass->b[0] != hold)
		{
			if (pass->a_len > 1 && pass->a[0] > pass->a[pass->a_len - 1])
			{
				ft_rrr(pass);
				ft_printf("rrr\n");
			}
			else
			{
				ft_rrb(pass);
				ft_printf("rrb\n");
			}
		}
	 }
}


int	main(int argc, char *argv[])
{
	t_info *pass;

	pass = NULL;
	pass = ft_create(pass, argc, argv);
	if (!pass)
		return (-1);
	if (ft_collect(pass, argv, argc) == -1)
		return (-1);
	if (ft_dup(pass) == -1)
		return (ft_error(pass));
	while (ft_solved(pass) == -1)
	{
		while (((pass->b[0] > pass->a[pass->a_len - 1] && pass->b[0] < pass->a[0]) ||ft_order(pass, 1, pass->a_len) == 0) && pass->b_len > 0)
		{
			ft_next_up(pass);
			ft_pa(pass);
			ft_printf("pa\n");
		}
		/*while (pass->a[0] > pass->a[1]  && pass->a[0] < pass->a[pass->a_len - 1]) //find away of getting the longest ascending sequence to the top
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
		}*/
		if ((pass->a[pass->a_len - 1] < pass->a[0] || pass->a[pass->a_len - 1] < pass->a[0]) && (pass->a[pass->a_len - 1] > pass->a[0] && pass->a[1] > pass->a[pass->a_len  - 1]))
		{
			while (pass->a[pass->a_len - 1] < pass->a[0] || (pass->a[pass->a_len - 1] > pass->a[0] && pass->a[1] > pass->a[pass->a_len  - 1]))
			{
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
		else if (pass->a[pass->a_len - 1] < pass->a[0])
		{
			while (pass->a[pass->a_len - 1] < pass->a[0])
			{
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
		while (pass->a[0] > pass->a[1]  && pass->a[0] < pass->a[pass->a_len - 1]) //find away of getting the longest ascending sequence to the top
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
		if (ft_order(pass, 1, pass->a_len) == -1)//&& pass->a[0] < pass->a[pass->a_len - 1] && pass->a[0] < pass->a[1])
		{
			if (pass->b_len > 2)
					ft_next_up_b(pass);
			ft_pb(pass);
			ft_printf("pb\n");
		}
		/*if (ft_b_order(pass, pass->b_len) == 0 || pass->b_len < 1)
		{
			int p = 0;
			ft_printf("\nchecking\n");
			while (p < pass->b_len)
				ft_printf("%i  b_len = %i\n", pass->b[p++], pass->b_len);
			//exit (1);
		}*/
		//if (pass->b_len > 20)
		//	exit (1);
	}
	/*ft_printf("\nchecking\n");
	while (p < pass->a_len)
	{
		ft_printf("%i  a_len = %i\n", pass->a[p++], pass->a_len);
	}*/
	return (0);

}
