/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Push_Swap_Pile.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscheupl <lscheupl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 17:00:24 by lscheupl          #+#    #+#             */
/*   Updated: 2024/08/12 19:55:22 by lscheupl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_Swap.h"

t_pile	*ft_pilefirst(t_pile *pile)
{
	t_pile	*cache;

	cache = NULL;
	if (pile == NULL)
		return (pile);
	while (pile != NULL)
	{
		cache = pile->prev;
		if (cache == NULL)
			return (pile);
		pile = cache;
	}
	return (pile);
}

void	ft_print_pile(t_pile *stack)
{
	t_pile	*cache;

	cache = ft_pilefirst(stack);
	while (cache != NULL)
	{
		ft_printf("lst : %d\n", cache->content);
		cache = cache->next;
	}
}

void	ft_make_pile(long long *tab, int words)
{
	t_stacks	piles;
	int			i;

	i = 0;
	piles.stack_a = ft_pilenew((int)tab[i]);
	i++;
	while (i < words)
	{
		ft_pileadd_front(&piles.stack_a, ft_pilenew((int)tab[i]));
		i++;
	}
	piles.stack_b = NULL;
	ft_printf("\n ----------- \n\n");
	ft_printf("\n Stack A start\n");
	ft_print_pile(piles.stack_a);
	ft_printf("\n ----------- \n\n");
	ft_swap_a(piles.stack_a, writing);
	ft_rotate_a(&piles, writing);
	ft_push_b(&piles);
	ft_swap_a(piles.stack_a, writing);
	ft_swap_a(piles.stack_a, writing);
	ft_print_pile(piles.stack_a);
	ft_printf("\n ----------- \n\n");
	ft_pileclear(&piles.stack_a, del);
	ft_pileclear(&piles.stack_b, del);
}
