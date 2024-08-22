/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Push_Swap_Algo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscheupl <lscheupl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 16:10:22 by leonel            #+#    #+#             */
/*   Updated: 2024/08/22 14:42:03 by lscheupl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_Swap.h"

void ft_sort_small_pile(t_stacks *piles)
{
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

void	ft_check_sorting(t_stacks *piles)
{
	int size;piles->stack_a = piles->stack_a->next;
	int i;

	
	ft_pilefirst(piles->stack_a);
	size = ft_pilesize(piles->stack_a);
	i = 0;
	while (piles->stack_a->next != NULL)
	{
		if(First < Second)
		{
			piles->stack_a = piles->stack_a->next;
			i++;
		}
		else
		{
			ft_printf("Sorting failed at %d\n", i);
			return ;
		}
	}
	ft_printf("Sorted !\n");
}
//void	ft_initialize_sorting(t_stacks *piles)
//{
//	ft_push_b(piles);
//	ft_push_b(piles);
//	if (piles->stack_b->content < piles->stack_b->next->content)
//		ft_swap_b(piles, writing);
//}
//int	ft_mediane(int *tab, int quantity)
//{
//	if ((quantity%2) == 0)
//		return (tab[quantity/2]);
//	return ((tab[quantity/2] + tab[quantity/2 + 1])/2);
//}

//int ft_target_position(int value, t_stacks *piles)
//{
//	int i;
//	int size;
//	t_pile *cache;

//	i = 0;
//	piles->stack_b = ft_pilefirst(piles->stack_b);
//	size = ft_pilesize(piles->stack_b);
//	cache = piles->stack_b;
//	while (value <= cache->content)
//	{
//		cache = piles->stack_b->next;
//		if (cache == NULL)
//			return (i);
//		piles->stack_b = cache;
//		i++;
//		if (i == size)
//			return (i);
//	}
//	piles->stack_b = ft_pilefirst(piles->stack_b);
//	return (i);
//}
//int	ft_calcul(int value, int size)
//{
//	if (value == 1 || value == size)
//			value = 2;
//	else if (value == 0)
//		value = 1;
//	else
//		value = (value-1)*2+value;
//	return (value);
//}

//void	ft_top_a(t_stacks *piles, int pos, int size_a)
//{
//	if (pos <= size_a/2)
//	{
//		while (pos > 0)
//		{
//			ft_rotate_a(piles, writing);
//			pos--;
//		}
//	}
//	else
//	{
//		while (pos <= size_a)
//		{
//			ft_reverse_rotate_a(piles, writing);
//			pos++;
//		}
//	}
//	piles->stack_a = ft_pilefirst(piles->stack_a);
//}

//void	ft_opti_on_top_a(t_stacks *piles)
//{
//	int pos_opt;
//	int cache1;
//	int cache2;
//	int size_a;
//	int i;
//	int j;

//	size_a = ft_pilesize(piles->stack_a);
//	j = 0;
//	pos_opt = 0;
//	piles->stack_a = ft_pilefirst(piles->stack_a);
//	cache1 = ft_target_position(piles->stack_a->content, piles);
//	if (cache1 > ft_pilesize(piles->stack_b)/2)
//	{
//		cache1 = ft_pilesize(piles->stack_b) - cache1;
//	}
//	cache1 = ft_calcul(cache1, ft_pilesize(piles->stack_b));
//	i = 0;
//	while (i < size_a / 2)
//	{
//		piles->stack_a = piles->stack_a->next;
//		cache2 = ft_target_position(piles->stack_a->content, piles);
//		cache2 = ft_calcul(cache2, ft_pilesize(piles->stack_b)) + i + 1;
//		if (cache2 < cache1 )
//		{
//			cache1 = cache2;
//			pos_opt = i;
//		}
//		i++;
//	}
//	i = size_a;
//	piles->stack_a = ft_pilelast(piles->stack_a);
//	while (i > size_a / 2)
//	{
//		cache2 = ft_pilesize(piles->stack_b) - ft_target_position(piles->stack_a->content, piles);
//		cache2 = ft_calcul(cache2, ft_pilesize(piles->stack_b)) + j + 1;
//		if (cache2 < cache1 )
//		{
//			cache1 = cache2;
//			pos_opt = i;
//		}
//		piles->stack_a = piles->stack_a->prev;
//		i--;
//		j++;
//	}
//	piles->stack_a = ft_pilefirst(piles->stack_a);
//	//ft_top_a(piles, pos_opt, size_a);
//	return (pos_opt);
//}

//void	ft_check_optimal_moove(t_stacks *piles, int mediane)
//{
//	int number;
//	int value;
//	int	i;

//	i = 0;
//	mediane++;
//	while (ft_pilesize(piles->stack_a) > 3)
//	{
//		piles->stack_b = ft_pilefirst(piles->stack_b);
//		ft_opti_on_top_a(piles);
//		value = ft_pilefirst(piles->stack_a)->content;
//		number = ft_target_position(value, piles);
//		piles->stack_b = ft_pilefirst(piles->stack_b);
//		ft_push_b(piles);
//		i = 0;
//		piles->stack_b = ft_pilefirst(piles->stack_b);
//		if (number == 0)
//			number = 0;
//		else if (number == ft_pilesize(piles->stack_b) - 2 && value < ft_pilelast(piles->stack_b)->content)
//		{
//			ft_rotate_b(piles, writing);
//		}
//		else if (number == 1)
//			ft_swap_b(piles, writing);
//		else
//		{
//			if (number <= ft_pilesize(piles->stack_b) / 2)
//			{
//				while (i < number - 1)
//				{
//					ft_swap_b(piles, writing);
//					ft_rotate_b(piles, writing);
//					i++;
//				}
//				ft_swap_b(piles, writing);
//				while (i > 0)
//				{
//					ft_reverse_rotate_b(piles, writing);
//					i--;
//				}
//			}
//			else
//			{
//				while (i < ft_pilesize(piles->stack_b) - number - 1)
//				{
//					ft_reverse_rotate_b(piles, writing);
//					ft_swap_b(piles, writing);
//					i++;
//				}
//				ft_rotate_b(piles, writing);
//				while (i > 0)
//				{
//					ft_rotate_b(piles, writing);
//					i--;
//				}
//			}
//		}
//	}
//	ft_sort_small_pile(piles);
//	piles->stack_b = ft_pilefirst(piles->stack_b);
//	i = 3;
//	while (piles->stack_b->next != NULL)
//	{
//		while (ft_pilelast(piles->stack_a)->content > ft_pilefirst(piles->stack_b)->content && i > 0)
//		{
//			ft_reverse_rotate_a(piles, writing);
//			i--;
//		}
//		ft_push_a(piles);
//	}
//	//if (ft_pilelast(piles->stack_a)->content < ft_pilefirst(piles->stack_a)->content)
//	//{
//	//	ft_rotate_a(piles, writing);
//	//	ft_push_a(piles);
//	//}
//	while (ft_pilelast(piles->stack_a)->content < ft_pilefirst(piles->stack_a)->content)
//	{
//		//if (piles->stack_b->content > )
//		ft_reverse_rotate_a(piles, writing);
//	}
//	if (piles->stack_b != NULL)
//		ft_push_a(piles);
//}

void	ft_sort_big_pile(t_stacks *piles, int size)
{
	//int mediane;

	//mediane = ft_mediane(tab, ft_pilesize(piles->stack_a));
	//printf("mediane : %d\n", mediane);
	//ft_initialize_sorting(piles);
	//ft_check_optimal_moove(piles, mediane);
	put_in_b(piles, size);
}

void	ft_sort_piles(t_stacks *piles, int *tab_sorted, int *tab_ori, int words)
{
	//int i = 0;

	ft_sort_int_tab(&tab_ori, words);
	if (ft_pilesize(piles->stack_a) <= 3)
	{
		ft_sort_small_pile(piles);
	}
	else
		ft_sort_big_pile(piles, words);
	//ft_check_sorting(piles);
	//ft_print_pile(piles->stack_a);
	//ft_reverse_rotate_a(piles, do_not_write);
	//ft_reverse_rotate_a(piles, do_not_write);
	//ft_reverse_rotate_a(piles, do_not_write);
	//ft_reverse_rotate_a(piles, do_not_write);
	//printf("\n");
	//ft_print_pile(piles->stack_a);
	//ft_push_b(piles);
	//ft_push_b(piles);
	//ft_push_b(piles);
	//printf("\n");
	//ft_push_a(piles);
	//ft_push_a(piles);
	//ft_push_a(piles);
	ft_print_pile(piles->stack_a);
	printf("just for tab and words %d%d", tab_sorted[0], words);
}