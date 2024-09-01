/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Push_Swap_Algo_Utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leonel <leonel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 16:43:44 by leonel            #+#    #+#             */
/*   Updated: 2024/09/01 21:48:43 by leonel           ###   ########.fr       */
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
	int	i;
	int	j;
	int	cache;
	int	*tmp;

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

int	determine_ratio(int size)
{
	float	ratio;

	if (size < 200)
		ratio = 0.10;
	else
		ratio = 0.04;
	return (size * ratio);
}

void	by_the_bottom(int max_pos, int size, int *i, t_stacks *piles)
{
	while (max_pos < size)
	{
		ft_reverse_rotate_b(piles, writing);
		max_pos++;
	}
	on_top_of_a(piles, i);
}
