/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Push_Swap_Pile.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscheupl <lscheupl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 17:00:24 by lscheupl          #+#    #+#             */
/*   Updated: 2024/08/28 17:51:47 by lscheupl         ###   ########.fr       */
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
	char	*check;

	check = NULL;
	check = malloc(size * sizeof(char));
	if (!check)
		return ;
	i = 0;
	j = 0;
	while (i < size)
	{
		check[i] = '0';
		i++;
	}
	check[i] = '\0';
	i = 0;
	while (i < size)
	{
		j = 0;
		while (tab_sorted[i] != tab_ori[j] && j < size)
		{
			j++;
			if (tab_sorted[i] == tab_ori[j] && check[j] == '1' && j < size - 1)
				j++;
		}
		if (tab_sorted[i] == tab_ori[j] && check[j] == '0')
		{
			tab_ori[j] = i;
			check[j] = '1';
		}
		i++;
	}
	free(check);
}

void	ft_make_pile(long long *tab, int words)
{
	t_stacks	piles;
	int			i;
	int			*tabint_ori;
	int			*tabint;

	i = 0;
	tabint_ori = NULL;
	tabint_ori = malloc((sizeof(int)) * words + 1);
	if (!tabint_ori)
		return ;
	ft_ll_to_int(tab, tabint_ori, words);
	ft_sort_tab(&tab, words);
	tabint = NULL;
	tabint = malloc((sizeof(int)) * words + 1);
	if (!tabint)
		return ;
	ft_ll_to_int(tab, tabint, words);
	ft_no_negative(tabint, tabint_ori, words);
	piles.stack_a = ft_pilenew(tabint_ori[i]);
	i++;
	while (i < words)
	{
		ft_pileadd_back(&piles.stack_a, ft_pilenew(tabint_ori[i]));
		i++;
	}
	piles.stack_b = NULL;
	ft_sort_piles(&piles, tabint, tabint_ori, words);
	//ft_print_pile(piles.stack_a);
	free(tab);
	free(tabint_ori);
	piles.stack_a = ft_pilefirst(piles.stack_a);
	ft_pileclear(&piles.stack_a, del);
}
