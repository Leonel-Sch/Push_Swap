/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscheupl <lscheupl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 18:05:12 by lscheupl          #+#    #+#             */
/*   Updated: 2024/05/23 19:28:15 by lscheupl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*ft_revcpy(void *dest, const void *src, size_t n)
{
	while (n > 0)
	{
		((char *)dest)[n -1] = ((char *)src)[n - 1];
		n--;
	}
	return (dest);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	if (dest > src)
		dest = ft_revcpy(dest, src, n);
	else
		dest = ft_memcpy(dest, src, n);
	return (dest);
}
