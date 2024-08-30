/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Push_Swap_Pile.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscheupl <lscheupl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 17:00:24 by lscheupl          #+#    #+#             */
/*   Updated: 2024/08/30 18:47:32 by lscheupl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_Swap.h"

void	ft_print_pile(t_pile *stack)
{
	t_pile	*cache;
	int		i;

	i = 0;
	cache = ft_pilefirst(stack);
	if (cache == NULL)
		ft_printf("Nothing to print\n");
	while (cache != NULL)
	{
		ft_printf("n°%d : %d\n", i, cache->content);
		cache = cache->next;
		i++;
	}
}

void	ft_ll_to_int(long long *src, int *dest, int nb_value)
{
	int	i;

	i = 0;
	while (i < nb_value)
	{
		dest[i] = (int)src[i];
		i++;
	}
}

void	ft_no_negative(int *tab_sorted, int *tab_ori, int size)
{
	long	i;
	long	j;
	int		check;

	i = 0;
	j = 0;
	while (i < size)
	{
		j = 0;
		check = 0;
		while (j < size && check == 0)
		{
			if (tab_ori[i] == tab_sorted[j])
			{
				tab_ori[i] = j;
				check = 1;
			}
			j++;
		}
		i++;
	}
}

void	ft_free_everything(int *tab1, long long *tab2, int *tab3,
		t_stacks *piles)
{
	free(tab1);
	free(tab2);
	free(tab3);
	piles->stack_a = ft_pilefirst(piles->stack_a);
	ft_pileclear(&piles->stack_a, del);
}

void	ft_make_pile(long long *tab, int words)
{
	t_stacks	piles;
	int			i;
	int			*tabint_ori;
	int			*tabint;

	i = 1;
	tabint_ori = malloc((sizeof(int)) * words + 1);
	if (!tabint_ori)
		return (free(tab));
	ft_ll_to_int(tab, tabint_ori, words);
	ft_sort_tab(&tab, words);
	tabint = malloc((sizeof(int)) * words + 1);
	if (!tabint)
		return (free(tab), free(tabint_ori));
	ft_ll_to_int(tab, tabint, words);
	ft_no_negative(tabint, tabint_ori, words);
	piles.stack_a = ft_pilenew(tabint_ori[0]);
	while (i < words)
		ft_pileadd_back(&piles.stack_a, ft_pilenew(tabint_ori[i++]));
	if (ft_check_sorting(&piles) == 0)
		ft_sort_piles(&piles, tabint, tabint_ori, words);
	ft_free_everything(tabint, tab, tabint_ori, &piles);
}
