/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Push_Swap_Parsing.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscheupl <lscheupl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 20:00:01 by lscheupl          #+#    #+#             */
/*   Updated: 2024/08/28 16:03:15 by lscheupl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_Swap.h"

t_parsing_status	ft_check_long_long(long long *tab, int words)
{
	int	i;
	int	j;

	i = 0;
	while (i < words)
	{
		if (tab[i] > 2147483647 || tab[i] < -2147483648)
			return (INVALID_VALUE);
		j = i + 1;
		while (j < words)
		{
			if (tab[i] == tab[j])
				return (INVALID_VALUE);
			j++;
		}
		i++;
	}
	return (VALID_VALUE);
}

t_parsing_status	ft_isnumber(char **tab)
{
	int	i;
	int	j;

	i = 0;
	while (tab[i])
	{
		j = 1;
		if (ft_isdigit(tab[i][0]) != 2048 && tab[i][0] != '+'
			&& tab[i][0] != '-')
			return (INVALID_VALUE);
		if ((tab[i][0] == '+' || tab[i][0] == '-') && (tab[i][1] == '\0'))
			return (INVALID_VALUE);
		else
		{
			while (tab[i][j])
			{
				if (ft_isdigit(tab[i][j]) != 2048)
					return (INVALID_VALUE);
				j++;
			}
		}
		i++;
	}
	return (VALID_VALUE);
}

t_parsing_status	ft_check_values(char **tab, int words, long long *tabllong)
{
	int	i;

	i = 0;
	if (ft_isnumber(tab) == INVALID_VALUE)
		return (INVALID_VALUE);
	while (tab[i])
	{
		tabllong[i] = ft_atoll(tab[i]);
		i++;
	}
	ft_free_tab(tab, words);
	if (ft_check_long_long(tabllong, words) == INVALID_VALUE)
		return (INVALID_VALUE);
	return (VALID_VALUE);
}

t_parsing_status	ft_parsing(long long *tabllong, int words, char *str)
{
	char	**tab;
	int		i;

	tab = NULL;
	i = 1;
	i++;
	tab = ft_split(str, 32);
	if (ft_check_values(tab, words, tabllong) == INVALID_VALUE)
		return (INVALID_VALUE);
	return (VALID_VALUE);
}

char	*ft_make_string(char *str, int argc, char **argv)
{
	int	i;

	i = 2;
	if (argc >= 2)
	{
		str = malloc(sizeof(char) * ft_lenarg(argv) + 1);
		if (!str)
			return (free(str), NULL);
		ft_strcpy(argv[1], str);
		if (argc > 2)
			ft_strcat(str, " ");
		while (argv[i])
		{
			ft_strcat(str, argv[i]);
			ft_strcat(str, " ");
			i++;
		}
	}
	return (str);
}
