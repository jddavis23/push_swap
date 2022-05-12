/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 12:55:00 by jdavis            #+#    #+#             */
/*   Updated: 2022/05/12 13:25:05 by jdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(t_info *pass)
{
	int	temp;

	if (pass->a_len > 1)
	{
		temp = (pass)->a[0];
		(pass)->a[0] = (pass)->a[1];
		(pass)->a[1]  = temp;
	}
}

void	ft_sb(t_info *pass)
{
	int	temp;

	if (pass->b_len > 1)
	{
		temp = pass->b[0];
		pass->b[0] = pass->b[1];
		pass->b[1]  = temp;
	}
}

void	ft_ss(t_info *pass)
{
	ft_sa(pass);
	ft_sb(pass);
}

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

void	ft_pa(t_info *pass)
{
	int	t_len;

	t_len = pass->a_len;
	if (pass->b_len > 0)
	{
		--pass->b_len;
		++pass->a_len;
		while (t_len > 0) //make own function
		{
			pass->a[t_len] = pass->a[t_len - 1];
			--t_len;
		}
		pass->a[0] = pass->b[0];
		pass->b = ft_rotate_up(pass->b, pass->b_len);
		ft_printf("alen = %i\n", pass->a_len);
		ft_printf("blen = %i\n", pass->b_len);
	}
}

void	ft_pb(t_info *pass)
{
	int	t_len;
	int	i;

	i = 0;
	t_len = pass->b_len;
	if (pass->a_len > 0)
	{
		--pass->a_len;
		++pass->b_len;
		while (t_len > 0)
		{
			pass->b[t_len] = pass->b[t_len - 1];
			--t_len;
		}
		pass->b[t_len] = pass->a[t_len];
		while (t_len < pass->a_len)
		{
			pass->a[t_len] = pass->a[t_len + 1];
			++t_len;
		}
		ft_printf("alen = %i\n", pass->a_len);
		ft_printf("blen = %i\n", pass->b_len);
	}
}

/*void	ft_ra(t_info *pass)
{
	int	temp;
	int	i;

	i = 0;
	temp = pass->a[i];

}*/
