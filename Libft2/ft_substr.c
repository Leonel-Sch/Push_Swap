/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscheupl <lscheupl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 08:21:49 by lscheupl          #+#    #+#             */
/*   Updated: 2024/05/28 17:46:35 by lscheupl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//size_t	ft_strlen(const char *str)
//{
//	int i;

//	i = 0;
//	while (str[i])
//		i++;
//	return (i);
//}
char	*ft_exception(char *sub)
{
	sub = (char *)malloc((sizeof(char)) * 1);
	if (!sub)
		return (NULL);
	sub[0] = '\0';
	return (sub);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	int		cache;
	int		i;
	char	*sub;

	cache = start;
	i = 0;
	sub = NULL;
	if (start >= ft_strlen(s))
		return (ft_exception(sub));
	if (ft_strlen(s) - start < len)
		sub = (char *)malloc((sizeof(char)) * ft_strlen(s) - start + 1);
	else
	{
		if (ft_strlen(s) < len)
			sub = (char *)malloc((sizeof(char)) * ft_strlen(s) + 1);
		else
			sub = (char *)malloc((sizeof(char)) * len + 1);
	}
	if (!sub)
		return (NULL);
	while ((start < len + cache) && (s[start]))
		sub[i++] = s[start++];
	sub[i] = '\0';
	return (sub);
}
//int	main(void)
//{
//	char string[] = "yeslife"; //7
//	int size = 10;
//	printf("mine : %zu\n", ft_strlen(ft_substr(string, 10, size)));
//	return (0);
//}
