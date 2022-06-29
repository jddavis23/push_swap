/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 11:51:48 by jdavis            #+#    #+#             */
/*   Updated: 2022/06/29 11:56:15 by jdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

void	ft_sa(t_info *pass, int choice)
{
	int	temp;

	if (pass->a_len > 1)
	{
		temp = (pass)->a[0];
		(pass)->a[0] = (pass)->a[1];
		(pass)->a[1]  = temp;
	}
	if (choice)
		ft_printf("sa\n");
}

void	ft_sb(t_info *pass, int choice)
{
	int	temp;

	if (pass->b_len > 1)
	{
		temp = pass->b[0];
		pass->b[0] = pass->b[1];
		pass->b[1]  = temp;
	}
	if (choice)
		ft_printf("sb\n");
}

void	ft_ss(t_info *pass, int choice)
{
	ft_sa(pass, 0);
	ft_sb(pass, 0);
	if (choice)
		ft_printf("ss\n");
}

void	ft_rr(t_info *pass, int choice)
{
	ft_ra(pass, 0);
	ft_rb(pass, 0);
	if (choice)
		ft_printf("rr\n");
}

void	ft_rrr(t_info *pass, int choice)
{
	ft_rra(pass, 0);
	ft_rrb(pass, 0);
	if (choice)
		ft_printf("rrr\n");
}
