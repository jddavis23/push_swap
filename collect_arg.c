/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collect_arg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 10:53:28 by jdavis            #+#    #+#             */
/*   Updated: 2022/06/30 12:07:30 by jdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	*ft_strnccpy(char *dest, char *src, int i)
{
	ft_strncpy(dest, src, i);
	dest[i] = '\0';
	return (dest);
}

static int	ft_helper(t_info *pass, char *argv[], int i)
{
	int	len;

	len = 0;
	while (len < (int)ft_strlen(argv[i]))
	{
		while (argv[i][len] != ' ' && argv[i][len] != '\0')
		{
			if (argv[i][len] < '0' || argv[i][len] > '9')
			{
				if (argv[i][len] == '-' && (len == 0 || argv[i][len - 1]
						== ' ') && (argv[i][len + 1] >= '0' && argv[i][len
							+ 1] <= '9'))
					break ;
				return (ft_error(pass));
			}
			++len;
		}
		++len;
	}
	return (0);
}

static int	ft_helper_error(char *str, int hold, char *dest)
{
	if (hold > 11 || (str[0] == '-' && hold >= 11
			&& ft_strcmp("-2147483648", ft_strnccpy(dest, str,
					hold)) < 0))
		return (-1);
	if (ft_strcmp("2147483647", ft_strnccpy(dest, str, hold))
		< 0 && hold >= 10)
		return (-1);
	return (0);
}

/*
 *	Helper function to exit if the end of the string happens early.
 */

static int	ft_helper_exit(char *str, int len, int *hold)
{
	if (str[len] == '\0')
		return (-1);
	*hold = ft_strlen_stop(&str[len], ' ');
	return (0);
}

int	ft_collect(t_info *pass, char *argv[], int argc)
{
	int		len;
	int		i;
	char	dest[12];
	int		hold;

	i = 1;
	while (i < argc)
	{
		if (ft_helper(pass, argv, i) == -1)
			return (-1);
		len = 0;
		while (len < (int)ft_strlen(argv[i]))
		{
			while (argv[i][len] == ' ')
				++len;
			if (ft_helper_exit(argv[i], len, &hold) == -1)
				break ;
			if (ft_helper_error(&argv[i][len], hold, dest) == -1)
				return (ft_error(pass));
			pass->a[pass->a_len++] = ft_atoi(&argv[i][len]);
			len += hold;
		}
		++i;
	}
	return (1);
}
