/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscheupl <lscheupl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 20:15:12 by lscheupl          #+#    #+#             */
/*   Updated: 2024/08/06 20:15:50 by lscheupl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_free_tab(char **tab, int i)
{
	int	j;

	j = 0;
	i = 2;
	while (tab[j] != NULL)
	{
		free(tab[j]);
		tab[j] = NULL;
		j++;
	}
	free(tab);
	return (NULL);
}
