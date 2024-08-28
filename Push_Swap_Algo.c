/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Push_Swap_Algo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscheupl <lscheupl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 16:10:22 by leonel            #+#    #+#             */
/*   Updated: 2024/08/28 17:40:26 by lscheupl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_Swap.h"

void	ft_sort_small_pile(t_stacks *piles)
{
	if (piles->stack_a->content > piles->stack_a->next->content
		&& piles->stack_a->content < piles->stack_a->next->next->content)
		ft_swap_a(piles, writing);
	else if (piles->stack_a->content > piles->stack_a->next->next->content)
	{
		if (piles->stack_a->content < piles->stack_a->next->content)
			ft_reverse_rotate_a(piles, writing);
		else
		{
			ft_rotate_a(piles, writing);
			if (piles->stack_a->content > piles->stack_a->next->content)
				ft_swap_a(piles, writing);
		}
	}
	else if (piles->stack_a->next->content
		> piles->stack_a->next->next->content)
	{
		ft_reverse_rotate_a(piles, writing);
		if (piles->stack_a->content > piles->stack_a->next->content)
			ft_swap_a(piles, writing);
	}
}

int	ft_check_sorting(t_stacks *piles)
{
	piles->stack_a = ft_pilefirst(piles->stack_a);
	while (piles->stack_a->next != NULL)
	{
		if (piles->stack_a->content < piles->stack_a->next->content)
		{
			piles->stack_a = piles->stack_a->next;
		}
		else
		{
			return (0);
		}
	}
	return (1);
}

void	ft_sort_big_pile(t_stacks *piles, int size)
{
	put_in_b(piles, size);
}

void	ft_sort_piles(t_stacks *piles, int *tab_sorted, int *tab_ori, int words)
{
	ft_sort_int_tab(&tab_ori, words);
	if (ft_pilesize(piles->stack_a) <= 3)
	{
		ft_sort_small_pile(piles);
	}
	else
		ft_sort_big_pile(piles, words);
	free(tab_sorted);
}
