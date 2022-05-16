/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collect_arg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 10:53:28 by jdavis            #+#    #+#             */
/*   Updated: 2022/05/16 10:54:00 by jdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	*ft_strnccpy(char *dest, char *src, int i)
{
	ft_strncpy(dest, src, i);
	dest[i] = '\0';
	return (dest);
}

int	ft_collect(t_info *pass, char *argv[], int argc)
{
	int	len;
	int	i;
	char	dest[12];
	int		hold;

	i = 1;
	while (i < argc)
	{
		len = 0;
		while (len < (int)ft_strlen(argv[i]))
		{
			while (argv[i][len] != ' ' && argv[i][len] != '\0')
			{
				if (argv[i][len] < '0' || argv[i][len] > '9')
				{
					if (argv[i][len] == '-' && (len == 0 || argv[i][len - 1] == ' '))
						break ;
					return (ft_error(pass));
				}
				++len;
			}
			++len;
		}
		len = 0;
		while (len < (int)ft_strlen(argv[i]))
		{
			while (argv[i][len] == ' ')
				++len;
			hold = ft_strlen_stop(&argv[i][len], ' ');
			if (hold > 11 || (argv[i][len] == '-' && hold >= 11 && ft_strcmp("-2147483648", ft_strnccpy(dest, &argv[i][len], hold)) < 0))
				return (ft_error(pass));
			if (ft_strcmp("2147483647", ft_strnccpy(dest, &argv[i][len], hold)) < 0 && hold >= 10)
				return (ft_error(pass));
			pass->a[pass->a_len++]  = ft_atoi(&argv[i][len]);
			len += hold;
		}
		++i;
	}
	if (pass->a_len != pass->total)
		ft_printf("MEZZ UPPP\n"); //remove when done
	return (1); //this should return a count of ints
}

