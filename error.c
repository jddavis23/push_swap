/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 10:58:11 by jdavis            #+#    #+#             */
/*   Updated: 2022/06/29 11:24:27 by jdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_error(t_info *pass)
{
	int	i;

	i = 0;
	if (pass->a && pass->b)
		pass->total = 0;
	if (pass->a)
		free(pass->a);
	if (pass->b)
		free(pass->b);
	if (pass->lis_arr)
		free(pass->lis_arr);
	if (pass->sequence)
		free(pass->sequence);
	if (pass)
		free(pass);
	ft_putstr_fd("Error\n", 2);
	return (-1);
}
