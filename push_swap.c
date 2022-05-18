/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 11:44:30 by jdavis            #+#    #+#             */
/*   Updated: 2022/05/18 14:14:35 by jdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_order(t_info *pass, int i)
{
	int	solved;

	solved = 0;
	while (i < pass->a_len)
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

int	main(int argc, char *argv[])
{
	t_info *pass;
	int		i;
	int p = 0;

	pass = NULL;
	pass = ft_create(pass, argc, argv);
	if (!pass)
		return (-1);
	if (ft_collect(pass, argv, argc) == -1)
		return (-1);
	if (ft_dup(pass) == -1)
		return (ft_error(pass));
	//inside own while loop
	while (ft_solved(pass) == -1)
	{
		if ((ft_order(pass, 1) == -1 && pass->a[0] < pass->a[1] && pass->a[0] != pass->max && pass->a[1] != pass->max) || (pass->a[0] == pass->max && ft_order(pass, 2) == -1))
		{
			ft_pb(pass);
			ft_printf("pb\n");
			return (0);
		}
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
		pass->min_pos = i++;
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
		//if (solved == 0)
		//	break ;
		if (((ft_order(pass, 2) == -1 && pass->a[1] < pass->a[0] && (pass->a[0] != pass->max || pass->a[1] == pass->min || pass->a[0] != pass->min || pass->a[1] == pass->max))))
		{
			if (pass->b[1] == pass->min_b && pass->b_len > 1)
			{
				ft_ss(pass);
				pass->min_b_pos = 0;
				ft_printf("ss\n");
			}
			else
			{
				ft_sa(pass);
				ft_printf("sa\n");
			}
			if (pass->a[0] == pass->min)
				pass->min_pos = 0;
			else if (pass->a[0] == pass->max)
				pass->max_pos = 0;
		}
		//ft_printf("relativ_max  = %i   max_pos = %i    relativ_min = %i   min_pos = %i\n", pass->a_len - pass->max_pos, pass->max_pos, pass->a_len - pass->min_pos, pass->min_pos);
		if (pass->min_pos <= (pass->a_len - pass->max_pos && pass->max_pos))
		{
			if (pass->min_pos <= (pass->a_len - pass->min_pos))
			{
				while (pass->min_pos > 0)
				{
					if (pass->min_b_pos <= pass->b_len / 2 && pass->min_b_pos != 0 && pass->b_len > 1) //look at adding comparison of even and odd totals for comparing pass->b_len / 2
					{
						pass->min_b_pos--;
						ft_rr(pass);
						ft_printf("rr\n");
					}
					else
					{
						ft_ra(pass);
						ft_printf("ra\n");
					}
					pass->min_pos--;
				}
			}
			else
			{
				while (pass->min_pos != 0)
				{
					if (pass->min_b_pos > pass->b_len / 2 && pass->min_b_pos != 0 && pass->b_len > 1)
					{
						pass->min_b_pos++;
						if (pass->min_b_pos == pass->b_len)
							pass->min_b_pos = 0;
						ft_rrr(pass);
						ft_printf("rrr\n");
					}
					else
					{
						ft_rra(pass);
						ft_printf("rra\n");
					}
					pass->min_pos++;
					if (pass->a[0] == pass->min)
						pass->min_pos = 0;
				}
			}
		}
		else if (pass->max_pos <= ((pass->a_len - pass->min_pos) && pass->min_pos) && pass->max_pos != 0)
		{
			if (pass->max_pos <= pass->a_len - pass->max_pos)
			{
				while (pass->max_pos > 0)
				{
					if (pass->min_b_pos <= pass->b_len / 2 && pass->min_b_pos != 0 && pass->b_len > 1)
					{
						pass->min_b_pos--;
						ft_rr(pass);
						ft_printf("rr\n");
					}
					else
					{
						ft_ra(pass);
						ft_printf("ra\n");
					}
					pass->max_pos--;
				}
			}
			else
			{
				while (pass->max_pos != 0)
				{
					if (pass->min_b_pos > pass->b_len / 2 && pass->min_b_pos != 0 && pass->b_len > 1)
					{
						pass->min_b_pos++;
						if (pass->b[0] == pass->min_b)
							pass->min_b_pos = 0;
						ft_rrr(pass);
						ft_printf("rrr\n");
					}
					else
					{
						ft_rra(pass);
						ft_printf("rra\n");
					}
					pass->max_pos++;
					if (pass->a[0] == pass->max)
						pass->max_pos = 0;
				}
			}
		}
		else if (pass->min_pos <= (pass->a_len - pass->min_pos))
		{
			//if (pass->min_pos == (pass->a_len - pass->max_pos))
			//{
				while (pass->min_pos > 0)
				{
					if (pass->min_b_pos <= pass->b_len / 2 && pass->min_b_pos != 0 && pass->b_len > 1)
					{
						pass->min_b_pos--;
						ft_rr(pass);
						ft_printf("rr\n");
					}
					else
					{
						ft_ra(pass);
						ft_printf("ra\n");
					}
					pass->min_pos--;
				}
			//}
		}
		else if (pass->max_pos <= (pass->a_len - pass->max_pos))
		{
			//if (pass->max_pos == (pass->a_len - pass->min_pos))
			//{
				while (pass->max_pos > 0)
				{
					if (pass->min_b_pos <= pass->b_len / 2 && pass->min_b_pos != 0 && pass->b_len > 1)
					{
						pass->min_b_pos--;
						ft_rr(pass);
						ft_printf("rr\n");
					}
					else
					{
						ft_ra(pass);
						ft_printf("ra\n");
					}
					pass->max_pos--;
				}
			//}
		}
		if (ft_order(pass, 1) == 0 && pass->b_len != 0)
		{
			ft_pa(pass);
			ft_printf("pa\n");
			if (pass->a[0] > pass->a[1] && pass->b_len > 0)
			{
				if (pass->b[1] == pass->min_b && pass->b_len > 1)
				{
					ft_rr(pass);
					ft_printf("rr\n");
					pass->min_b_pos = 0;
				}
				else
				{
					ft_ra(pass);
					ft_printf("ra\n");
				}
				pass->max_pos = pass->a_len - 1;
			}
		}
	}
	ft_printf("\nchecking\n");
	while (p < pass->a_len)
	{
		ft_printf("%i  a_len = %i\n", pass->a[p++], pass->a_len);
	}
	return (0);

}

