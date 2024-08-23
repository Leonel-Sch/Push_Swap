/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Algo2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscheupl <lscheupl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 17:54:55 by lscheupl          #+#    #+#             */
/*   Updated: 2024/08/23 18:17:31 by lscheupl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_Swap.h"

// void	ft_make_optimal_moove(t_stacks *piles, int mediane)
//{
//	int pos;
//	int value;
//	int i;

//	pos = ft_opti_on_top_a(piles);
//	while (i < pos)
//	{
//		piles->stack_a = piles->stack_a->next;
//		i++;
//	}
//	value = piles->stack_b->content;
//	piles->stack_a = ft_pilefirst(piles->stack_a);
//	if (value < mediane)
//	{
//		if (pos < ft_pilesize(piles->stack_a)/2)
//		{

//		}
//		else
//		{

//		}
//	}
//	else
//	{
//		if (pos < ft_pilesize(piles->stack_a)/2)
//		{

//		}
//		else
//		{

//		}
//	}
//}

void	put_in_b(t_stacks *piles, int size)
{
	int percent;
	float ratio;

	if (size < 200)
		ratio = 0.10;
	else
		ratio = 0.04;
	if (size < 10)
		percent = 1;
	else
		percent = (size * ratio);
	while (ft_pilesize(piles->stack_a) > 3)
	{
		if (piles->stack_a->content <= percent)
		{
			ft_push_b(piles);
			percent++;
		}
		else if((piles->stack_a->next->content <= percent) && (piles->stack_a->content <= (percent + 1)))
			ft_swap_a(piles, writing);
		else
			ft_rotate_a(piles, writing);
	}
	//ft_print_pile(piles->stack_b);
	//ft_print_pile(piles->stack_a);
	ft_sort_small_pile(piles);
	ft_max_in_a(piles, size);
}

void	ft_max_in_a(t_stacks *piles, int size_b)
{
	int max_pos;
	int i;

	i = 3;

	piles->stack_b = ft_pilefirst(piles->stack_b);
	while (piles->stack_b != NULL)
	{
		piles->stack_b = ft_pilefirst(piles->stack_b);
		size_b = ft_pilesize(piles->stack_b);
		piles->stack_b = ft_pilefirst(piles->stack_b);
		max_pos = ft_where_is_max(piles);
		piles->stack_b = ft_pilefirst(piles->stack_b);
		if (max_pos > size_b / 2)
		{
			while (max_pos < size_b)
			{
				ft_reverse_rotate_b(piles, writing);
				max_pos++;
			}
			piles->stack_b = ft_pilefirst(piles->stack_b);
			while (ft_pilelast(piles->stack_a)->content > piles->stack_b->content && i > 0)
			{
				i--;
				ft_reverse_rotate_a(piles, writing);
			}
			ft_push_a(piles);
		}
		else
		{
			while (max_pos > 0)
			{
				if (max_pos == 1)
					ft_swap_b(piles, writing);
				else
					ft_rotate_b(piles, writing);
				max_pos--;
			}
			piles->stack_b = ft_pilefirst(piles->stack_b);
			while (ft_pilelast(piles->stack_a)->content > piles->stack_b->content && i > 0)
			{
				i--;
				ft_reverse_rotate_a(piles, writing);
			}
			ft_push_a(piles);
		}
	}
}

int	ft_where_is_max(t_stacks *piles)
{
	int pos;
	int max_value;

	pos = 0;
	max_value = -1;
	while (piles->stack_b->next != NULL)
	{
		if (piles->stack_b->content > max_value)
			max_value = piles->stack_b->content;
		else
		piles->stack_b = piles->stack_b->next;
	}
	if (piles->stack_b->content > max_value)
			max_value = piles->stack_b->content;
	piles->stack_b = ft_pilefirst(piles->stack_b);
	if (ft_pilesize(piles->stack_b) == 1)
		return (0);
	while (piles->stack_b->content != max_value)
	{
		piles->stack_b = piles->stack_b->next;
		pos++;
	}
	return (pos);
}
