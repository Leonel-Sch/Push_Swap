/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscheupl <lscheupl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 17:17:49 by lscheupl          #+#    #+#             */
/*   Updated: 2024/08/03 18:01:01 by lscheupl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_base_fd(long long nb, char *base, int fd)
{
	int	len;

	len = ft_strlen(base);
	if (nb < 0)
	{
		nb = -nb;
		ft_putchar_fd('-', fd);
	}
	if (nb >= len)
	{
		ft_putnbr_base_fd(nb / ft_strlen(base), base, fd);
		ft_putchar_fd(base[nb % ft_strlen(base)], fd);
	}
	if (nb < len)
	{
		ft_putchar_fd(base[nb], fd);
	}
}

//int	main(int argc, char **argv)
//{
//	if (argc > 3)
//		return (0);
//	ft_putnbr_base_fd(ft_atoi(argv[1]), argv[2], 1);
//	return (0);
//}