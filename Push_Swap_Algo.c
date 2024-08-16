/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Push_Swap_Algo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leonel <leonel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 16:10:22 by leonel            #+#    #+#             */
/*   Updated: 2024/08/16 14:39:16 by leonel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_Swap.h"

void ft_sort_small_pile(t_stacks *piles, t_sorting_status *status)
{
	*status = sorting;
	if (ft_pilesize(piles->stack_a) == 2)
		ft_swap_a(piles->stack_a, writing);
	else
	{
		if (First < Second && Second > Third)
		{
			if (Third > First)
			{
				ft_swap_a(piles->stack_a, writing);
				ft_rotate_a(piles, writing);
			}
			else
				ft_reverse_rotate_a(piles, writing);
		}
		if (First > Second)
		{
			if (Second > Third)
			{
				ft_swap_a(piles->stack_a, writing);
				ft_reverse_rotate_a(piles, writing);
			}
			else
			{
				if (First > Third)
					ft_rotate_a(piles, writing);
				else 
					ft_swap_a(piles->stack_a, writing);
			}
		}
	}
}

void	ft_check_sorting(t_stacks *piles, t_sorting_status *status, int *tab)
{
	int size;
	int i;

	ft_pilefirst(piles->stack_a);
	size = ft_pilesize(piles->stack_a);
	i = 0;
	while (i < size)
	{
		if (piles->stack_a->content == tab[i])
		{
			printf("%d : %d\n", piles->stack_a->content, tab[i]);
			i++;
			piles->stack_a = piles->stack_a->next;
		}
		else
		{
			ft_printf("Sorting as failed\n");
			*status = finished;
			ft_print_pile(piles->stack_a);
			return;
		}
	}
	*status = finished;
	ft_print_pile(piles->stack_a);
}
void	ft_initialize_sorting(t_stacks *piles)
{
	ft_push_b(piles);
	ft_push_b(piles);
	if (piles->stack_b->content < piles->stack_b->next->content)
		ft_swap_b(piles->stack_b, writing);
}
int	ft_mediane(int *tab, int quantity)
{
	if ((quantity%2) == 0)
		return (tab[quantity/2]);
	return ((tab[quantity/2] + tab[quantity/2 + 1])/2);
}

int ft_target_position(int value, t_stacks *piles)
{
	int i;
	int size;

	i = 0;
	piles->stack_b = ft_pilefirst(piles->stack_b);
	size = ft_pilesize(piles->stack_b);
	while (value <= piles->stack_b->content)
	{
		piles->stack_b = piles->stack_b->next;
		i++;
		if (i == size)
			return (i);
	}
	piles->stack_b = ft_pilefirst(piles->stack_b);
	return (i);
}

void	ft_check_optimal_moove(t_stacks *piles, int mediane)
{
	int number;
	int value;
	int	i;

	i = 0;
	mediane++;
	while (piles->stack_a != NULL)
	{
		ft_push_b(piles);
		value = ft_pilefirst(piles->stack_b)->content;
		number = ft_target_position(value, piles);
		while (i < number)
		{
			ft_swap_b(piles->stack_b, writing);
			ft_rotate_b(piles, writing);
			i++;
		}
		while (i > 0)
			ft_reverse_rotate_b(piles, writing);
	}
	while (piles->stack_b != NULL)
	{
		ft_push_a(piles);
	}
}

void	ft_sort_big_pile(t_stacks *piles, t_sorting_status *status, int *tab)
{
	int mediane;

	mediane = ft_mediane(tab, ft_pilesize(piles->stack_a));
	*status = sorting;
	ft_initialize_sorting(piles);
	ft_check_optimal_moove(piles, mediane);
	//ft_check_reverse_sorting_b(piles);
	
}

void	ft_sort_piles(t_stacks *piles, int *tab)
{
	t_sorting_status status;

	status = waiting;
	if (ft_pilesize(piles->stack_a) <= 3)
	{
		ft_sort_small_pile(piles, &status);
	}
	else
		ft_sort_big_pile(piles, &status, tab);

	//ft_check_sorting(piles, &status, tab);
	ft_print_pile(piles->stack_a);
}