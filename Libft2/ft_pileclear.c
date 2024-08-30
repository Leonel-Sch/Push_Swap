/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pileclear.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscheupl <lscheupl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 21:35:15 by lscheupl          #+#    #+#             */
/*   Updated: 2024/08/30 17:15:52 by lscheupl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_pileclear(t_pile **pile, void (*del)(int *))
{
	int		i;
	t_pile	*cache;

	i = ft_pilesize(*pile);
	if (pile == NULL || del == NULL)
		return ;
	while (i > 0)
	{
		cache = *pile;
		*pile = (*pile)->next;
		ft_piledelone(cache, del);
		i--;
	}
	pile = NULL;
}
