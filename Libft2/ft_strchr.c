/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscheupl <lscheupl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 17:55:05 by lscheupl          #+#    #+#             */
/*   Updated: 2024/05/28 17:46:20 by lscheupl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//#include <stdio.h>

char	*ft_strchr(const char *s, int c)
{
	int				i;
	unsigned char	cc;

	i = 0;
	cc = (unsigned char)c;
	while (s[i] != cc && s[i])
		i++;
	if (s[i] == cc)
		return ((char *)&s[i]);
	return (NULL);
}

// int main (void)
//{
//	char s[] = "lalala";
//	int c = 97;
//	printf("%s", ft_strchr(s, c));
//	return (0);
//}