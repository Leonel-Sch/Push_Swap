/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Push_Swap_Pile.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leonel <leonel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 17:00:24 by lscheupl          #+#    #+#             */
/*   Updated: 2024/08/15 19:11:31 by leonel           ###   ########.fr       */
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

void	ft_ll_to_int(long long *src, int *dest, int nb_value)
{
	int i;

	i = 0;
	while (i < nb_value)
	{
		dest[i] = (int)src[i];
		i++;
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
	i = 1;
	ft_sort_tab(&tab, words);
	int *tabint;

	tabint = NULL;
	tabint = malloc((sizeof (int)) * words + 1);
	if (!tabint)
		return;
	ft_ll_to_int(tab, tabint, words);
	piles.stack_a = ft_pilefirst(piles.stack_a);
	ft_sort_piles(&piles, tabint);
	free(tab);
	free(tabint);
	piles.stack_a = ft_pilefirst(piles.stack_a);
	ft_pileclear(&piles.stack_a, del);
	//ft_pileclear(&piles.stack_b, del);
}
