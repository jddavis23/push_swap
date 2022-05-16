/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 13:06:22 by jdavis            #+#    #+#             */
/*   Updated: 2022/05/16 13:06:44 by jdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.c"

t_info	*ft_create(t_info *pass, int argc, char *argv[])
{
	int	count;
	int	i;

	count = 0;
	i = 1;
	if (argc == 1 && argv)
		return (NULL);
	pass = (t_info *) malloc(sizeof(t_info));
	if (!pass)
		return (NULL);
	while (i < argc)
		count += ft_numb_count(argv[i++]);
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

