/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Algo2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscheupl <lscheupl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 17:54:55 by lscheupl          #+#    #+#             */
/*   Updated: 2024/08/21 18:34:07 by lscheupl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_Swap.h"

void	ft_make_optimal_moove(t_stacks *piles, int mediane)
{
	int pos;
	int value;
	int i;

	pos = ft_opti_on_top_a(piles);
	while (i < pos)
	{
		piles->stack_a = piles->stack_a->next;
		i++;
	}
	value = piles->stack_b->content;
	piles->stack_a = ft_pilefirst(piles->stack_a);
	if (value < mediane)
	{
		if (pos < ft_pilesize(piles->stack_a)/2)
		{

		}
		else
		{

		}
	}
	else
	{
		if (pos < ft_pilesize(piles->stack_a)/2)
		{

		}
		else
		{
			
		}
	}
}
