/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Push_Swap_Command.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leonel <leonel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 17:07:29 by lscheupl          #+#    #+#             */
/*   Updated: 2024/08/16 14:46:57 by leonel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_Swap.h"

void	ft_swap_a(t_pile *stack_a, t_writing_status status)
{
	int	swap;

	if (stack_a != NULL && stack_a->next != NULL)
	{
		swap = stack_a->content;
		stack_a = stack_a->next;
		stack_a->prev->content = stack_a->content;
		stack_a->content = swap;
	}
	if (status == do_not_write)
		return;
	ft_printf("sa\n");
}

void	ft_swap_b(t_pile *stack_b, t_writing_status status)
{
	int	swap;

	if (stack_b != NULL && stack_b->next != NULL)
	{
		swap = stack_b->content;
		stack_b = stack_b->next;
		stack_b->prev->content = stack_b->content;
		stack_b->content = swap;
	}
	if (status == do_not_write)
		return;
	ft_printf("sb\n");
}

void	ft_double_swap(t_pile *stack_a, t_pile *stack_b)
{
	ft_swap_a(stack_a, do_not_write);
	ft_swap_b(stack_b, do_not_write);
	ft_printf("ss\n");
}

void	ft_push_a(t_stacks *piles)
{
	int	cache;

	if (piles->stack_b != NULL)
	{
		ft_pilefirst(piles->stack_b);
		cache = (piles->stack_b)->content;
		if (piles->stack_a == NULL)
			piles->stack_a = ft_pilenew(cache);
		else
			ft_pileadd_front(&piles->stack_a, ft_pilenew(cache));
		if (piles->stack_b->next == NULL)
		{
			ft_pileclear(&(piles->stack_b), del);
			return ;
		}
		else
			(piles->stack_b) = (piles->stack_b)->next;
		ft_piledelone(((piles->stack_b)->prev), del);
		(piles->stack_b)->prev = NULL;
		*(piles->stack_b) = *piles->stack_b;
	}
	ft_printf("pb\n");
}

void	del(int *contenu)
{
	*contenu = 0;
}

void	ft_push_b(t_stacks *piles)
{
	int	cache;

	if (piles->stack_a != NULL)
	{
		ft_pilefirst(piles->stack_a);
		cache = (piles->stack_a)->content;
		if (piles->stack_b == NULL)
			piles->stack_b = ft_pilenew(cache);
		else
			ft_pileadd_front(&piles->stack_b, ft_pilenew(cache));
		if (piles->stack_a->next == NULL)
		{
			ft_pileclear(&(piles->stack_a), del);
			return ;
		}
		else
			(piles->stack_a) = (piles->stack_a)->next;
		ft_piledelone(((piles->stack_a)->prev), del);
		(piles->stack_a)->prev = NULL;
		*(piles->stack_a) = *piles->stack_a;
	}
	ft_printf("pb\n");
}

void	ft_rotate_a(t_stacks *piles, t_writing_status status)
{
	int	value;

	value = (piles->stack_a)->content;
	ft_pileadd_back(&(piles->stack_a), ft_pilenew(value));
	(piles->stack_a) = (piles->stack_a)->next;
	ft_piledelone((piles->stack_a->prev), del);
	piles->stack_a->prev = NULL;
	*(piles->stack_a) = *piles->stack_a;
	if (status == do_not_write)
		return;
	ft_printf("ra\n");
}

void	ft_rotate_b(t_stacks *piles, t_writing_status status)
{
	int	value;

	piles->stack_b = ft_pilefirst(piles->stack_b);
	value = piles->stack_b->content;
	ft_pileadd_back(&(piles->stack_b), ft_pilenew(value));
	(piles->stack_b) = (piles->stack_b)->next;
	ft_piledelone(((piles->stack_b)->prev), del);
	piles->stack_b->prev = NULL;
	*(piles->stack_b) = *piles->stack_b;
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
	int		value;
	t_pile	*first;
	t_pile	*bf_last;

	first = ft_pilefirst(piles->stack_a);
	(piles->stack_a) = ft_pilelast(piles->stack_a);
	bf_last = (piles->stack_a)->prev;
	value = (piles->stack_a)->content;
	ft_pileadd_front(&(piles->stack_a), ft_pilenew(value));
	ft_piledelone(((piles->stack_a->next)), del);
	(piles->stack_a)->next = first;
	first->prev = piles->stack_a;
	bf_last->next = NULL;
	if (status == do_not_write)
		return;
	ft_printf("rra\n");
}

void	ft_reverse_rotate_b(t_stacks *piles, t_writing_status status)
{
	int		value;
	t_pile	*first;
	t_pile	*bf_last;

	first = ft_pilefirst(piles->stack_b);
	(piles->stack_b) = ft_pilelast(piles->stack_b);
	bf_last = (piles->stack_b)->prev;
	value = (piles->stack_b)->content;
	ft_pileadd_front(&(piles->stack_b), ft_pilenew(value));
	ft_piledelone(((piles->stack_b->next)), del);
	(piles->stack_b)->next = first;
	first->prev = piles->stack_b;
	bf_last->next = NULL;
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
