/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 10:58:11 by jdavis            #+#    #+#             */
/*   Updated: 2022/05/16 10:58:16 by jdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_error(t_info *pass)
{
	int	i;

	i = 0;
	if (pass->a && pass->b)
		pass->total = 0;
	/*while (i <= index)
	{
		if (a)
			free(a[i]);
		if (b)
			free(b[i++]);
	}
	free(a);
	free(b);
	a = NULL;
	b = NULL;
	USE ft_double_arrdel*/
	ft_printf("Error\n");
	return (-1);
}

