/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_piledelone.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscheupl <lscheupl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 21:35:18 by lscheupl          #+#    #+#             */
/*   Updated: 2024/08/12 16:51:51 by lscheupl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_piledelone(t_pile *pile, void (del)(int *))
{
	int	supr;
	//t_pile	*cache;

	supr = pile->content;
	del(&supr);
	pile -> next = NULL;
	pile -> prev = NULL;
	//cache = pile;
	free(pile);
	//cache -> next = cache;
}
