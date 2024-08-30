/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoll.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscheupl <lscheupl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 15:46:56 by lscheupl          #+#    #+#             */
/*   Updated: 2024/08/30 16:51:50 by lscheupl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long	ft_atoll(const char *nptr)
{
	long long	sum;
	long long	sign;
	int			i;

	sign = 1;
	sum = 0;
	i = 0;
	while (nptr[i] == '\t' || nptr[i] == '\n' || nptr[i] == '\r'
		|| nptr[i] == '\v' || nptr[i] == '\f' || nptr[i] == ' ')
		i++;
	if (nptr[i] == '-')
	{
		sign = -sign;
		i++;
	}
	else if (nptr[i] == '+')
		i++;
	while (nptr[i] >= 48 && nptr[i] <= 57)
	{
		sum = sum * 10 + (nptr[i] - 48);
		i++;
	}
	return (sum * sign);
}
// int main()
//{
//	printf("%lld\n", ft_atoll("21474836564550"));
//	return (0);
//}