/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Push_Swap_Commands_3.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscheupl <lscheupl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 16:41:54 by lscheupl          #+#    #+#             */
/*   Updated: 2024/08/30 16:52:07 by lscheupl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_Swap.h"

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
		return ;
	ft_printf("rrb\n");
}

void	ft_double_reverse_rotate(t_stacks *piles)
{
	ft_reverse_rotate_a(piles, do_not_write);
	ft_reverse_rotate_b(piles, do_not_write);
	ft_printf("rrr\n");
}
