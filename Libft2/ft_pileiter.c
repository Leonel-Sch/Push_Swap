/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pileiter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscheupl <lscheupl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 21:35:21 by lscheupl          #+#    #+#             */
/*   Updated: 2024/08/07 15:32:34 by lscheupl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_pileiter(t_pile *pile, void (*f)(int))
{
	while (pile != NULL)
	{
		f(pile->content);
		pile = pile->next;
	}
}
