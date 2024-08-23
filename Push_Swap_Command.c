/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Push_Swap_Command.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscheupl <lscheupl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 17:07:29 by lscheupl          #+#    #+#             */
/*   Updated: 2024/08/23 17:40:26 by lscheupl         ###   ########.fr       */
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
		return;
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
	//if (piles->stack_b != NULL)
	piles->stack_b->prev = NULL;
	cache->next = piles->stack_b->next;
	if (cache->next != NULL)
		cache->next->prev = cache;
	piles->stack_b->next = cache;
	cache->prev = piles->stack_b;
	if (status == do_not_write)
		return;
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

void	ft_push_b(t_stacks *piles)
{
	t_pile	*cache;

	if (piles->stack_a == NULL)
	{
		//printf("am out\n");
		return ;
	}
	cache = piles->stack_b;
	piles->stack_b = piles->stack_a;
	piles->stack_a = piles->stack_a->next;
	piles->stack_b->next = cache;
	if (cache != NULL)
		cache->prev = piles->stack_b;
	if (piles->stack_a != NULL)
		piles->stack_a->prev = NULL;

	
	//piles->stack_b = ft_pilefirst(piles->stack_b);
	//ft_print_pile(piles->stack_b);
	ft_printf("pb\n");
}

void	ft_rotate_a(t_stacks *piles, t_writing_status status)
{
	t_pile	*cache;
	
	if (piles->stack_a == NULL || piles->stack_a->next == NULL)
		return;
	cache = piles->stack_a;
	piles->stack_a = piles->stack_a->next;
	piles->stack_a->prev = NULL;
	cache->next = NULL;
	cache->prev = ft_pilelast(piles->stack_a);
	cache->prev->next = cache;
	piles->stack_a = ft_pilefirst(piles->stack_a);
	if (status == do_not_write)
		return;
	ft_printf("ra\n");
}

void	ft_rotate_b(t_stacks *piles, t_writing_status status)
{
	t_pile	*cache;
	
	if (piles->stack_b == NULL || piles->stack_b->next == NULL)
		return;
	piles->stack_b = ft_pilefirst(piles->stack_b);
	cache = piles->stack_b;
	piles->stack_b = piles->stack_b->next;
	piles->stack_b->prev = NULL;
	cache->next = NULL;
	cache->prev = ft_pilelast(piles->stack_b);
	cache->prev->next = cache;
	piles->stack_b = ft_pilefirst(piles->stack_b);
	if (status == do_not_write)
		return;
	ft_printf("rb\n");
}

void	ft_double_rotate(t_stacks *piles)
{
	ft_rotate_a(piles, do_not_write);
	ft_rotate_b(piles, do_not_write);
	ft_printf("rr\n");
}

void	ft_reverse_rotate_a(t_stacks *piles, t_writing_status status)
{
	t_pile	*cache;

	if (piles->stack_a == NULL || piles->stack_a->next == NULL)
		return ;
	cache = piles->stack_a;
	piles->stack_a = ft_pilelast(piles->stack_a);
	piles->stack_a->prev->next = NULL;
	piles->stack_a->prev = NULL;
	piles->stack_a->next = cache;
	cache->prev = piles->stack_a;
	if (status == do_not_write)
		return;
	ft_printf("rra\n");
}

void	ft_reverse_rotate_b(t_stacks *piles, t_writing_status status)
{
	t_pile	*cache;

	if (piles->stack_b == NULL || piles->stack_b->next == NULL)
		return ;
	cache = piles->stack_b; 
	piles->stack_b = ft_pilelast(piles->stack_b);
	piles->stack_b->prev->next = NULL;
	piles->stack_b->prev = NULL;
	piles->stack_b->next = cache;
	cache->prev = piles->stack_b;
	if (status == do_not_write)
		return;
	ft_printf("rrb\n");
}

void	ft_double_reverse_rotate(t_stacks *piles)
{
	ft_reverse_rotate_a(piles, do_not_write);
	ft_reverse_rotate_b(piles, do_not_write);
	ft_printf("rrr\n");
}
