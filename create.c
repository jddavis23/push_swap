/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 13:06:22 by jdavis            #+#    #+#             */
/*   Updated: 2022/06/29 11:32:31 by jdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_assign(t_info *pass, int count)
{
	pass->a = NULL;
	pass->b = NULL;
	pass->lis_arr = NULL;
	pass->sequence = NULL;
	pass->a = (int *) malloc(count * sizeof(int *));
	pass->b = (int *) malloc(count * sizeof(int *));
	pass->lis_arr = (int *) malloc(count * sizeof(int));
}

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
	/*pass->a = NULL;
	pass->b = NULL;
	pass->lis_arr = NULL;
	pass->sequence = NULL;
	pass->a = (int *) malloc(count * sizeof(int *));
	pass->b = (int *) malloc(count * sizeof(int *));
	pass->lis_arr = (int *) malloc(count * sizeof(int));*/
	ft_assign(pass, count);
	if (!pass->a || !pass->b || !pass->lis_arr)
	{
		ft_error(pass);
		return (NULL);
	}
	pass->a_len = 0;
	pass->b_len = 0;
	pass->total = count;
	if (ft_collect(pass, str, total) == -1)
		return (NULL);
	return (pass);
}
