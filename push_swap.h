/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 12:12:33 by jdavis            #+#    #+#             */
/*   Updated: 2022/06/03 13:11:59 by jdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "libft/ft_printf.h"

typedef struct	s_info
{
	int		*a;
	int		*b;
	int		*lis_arr;
	int		*sequence;
	int		lis;
	int		lis_pos;
	int		a_len;
	int		b_len;
	int		total;
	int		min;
	int		min_pos;
	int		max;
	int		max_pos;
	int		min_b;
	int		min_b_pos;
}				t_info;

void	ft_sa(t_info *pass);
void	ft_sb(t_info *pass);
void	ft_ss(t_info *pass);
void	ft_pa(t_info *pass);
void	ft_pb(t_info *pass);
void	ft_ra(t_info *pass);
void	ft_rb(t_info *pass);
void	ft_rr(t_info *pass);
void	ft_rra(t_info *pass);
void	ft_rrb(t_info *pass);
void	ft_rrr(t_info *pass);
int		ft_solved(t_info *pass);
void	ft_compare(t_info *pass, char **line);
int		ft_collect(t_info * pass, char *argv[], int argc);
int		ft_error(t_info *pass);
t_info	*ft_create(t_info *pass, int total, char *str[]);
int		ft_dup_option_check(t_info *pass);
int		ft_dup(t_info *pass);

#endif
