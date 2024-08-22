/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Algo2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscheupl <lscheupl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 17:54:55 by lscheupl          #+#    #+#             */
/*   Updated: 2024/08/22 15:26:45 by lscheupl         ###   ########.fr       */
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
	int fifteen;

	if (size < 7)
		fifteen = 1;
	else
		fifteen = (size * 0.15);
	while (ft_pilesize(piles->stack_a) > 3)
	{
		if (piles->stack_a->content <= fifteen)
		{
			ft_push_b(piles);
			fifteen++;
		}
		else
			ft_rotate_a(piles, writing);
	}
	ft_sort_small_pile(piles);
	ft_max_in_a(piles, size);
}

void	ft_max_in_a(t_stacks *piles, int size_b)
{
	int max_pos;
	int i;

	i = 3;

	ft_print_pile(piles->stack_b);
	ft_print_pile(piles->stack_a);
	piles->stack_b = ft_pilefirst(piles->stack_b);
	while (piles->stack_b != NULL)
	{
		piles->stack_b = ft_pilefirst(piles->stack_b);
		size_b = ft_pilesize(piles->stack_b);
		piles->stack_b = ft_pilefirst(piles->stack_b);
		max_pos = ft_where_is_max(piles);
		if (max_pos > size_b / 2)
		{
			while (max_pos < size_b)
			{
				ft_reverse_rotate_b(piles, writing);
				max_pos++;
			}
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
				ft_rotate_b(piles, writing);
				max_pos--;
			}
			while (ft_pilelast(piles->stack_a)->content > piles->stack_b->content && i > 0)
			{
				i--;
				ft_reverse_rotate_a(piles, writing);
			}
			ft_push_a(piles);
		}
		ft_print_pile(piles->stack_b);
		ft_print_pile(piles->stack_a);
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
