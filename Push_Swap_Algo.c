/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Push_Swap_Algo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leonel <leonel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 16:10:22 by leonel            #+#    #+#             */
/*   Updated: 2024/08/16 22:02:11 by leonel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_Swap.h"

void ft_sort_small_pile(t_stacks *piles, t_sorting_status *status)
{
	*status = sorting;
	if (ft_pilesize(piles->stack_a) == 2)
		ft_swap_a(piles, writing);
	else
	{
		if (First < Second && Second > Third)
		{
			if (Third > First)
			{
				ft_swap_a(piles, writing);
				ft_rotate_a(piles, writing);
			}
			else
				ft_reverse_rotate_a(piles, writing);
		}
		if (First > Second)
		{
			if (Second > Third)
			{
				ft_swap_a(piles, writing);
				ft_reverse_rotate_a(piles, writing);
			}
			else
			{
				if (First > Third)
					ft_rotate_a(piles, writing);
				else 
					ft_swap_a(piles, writing);
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
		ft_swap_b(piles, writing);
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
	t_pile *cache;

	i = 0;
	size = ft_pilesize(piles->stack_b);
	//piles->stack_b = ft_pilefirst(piles->stack_b);
	//printf("\n\n %d \n\n", piles->stack_b->content);
	cache = piles->stack_b;
	while (value <= cache->content)
	{
		cache = piles->stack_b;
		if (cache == NULL)
			return (i);
		piles->stack_b = cache;
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
		ft_print_pile(piles->stack_b);
		value = ft_pilefirst(piles->stack_b)->content;
		number = ft_target_position(value, piles);
		i = 0;
		while (i < number)
		{
			ft_swap_b(piles, writing);
			ft_rotate_b(piles, writing);
			i++;
		}
		ft_print_pile(piles->stack_b);
		while (i > 0)
		{
			ft_reverse_rotate_b(piles, writing);
			i--;
		}
		ft_print_pile(piles->stack_b);
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
	//ft_print_pile(piles->stack_b);
	//ft_print_pile(piles->stack_a);
	ft_initialize_sorting(piles);
	//ft_print_pile(piles->stack_b);
	//printf("\n");
	//ft_print_pile(piles->stack_a);
	ft_check_optimal_moove(piles, mediane);
	//ft_print_pile(piles->stack_b);
	//printf("\n");
	//ft_print_pile(piles->stack_a);
	//ft_check_reverse_sorting_b(piles);
	//ft_print_pile(piles->stack_a);
	
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
	ft_print_pile(piles->stack_b);
}