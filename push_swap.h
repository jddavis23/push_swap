/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 12:12:33 by jdavis            #+#    #+#             */
/*   Updated: 2022/05/12 12:04:17 by jdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "libft/ft_printf.h"

typedef struct	s_info
{
	int		*a;
	int		*b;
	int		a_len;
	int		b_len;
	int		total;
}				t_info;

void	ft_sa(t_info *pass);
void	ft_sb(t_info *pass);
void	ft_ss(t_info *pass);
void	ft_pa(t_info *pass);
void	ft_pb(t_info *pass);

#endif
