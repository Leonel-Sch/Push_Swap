/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscheupl <lscheupl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 21:35:15 by lscheupl          #+#    #+#             */
/*   Updated: 2024/05/30 14:39:14 by lscheupl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	int		i;
	t_list	*cache;

	i = ft_lstsize(*lst);
	if (lst == NULL || del == NULL)
		return ;
	while (i > 0)
	{
		cache = *lst;
		*lst = (*lst)->next;
		ft_lstdelone(cache, del);
		i--;
	}
	lst = NULL;
}
