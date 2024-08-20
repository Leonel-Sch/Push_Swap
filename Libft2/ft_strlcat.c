/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscheupl <lscheupl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 18:48:48 by lscheupl          #+#    #+#             */
/*   Updated: 2024/05/28 17:46:02 by lscheupl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <bsd/string.h>

size_t	ft_strlcat(char *dst, const char *src, size_t siz)
{
	size_t	i;
	size_t	lendst;

	i = 0;
	lendst = ft_strlen(dst);
	if (lendst >= siz)
	{
		return (ft_strlen(src) + siz);
	}
	while ((lendst + i < siz - 1) && (src[i] != '\0'))
	{
		dst[lendst + i] = src[i];
		i++;
	}
	dst[lendst + i] = '\0';
	return (ft_strlen(src) + lendst);
}

//int main (void)
//{
//	char dst[] = "destination";
//	char src[] = "source";
//	size_t siz = -1;
//	printf("%zu ou %zu", ft_strlcat(dst, src, siz), strlcat(dst, src, siz));
//	return (0);
//}