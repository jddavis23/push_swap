/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 10:28:54 by jdavis            #+#    #+#             */
/*   Updated: 2022/06/17 13:41:51 by jdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_compare(t_info *pass, char **line)
{
	if (ft_strcmp("sa", *line) == 0 && *line)
		ft_sa(pass, 0);
	if (ft_strcmp("sb", *line) == 0 && *line)
		ft_sb(pass, 0);
	if (ft_strcmp("pa", *line) == 0 && *line)
		ft_pa(pass, 0);
	if (ft_strcmp("pb", *line) == 0 && *line)
		ft_pb(pass, 0);
	if (ft_strcmp("ra", *line) == 0 && *line)
		ft_ra(pass, 0);
	if (ft_strcmp("rb", *line) == 0 && *line)
		ft_rb(pass, 0);
	if (ft_strcmp("rr", *line) == 0 && *line)
		ft_rr(pass, 0);
	if (ft_strcmp("rra", *line) == 0 && *line)
		ft_rra(pass, 0);
	if (ft_strcmp("rrb", *line) == 0 && *line)
		ft_rrb(pass, 0);
	if (ft_strcmp("rrr", *line) == 0 && *line)
		ft_rrr(pass, 0);
}
