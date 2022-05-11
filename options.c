/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 12:55:00 by jdavis            #+#    #+#             */
/*   Updated: 2022/05/11 16:31:17 by jdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(t_info *pass)
{
	int	temp;

	temp = pass->a[0];
	pass->a[0] = pass->a[1];
	pass->a[1]  = temp;
}

void	ft_sb(t_info *pass)
{
	int	temp;

	temp = pass->b[0];
	pass->b[0] = pass->b[1];
	pass->b[1]  = temp;
}
