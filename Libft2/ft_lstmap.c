/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscheupl <lscheupl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 21:35:28 by lscheupl          #+#    #+#             */
/*   Updated: 2024/05/30 16:33:21 by lscheupl         ###   ########.fr       */
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

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlst;
	t_list	*new_element;

	newlst = NULL;
	while (lst != NULL)
	{
		new_element = ft_lstnew(f(lst->content));
		if (!new_element)
		{
			ft_lstclear(&newlst, del);
			return (NULL);
		}
		ft_lstadd_back(&(newlst), new_element);
		lst = lst->next;
	}
	return (newlst);
}
