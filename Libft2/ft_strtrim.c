/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscheupl <lscheupl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 16:12:03 by lscheupl          #+#    #+#             */
/*   Updated: 2024/05/28 17:46:47 by lscheupl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

static int	ft_start(const char *s1, const char *set)
{
	int	i;
	int	lens1;

	i = 0;
	lens1 = ft_strlen(s1);
	while (i < lens1 && (ft_strchr(set, s1[i]) != NULL))
		i++;
	return (i);
}

static int	ft_end(const char *s1, const char *set)
{
	int	i;
	int	lens1;

	lens1 = ft_strlen(s1);
	i = lens1;
	while (i > 0 && (ft_strrchr(set, s1[i]) != NULL))
		i--;
	return (i);
}

char	*ft_bad(char *trimmed)
{
	trimmed = (char *)malloc((sizeof(char)) * 1);
	if (!trimmed)
		return (NULL);
	trimmed[0] = '\0';
	return (trimmed);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	int		i;
	char	*trimmed;

	start = ft_start(s1, set);
	end = ft_end(s1, set);
	i = 0;
	trimmed = NULL;
	if ((start > end) || (s1[i] == '\0'))
		return (ft_bad(trimmed));
	trimmed = (char *)malloc(sizeof(char) * end - start + 2);
	if (!trimmed)
		return (NULL);
	while (i < end - start + 1)
	{
		trimmed[i] = s1[i + start];
		i++;
	}
	trimmed[i] = '\0';
	return (trimmed);
}

// int	main(int argc, char **argv)
//{
//	if (argc > 3)
//		return (0);
//	printf(" source = %s\ntrimmed = %s\n", argv[1], ft_strtrim(argv[1],
//			argv[2]));
//	printf("%d\n", strcmp(argv[1], ft_strtrim(argv[1], argv[2])));
//	return (0);
//}
