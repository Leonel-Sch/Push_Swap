/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pilefirst.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscheupl <lscheupl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 14:39:49 by lscheupl          #+#    #+#             */
/*   Updated: 2024/08/20 14:40:10 by lscheupl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
