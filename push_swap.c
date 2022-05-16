/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 11:44:30 by jdavis            #+#    #+#             */
/*   Updated: 2022/05/16 16:58:08 by jdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_order(t_info *pass)
{
	int	i;
	int	solved;

	solved = 0;
	i = 1;
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
	int		solved;
	int p = 0;

	pass = NULL;
	solved = -1;
	pass = ft_create(pass, argc, argv);
	if (!pass)
		return (-1);
	if (ft_collect(pass, argv, argc) == -1)
		return (-1);
	if (ft_dup(pass) == -1)
		return (ft_error(pass));
	//inside own while loop
	while (solved == -1)
	{
		i = 0;
		solved = 0;
		pass->min = pass->a[i++];
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
		if (solved == 0)
			break ;
		if ((pass->min_pos == 1 && pass->a[0] > pass->min) || pass->a[1] < pass->a[0])
		{
			ft_sa(pass);
			ft_printf("sa\n");
			if (pass->a[0] == pass->min)
				pass->min_pos = 0;
		}
		while ((pass->min_pos < (pass->a_len / 2)) && pass->a[0] != pass->min)
		{
			ft_printf("min   %i    half %i    a[0] = %i\n", pass->min_pos, pass->a_len / 2, pass->a[0]);
			pass->min_pos--;
			ft_ra(pass);
			ft_printf("ra\n");
		}
		while ((pass->min_pos >= (pass->a_len / 2)) && pass->a[0] != pass->min)
		{
			pass->min_pos++;
			ft_rra(pass);
			ft_printf("rra\n");
			if (pass->a[0] == pass->min)
				pass->min_pos = 0;
		}
		if (pass->min_pos == 0 && ft_order(pass) == -1 && pass->a[0] < pass->a[pass->a_len - 1])
		{
			ft_pb(pass);
			ft_printf("pb\n");
		}
	}
	if (ft_solved(pass) == -1)
	{
		while (pass->b_len > 0)
		{
			ft_pa(pass);
			ft_printf("pa\n");
		}
	}

	ft_printf("\nchecking\n");
	while (p < pass->a_len)
	{
		ft_printf("%i  a_len = %i\n", pass->a[p++], pass->a_len);
	}
	return (0);

}

