/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscheupl <lscheupl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 19:16:19 by lscheupl          #+#    #+#             */
/*   Updated: 2024/08/30 16:50:33 by lscheupl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_nb(char c, int *count)
{
	write(1, &c, 1);
	*count += 1;
}

int	ft_dependance(const char *format, va_list ap, int *count, int i)
{
	if (format[i] == '%' && format[i + 1] == 'c')
		return (ft_putchar_nb(va_arg(ap, int), count), 1);
	else if (format[i] == '%' && format[i + 1] == 's')
		return (ft_putstr_f(va_arg(ap, char *), count), 1);
	else if (format[i] == '%' && format[i + 1] == 'p')
		return (ft_pointer(va_arg(ap, UL), count), 1);
	else if (format[i] == '%' && format[i + 1] == 'd')
		return (ft_putnbr_base_f(va_arg(ap, int), B10, count), 1);
	else if (format[i] == '%' && format[i + 1] == 'i')
		return (ft_putnbr_base_f(va_arg(ap, int), B10, count), 1);
	else if (format[i] == '%' && format[i + 1] == 'u')
		return (ft_putnbr_base_f(va_arg(ap, unsigned int), B10, count), 1);
	else if (format[i] == '%' && format[i + 1] == 'x')
		return (ft_putnbr_base_f(va_arg(ap, unsigned int), HEXAL, count), 1);
	else if (format[i] == '%' && format[i + 1] == 'X')
		return (ft_putnbr_base_f(va_arg(ap, unsigned int), HEXAU, count), 1);
	else if (format[i] == '%' && format[i + 1] == '%')
		return (ft_putchar_nb('%', count), 1);
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		count;
	int		i;

	count = 0;
	i = 0;
	va_start(ap, format);
	if (!format)
		return (-1);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			if (ft_dependance(format, ap, &count, i) != 0)
				i++;
		}
		else
			ft_putchar_nb(format[i], &count);
		i++;
	}
	va_end(ap);
	return (count);
}
