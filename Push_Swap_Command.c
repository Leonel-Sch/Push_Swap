/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Push_Swap_Command.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscheupl <lscheupl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 17:07:29 by lscheupl          #+#    #+#             */
/*   Updated: 2024/08/30 16:52:02 by lscheupl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_Swap.h"

void	ft_swap_a(t_stacks *piles, t_writing_status status)
{
	t_pile	*cache;

	piles->stack_a = ft_pilefirst(piles->stack_a);
	if (piles->stack_a == NULL && piles->stack_a->next == NULL)
		return ;
	cache = piles->stack_a;
	piles->stack_a = piles->stack_a->next;
	piles->stack_a->prev = NULL;
	cache->next = piles->stack_a->next;
	if (cache->next != NULL)
		cache->next->prev = cache;
	piles->stack_a->next = cache;
	cache->prev = piles->stack_a;
	if (status == do_not_write)
		return ;
	ft_printf("sa\n");
}

void	ft_swap_b(t_stacks *piles, t_writing_status status)
{
	t_pile	*cache;

	piles->stack_b = ft_pilefirst(piles->stack_b);
	if (piles->stack_b == NULL || piles->stack_b->next == NULL)
		return ;
	cache = piles->stack_b;
	piles->stack_b = piles->stack_b->next;
	piles->stack_b->prev = NULL;
	cache->next = piles->stack_b->next;
	if (cache->next != NULL)
		cache->next->prev = cache;
	piles->stack_b->next = cache;
	cache->prev = piles->stack_b;
	if (status == do_not_write)
		return ;
	ft_printf("sb\n");
}

void	ft_double_swap(t_stacks *piles)
{
	ft_swap_a(piles, do_not_write);
	ft_swap_b(piles, do_not_write);
	ft_printf("ss\n");
}

void	ft_push_a(t_stacks *piles)
{
	t_pile	*cache;

	if (piles->stack_b == NULL)
		return ;
	cache = piles->stack_a;
	piles->stack_a = piles->stack_b;
	piles->stack_b = piles->stack_b->next;
	piles->stack_a->next = cache;
	if (cache != NULL)
		cache->prev = piles->stack_a;
	if (piles->stack_b != NULL)
		piles->stack_b->prev = NULL;
	ft_printf("pa\n");
}

void	del(int *contenu)
{
	*contenu = 0;
}
