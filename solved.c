/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solved.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 13:05:14 by jdavis            #+#    #+#             */
/*   Updated: 2022/05/16 13:13:20 by jdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_solved(t_info *pass)
{
	int	i;

	i = 0;
	if (pass->a_len == pass->total && pass->b_len == 0)
	{
		while (i < pass->total - 1 )
		{
			if (pass->a[i] >= pass->a[i + 1])
				return (-1);
			++i;
		}
	}
	return (0);
}
