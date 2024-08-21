/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Push_Swap_Algo_Utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscheupl <lscheupl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 16:43:44 by leonel            #+#    #+#             */
/*   Updated: 2024/08/21 16:37:18 by lscheupl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_Swap.h"

void	ft_sort_tab(long long **tab, int quantity)
{
	int			i;
	int			j;
	long long	cache;
	long long	*tmp;

	tmp = *tab;
	i = 0;
	while (i < quantity)
	{
		j = 0;
		while (j < quantity - 1)
		{
			if (tmp[j] > tmp[j + 1])
			{
				cache = tmp[j];
				tmp[j] = tmp[j + 1];
				tmp[j + 1] = cache;
			}
			j++;
		}
		i++;
	}
}

void	ft_sort_int_tab(int **tab, int quantity)
{
	int i;
	int j;
	int cache;
	int *tmp;

	tmp = *tab;

	i = 0;
	while (i < quantity)
	{
		j = 0;
		while (j < quantity - 1)
		{
			if (tmp[j] > tmp[j + 1])
			{
				cache = tmp[j];
				tmp[j] = tmp[j + 1];
				tmp[j + 1] = cache;
			}
			j++;
		}
		i++;
	}
}
