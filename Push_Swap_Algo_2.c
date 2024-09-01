/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Push_Swap_Algo_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leonel <leonel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 17:54:55 by lscheupl          #+#    #+#             */
/*   Updated: 2024/09/01 21:57:19 by leonel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_Swap.h"

void	case_b(t_stacks *piles, int *end_window, int *start_window)
{
	if (piles->stack_a->content <= *end_window && piles->stack_a->content >= *start_window)
	{
		ft_push_b(piles);
		*end_window = *end_window + 1;
		*start_window = *start_window + 1;
	}
	else if (piles->stack_a->content <= *start_window)
	{
		ft_push_b(piles);
		ft_rotate_b(piles, writing);
		*end_window = *end_window + 1;
		*start_window = *start_window + 1;
	}
	//else if ((piles->stack_a->next->content <= *end_window)
	//	&& (piles->stack_a->content <= (*end_window + 1)))
	//{
	//	ft_swap_a(piles, writing);
	//	ft_push_b(piles);
	//	*end_window = *end_window + 1;
	//}
	//else if (ft_pilelast(piles->stack_a)->content <= *end_window)
	//{
	//	ft_reverse_rotate_a(piles, writing);
	//	ft_push_b(piles);
	//	*end_window = *end_window + 1;
	//}
	else
	{
		if (ft_pilelast(piles->stack_a)->content <= *end_window)
		{
			ft_reverse_rotate_a(piles, writing);
		}
		while (!(piles->stack_a->content <= *end_window))
			ft_rotate_a(piles, writing);
		//ft_push_b(piles);
		//*end_window = *end_window + 1;
		//ft_push_b(piles);
		//ft_rotate_b(piles, writing);
	}
}

void	put_in_b(t_stacks *piles, int size)
{
	int	end_window;
	int start_window;

	end_window = determine_ratio(size);
	start_window = 0;
	while (ft_pilesize(piles->stack_a) > 3)
	{
		case_b(piles, &end_window, &start_window);
		if (ft_pilesize(piles->stack_b) > 2)
		{
			if (piles->stack_b->next->content > piles->stack_b->content)
				ft_swap_b(piles, writing);
		}
		//while (ft_pilelast(piles->stack_b)->content <= percent && ft_pilelast(piles->stack_b)->content > cap_value)
		//{
		//		ft_reverse_rotate_b(piles, writing);
		//		if (piles->stack_b->next->content > piles->stack_b->content)
		//			ft_swap_b(piles, writing);
		//}
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
