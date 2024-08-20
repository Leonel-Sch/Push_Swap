/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscheupl <lscheupl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 19:50:36 by lscheupl          #+#    #+#             */
/*   Updated: 2024/05/28 16:30:02 by lscheupl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>

//int	ft_strncmp(const char *s1, const char *s2, size_t n)
//{
//	size_t	i;
//	unsigned char *s22;
//	unsigned char *s11;

//	s11 = (unsigned char *)s1;
//	s22 = (unsigned char *)s2;
//	i = 0;
//	if (n == 0)
//		return (0);
//	while ((s1[i] == s2[i]) && (s1[i] != '\0') && (s2[i] != '\0') && (i < n
//			- 1))
//	{
//		i++;
//	}
//	return ((s11[i] - s22[i]));
//}

//size_t	ft_strlen(const char *str)
//{
//	int i;

//	i = 0;
//	while (str[i])
//		i++;
//	return (i);
//}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	cache;

	i = 0;
	if (little[0] == '\0')
		return ((char *)big);
	while ((big[i]) && (i < len))
	{
		j = 0;
		if (big[i] == little[j])
		{
			cache = i;
			while ((big[i] == little[j]) && (big[i]) && (i < len))
			{
				j++;
				i++;
			}
			if (j == ft_strlen(little))
				return ((char *)&big[cache]);
			i = cache;
		}
		i++;
	}
	return (NULL);
}

//int	main(int argc, char **argv)
//{
//	char	*big;
//	char	*little;
//	int		n;

//	little = argv[1];
//	big = argv[2];
//	n = atoi(argv[3]);
//	printf("%s", ft_strnstr(big, little, n));
//	return (0);
//}
