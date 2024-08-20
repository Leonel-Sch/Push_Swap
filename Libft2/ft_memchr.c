/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscheupl <lscheupl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 18:32:59 by lscheupl          #+#    #+#             */
/*   Updated: 2024/05/27 22:32:59 by lscheupl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	unsigned char		cc;
	const unsigned char	*s1;

	i = 0;
	cc = (unsigned char)c;
	s1 = (const unsigned char *)s;
	if (n == 0)
		return (NULL);
	while ((s1[i] != cc) && (i < n - 1))
	{
		i++;
	}
	if (s1[i] == cc)
		return ((void *)&s[i]);
	return (NULL);
}
