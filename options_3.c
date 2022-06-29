/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 12:14:17 by jdavis            #+#    #+#             */
/*   Updated: 2022/06/29 12:23:01 by jdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*ft_rotate_up(int *arr, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		arr[i] = arr[i + 1];
		++i;
	}
	return (arr);
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
