/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Push_Swap_Utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscheupl <lscheupl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 20:02:19 by lscheupl          #+#    #+#             */
/*   Updated: 2024/08/28 16:03:09 by lscheupl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_Swap.h"

size_t	ft_lenarg(char **argv)
{
	long long	characters;
	int			i;

	i = 0;
	characters = 0;
	while (argv[i])
	{
		characters += ft_strlen(argv[i]) + 1;
		i++;
	}
	return (characters);
}
