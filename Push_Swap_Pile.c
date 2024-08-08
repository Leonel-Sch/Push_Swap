/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Push_Swap_Pile.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscheupl <lscheupl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 17:00:24 by lscheupl          #+#    #+#             */
/*   Updated: 2024/08/08 18:14:27 by lscheupl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_Swap.h"

t_pile	*ft_pilefirst(t_pile *pile)
{
	t_pile	*cache;

	while (pile != NULL)
	{
		cache = pile->prev;
		if (cache == NULL)
			return (pile);
		pile = cache;
	}
	return (pile);
}

void	ft_print_pile_and_compare(long long *tab, t_pile *stack_a, int i)
{
	long long	*tab2;
	t_pile		*cache;

	tab2 = tab;
	cache = ft_pilefirst(stack_a);
	while (i >= 0)
	{
		ft_printf("lst : %d = %d : tab\n", cache->content, (int)tab[i]);
		cache = cache->next;
		i--;
	}
}

void	ft_make_pile(long long *tab, int words)
{
	t_pile	*stack_a;
	t_pile	*stack_b;
	int		i;

	i = 0
	stack_a = ft_pilenew((int)tab[i]);
	while (i < words)
	{
		ft_pileadd_front(&stack_a, ft_pilenew((int)tab[i]));
		i++;
	}
	ft_print_pile_and_compare(tab, stack_a, words - 1);
	stack_b = NULL;
	//stack_a = ft_pilefirst(stack_a);
	ft_swap_a(stack_a);
	ft_printf("\n ----------- \n");
	ft_print_pile_and_compare(tab, stack_a, words - 1);
	ft_pileclear(&stack_a, del);
	ft_pileclear(&stack_b, del);
}
