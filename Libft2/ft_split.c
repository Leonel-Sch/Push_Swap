/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscheupl <lscheupl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 13:23:45 by lscheupl          #+#    #+#             */
/*   Updated: 2024/08/07 11:07:29 by lscheupl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

//static char	**ft_xav(char **tab, int i)
//{
//	int	j;

//	j = 0;
//	i = 2;
//	while (tab[j] != NULL)
//	{
//		free(tab[j]);
//		tab[j] = NULL;
//		j++;
//	}
//	free(tab);
//	return (NULL);
//}

//static int	ft_count_words(const char *s, char c)
//{
//	int	count;
//	int	i;

//	i = 0;
//	count = 0;
//	while (s[i])
//	{
//		if (s[i] != c)
//		{
//			count++;
//			while (s[i] != c || s[i] == '\0')
//			{
//				if (s[i] == '\0')
//					return (count);
//				i++;
//			}
//		}
//		i++;
//	}
//	return (count);
//}

static char	**ft_dependancy(char **tab, const char *s, char c, int i)
{
	int	k;
	int	j;
	int	sizewords;

	j = 0;
	sizewords = 0;
	while (i <= ft_count_words(s, c) - 1)
	{
		k = 0;
		while (s[j] == c)
			j++;
		while ((s[j] != c) && (s[j]))
		{
			j++;
			sizewords++;
		}
		tab[i] = (char *)malloc(sizeof(char) * sizewords + 1);
		if (!tab[i])
			return (ft_free_tab(tab, i));
		while (0 < sizewords)
			tab[i][k++] = s[j - sizewords--];
		tab[i++][k] = '\0';
	}
	tab[i] = NULL;
	return (tab);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		i;

	i = 0;
	tab = (char **)malloc(sizeof(char *) * (ft_count_words(s, c) + 1));
	if (!tab)
		return (NULL);
	return (ft_dependancy(tab, s, c, i));
}

// int	main(void)
//{
//	int		i;
//	char	**tab;

//	i = 0;
//	tab = ft_split("hello!", 32);
//	while (i <= 1)
//	{
//		printf("%s\n", tab[i]);
//		i++;
//	}
//	//printf("%d", ft_count_words("Tripouille", ' '));
//	return (0);
//}
