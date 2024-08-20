/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_dependancy.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscheupl <lscheupl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 10:47:04 by lscheupl          #+#    #+#             */
/*   Updated: 2024/08/03 17:47:26 by lscheupl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"


void	ft_putstr_f(char *s, int *count)
{
	int	i;

	i = 0;
	if (s == NULL)
	{
		ft_putstr_f("(null)", count);
		return ;
	}
	while (s[i])
	{
		ft_putchar_nb(s[i], count);
		i++;
	}
}

void	ft_putnbr_base_f(long long nb, char *base, int *count)
{
	int	len;

	len = ft_strlen(base);
	if (nb < 0)
	{
		nb = -nb;
		ft_putchar_nb('-', count);
	}
	if (nb >= len)
	{
		ft_putnbr_base_f(nb / ft_strlen(base), base, count);
		ft_putchar_nb(base[nb % ft_strlen(base)], count);
	}
	if (nb < len)
	{
		ft_putchar_nb(base[nb], count);
	}
}

void	ft_putnbr_base_ul(unsigned long long nb, char *base, int *count)
{
	if (nb >= ft_strlen(base))
	{
		ft_putnbr_base_ul(nb / ft_strlen(base), base, count);
		ft_putchar_nb(base[nb % ft_strlen(base)], count);
		//"0123456789ABCDEF" 
	}
	if (nb < ft_strlen(base))
	{
		ft_putchar_nb(base[nb], count);
	}
}

void	ft_pointer(unsigned long long nb, int *count)
{
	if (!nb)
	{
		ft_putstr_f("(nil)", count);
		return ;
	}
	else
	{
		ft_putstr_f("0x", count);
		ft_putnbr_base_ul(nb, HEXAL, count);
	}
}
