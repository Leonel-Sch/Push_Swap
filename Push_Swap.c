/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Push_Swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscheupl <lscheupl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 16:19:49 by lscheupl          #+#    #+#             */
/*   Updated: 2024/08/07 16:50:54 by lscheupl         ###   ########.fr       */
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
	int		i;

	i = words - 2;
	stack_a = ft_pilenew((int)tab[i + 1]);
	while (i >= 0)
	{
		ft_pileadd_back(&stack_a, ft_pilenew((int)tab[i]));
		i--;
	}
	// contenu = stackA->content;
	ft_print_pile_and_compare(tab, stack_a, words - 1);
}

t_parsing_status	ft_push_swap(int argc, char **argv)
{
	long long	*tabllong;
	int			words;
	char		*str;

	str = NULL;
	str = ft_make_string(str, argc, argv);
	words = ft_count_words(str, 32);
	tabllong = NULL;
	tabllong = (long long *)malloc((sizeof(long long) * words) + 1);
	if (!tabllong)
		return (free(tabllong), 0);
	if (ft_parsing(tabllong, words, str) == INVALID_VALUE)
		return (free(tabllong), INVALID_VALUE);
	// int i;
	// i = 0;
	// while (i < words)
	//{
	//	printf("%lld\n", tabllong[i]);
	//	i++;
	//}
	ft_make_pile(tabllong, words);
	return (free(str), free(tabllong), VALID_VALUE);
}

int	main(int argc, char **argv)
{
	if (argc <= 1)
		return (ft_printf("Error"), 0);
	if (ft_push_swap(argc, argv) == INVALID_VALUE)
		return (ft_printf("Error"), 0);
}
