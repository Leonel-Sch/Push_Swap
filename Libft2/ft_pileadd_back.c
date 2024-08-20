/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pileadd_back.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscheupl <lscheupl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 21:35:05 by lscheupl          #+#    #+#             */
/*   Updated: 2024/08/07 13:32:12 by lscheupl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_pileadd_back(t_pile **pile, t_pile *new)
{
	t_pile	*here;

	here = ft_pilelast(*pile);
	if (pile != NULL)
	{
		if (here != NULL)
		{
			here->next = new;
			new->prev = here;
			new->next = NULL;
		}
		else
			*pile = new;
	}
	else
		*pile = new;
}
