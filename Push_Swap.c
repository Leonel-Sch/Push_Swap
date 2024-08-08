/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Push_Swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscheupl <lscheupl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 16:19:49 by lscheupl          #+#    #+#             */
/*   Updated: 2024/08/08 17:05:14 by lscheupl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_Swap.h"

t_parsing_status	ft_push_swap(int argc, char **argv)
{
	long long	*tabllong;
	int			words;
	char		*str;

	str = NULL;
	str = ft_make_string(str, argc, argv);
	words = ft_count_words(str, 32);
	tabllong = NULL;
	tabllong = (long long *)malloc((sizeof(long long) * words) + 1);
	if (!tabllong)
		return (free(tabllong), 0);
	if (ft_parsing(tabllong, words, str) == INVALID_VALUE)
		return (free(tabllong), INVALID_VALUE);
	ft_make_pile(tabllong, words);
	return (free(str), free(tabllong), VALID_VALUE);
}

int	main(int argc, char **argv)
{
	if (argc <= 1)
		return (ft_printf("Error"), 0);
	if (ft_push_swap(argc, argv) == INVALID_VALUE)
		return (ft_printf("Error\n"), 0);
}
