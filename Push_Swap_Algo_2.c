/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Push_Swap_Algo_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscheupl <lscheupl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 17:54:55 by lscheupl          #+#    #+#             */
/*   Updated: 2024/08/30 20:11:38 by lscheupl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_Swap.h"

int	determine_ratio(int size)
{
	float	ratio;

	if (size < 200)
		ratio = 0.10;
	else
		ratio = 0.04;
	return (size * ratio);
}

void	put_in_b(t_stacks *piles, int size)
{
	int	percent;

	percent = determine_ratio(size);
	while (ft_pilesize(piles->stack_a) > 3)
	{
		if (piles->stack_a->content <= percent)
		{
			ft_push_b(piles);
			percent++;
		}
		else if ((piles->stack_a->next->content <= percent)
			&& (piles->stack_a->content <= (percent + 1)))
		{
			ft_swap_a(piles, writing);
			ft_push_b(piles);
			percent++;
		}
		else if (ft_pilelast(piles->stack_a)->content <= percent)
		{
			ft_reverse_rotate_a(piles, writing);
			ft_push_b(piles);
			percent++;
		}
		else
		{
			while (!(piles->stack_a->content <= percent))
			{
				ft_rotate_a(piles, writing);
			}
			ft_push_b(piles);
			percent++;
		}
		if (ft_pilesize(piles->stack_b) > 2)
		{
			if (piles->stack_b->next->content > piles->stack_b->content)
				ft_swap_b(piles, writing);
		}
	}
	ft_sort_small_pile(piles);
	ft_max_in_a(piles, size);
}

void	on_top_of_a(t_stacks *piles, int *i)
{
	if (ft_pilesize(piles->stack_a) == 3 && ft_pilesize(piles->stack_b) < 3
		&& ft_pilelast(piles->stack_a)->content > piles->stack_b->content)
	{
		ft_push_a(piles);
		*i = 0;
		return ;
	}
	while (ft_pilelast(piles->stack_a)->content > piles->stack_b->content
		&& *i > 0)
	{
		*i = *i - 1;
		ft_reverse_rotate_a(piles, writing);
	}
	ft_push_a(piles);
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

void	ft_max_in_a(t_stacks *piles, int size_b)
{
	int	max_pos;
	int	i;

	i = 3;
	while (piles->stack_b != NULL)
	{
		size_b = ft_pilesize(piles->stack_b);
		max_pos = ft_where_is_max(piles);
		if (max_pos >= size_b / 2)
			by_the_bottom(max_pos, size_b, &i, piles);
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
			on_top_of_a(piles, &i);
		}
	}
}

int	ft_where_is_max(t_stacks *piles)
{
	int	pos;
	int	max_value;

	pos = 0;
	max_value = -1;
	piles->stack_b = ft_pilefirst(piles->stack_b);
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
	piles->stack_b = ft_pilefirst(piles->stack_b);
	return (pos);
}
