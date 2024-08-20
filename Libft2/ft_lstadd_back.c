/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscheupl <lscheupl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 21:35:05 by lscheupl          #+#    #+#             */
/*   Updated: 2024/05/30 13:55:23 by lscheupl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*here;

	here = ft_lstlast(*lst);
	if (lst != NULL)
	{
		if (here != NULL)
			here->next = new;
		else
			*lst = new;
	}
	else
		*lst = new;
}
