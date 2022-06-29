/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 12:55:00 by jdavis            #+#    #+#             */
/*   Updated: 2022/06/29 11:57:49 by jdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*ft_rotate_up(int *arr, int len)
{
	int i;

	i = 0;
	while (i < len)
	{
		arr[i] = arr[i + 1];
		++i;
	}
	return (arr);
}

int	*ft_rotate_down(int *arr, int len)
{
	while (len > 0)
	{
		arr[len] = arr[len - 1];
		--len;
	}
	return (arr);
}

void	ft_pa(t_info *pass, int choice)
{
	if (pass->b_len > 0)
	{
		--pass->b_len;
		++pass->a_len;
		pass->a =ft_rotate_down(pass->a, pass->a_len);
		pass->a[0] = pass->b[0];
		pass->b = ft_rotate_up(pass->b, pass->b_len);
	}
	if (choice)
		ft_printf("pa\n");
}

void	ft_pb(t_info *pass, int choice)
{
	if (pass->a_len > 0)
	{
		--pass->a_len;
		++pass->b_len;
		pass->b = ft_rotate_down(pass->b, pass->b_len);
		pass->b[0] = pass->a[0];
		pass->a = ft_rotate_up(pass->a, pass->a_len);
	}
	if (choice)
		ft_printf("pb\n");
}

void	ft_ra(t_info *pass, int choice)
{
	int	temp;

	temp = pass->a[0];
	pass->a = ft_rotate_up(pass->a, pass->a_len);
	pass->a[pass->a_len - 1] = temp;
	if (choice)
		ft_printf("ra\n");
}

void	ft_rb(t_info *pass, int choice)
{
	int	temp;

	temp = pass->b[0];
	pass->b = ft_rotate_up(pass->b, pass->b_len);
	pass->b[pass->b_len - 1] = temp;
	if (choice)
		ft_printf("rb\n");
}

void	ft_rra(t_info *pass, int choice)
{
	int	temp;

	if(pass->a_len > 1)
	{
		temp = pass->a[pass->a_len - 1];
		pass->a = ft_rotate_down(pass->a, pass->a_len);
		pass->a[0] = temp;
	}
	if (choice)
		ft_printf("rra\n");
}

void	ft_rrb(t_info *pass, int choice)
{
	int	temp;

	if (pass->b_len > 1)
	{
		temp = pass->b[pass->b_len - 1];
		pass->b = ft_rotate_down(pass->b, pass->b_len);
		pass->b[0] = temp;
	}
	if (choice)
		ft_printf("rrb\n");
}
