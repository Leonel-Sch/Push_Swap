/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Push_Swap_Algo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leonel <leonel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 16:10:22 by leonel            #+#    #+#             */
/*   Updated: 2024/08/31 22:09:44 by leonel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_Swap.h"

void	ft_sort_small_pile(t_stacks *piles)
{
	if (ft_pilesize(piles->stack_a) == 2)
		return (ft_swap_a(piles, writing));
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
			piles->stack_a = ft_pilefirst(piles->stack_a);
			return (0);
		}
	}
	piles->stack_a = ft_pilefirst(piles->stack_a);
	return (1);
}

void	ft_sort_big_pile(t_stacks *piles, int size)
{
	put_in_b(piles, size);
}

void	ft_sort_piles(t_stacks *piles, int *tab_sorted, int *tab_ori, int words)
{
	piles->stack_b = NULL;
	ft_sort_int_tab(&tab_ori, words);
	if (ft_pilesize(piles->stack_a) <= 3)
	{
		ft_sort_small_pile(piles);
	}
	else
		ft_sort_big_pile(piles, words);
	tab_sorted = NULL;
	free(tab_sorted);
}
