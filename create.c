/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 13:06:22 by jdavis            #+#    #+#             */
/*   Updated: 2022/05/16 15:20:01 by jdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_info	*ft_create(t_info *pass, int total, char *str[])
{
	int	count;
	int	i;

	count = 0;
	i = 1;
	if (total == 1 && str)
		return (NULL);
	pass = (t_info *) malloc(sizeof(t_info));
	if (!pass)
		return (NULL);
	while (i < total)
		count += ft_numb_count(str[i++]);
	pass->a = (int *) malloc(count * sizeof(int *));
	pass->b = (int *) malloc(count * sizeof(int *));
	if (!pass->a || !pass->b)
	{
		//free whichever
		//return
	}
	pass->a_len = 0;
	pass->b_len = 0;
	pass->total = count;
	return (pass);
}

