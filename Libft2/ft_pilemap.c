/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pilemap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscheupl <lscheupl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 21:35:28 by lscheupl          #+#    #+#             */
/*   Updated: 2024/08/12 14:09:26 by lscheupl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
//{
//	t_list *newlst;
//	t_list *cache;

//	cache = lst;
//	if (lst == NULL)
//		return (NULL);
//	while (lst != NULL)
//	{
//		newlst = ft_lstnew(f(lst->content));
//		ft_lstadd_back((&newlst), newlst->content);
//		lst = lst->next;
//		newlst = newlst->next;
//	}
//	ft_lstclear(&cache, del);
//	newlst->next = NULL;
//	return (newlst);
//}

t_pile	*ft_pilemap(t_pile *pile, int (*f)(int), void (*del)(int *))
{
	t_pile	*newpile;
	t_pile	*new_element;

	newpile = NULL;
	while (pile != NULL)
	{
		new_element = ft_pilenew(f(pile->content));
		if (!new_element)
		{
			ft_pileclear(&newpile, del);
			return (NULL);
		}
		ft_pileadd_back(&(newpile), new_element);
		pile = pile->next;
	}
	return (pile);
}
