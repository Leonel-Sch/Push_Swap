/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Push_Swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscheupl <lscheupl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 16:23:22 by lscheupl          #+#    #+#             */
/*   Updated: 2024/08/12 19:50:23 by lscheupl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include "Libft/libft.h"

typedef enum	e_parsing_status
{
	ERROR = -1,
	INVALID_VALUE = -1,
	VALID_VALUE
}				t_parsing_status;

typedef enum	e_writing_status
{
	writing = 1,
	do_not_write = 0,
}				t_writing_status;

typedef struct e_piles
{
	t_pile	*stack_b;
	t_pile	*stack_a;
}	t_stacks;


t_parsing_status	ft_check_values(char **tab, int words, long long *tabllong);
t_parsing_status	ft_parsing(long long *tabllong, int words, char *str);
char				*ft_make_string(char *str, int argc, char **argv);
t_parsing_status	ft_check_long_long(long long *tab, int words);
t_parsing_status	ft_isnumber(char **tab);
size_t				ft_lenarg(char **argv);
void				ft_make_pile(long long *tab, int words);
void				ft_swap_a(t_pile *stack_a, t_writing_status status);
void				ft_swap_b(t_pile *stack_b, t_writing_status status);
t_pile				*ft_pilefirst(t_pile *pile);
void				del(int *contenu);
void	ft_push_b(t_stacks *piles);
void	ft_push_a(t_stacks *piles);
void	ft_double_push(t_stacks *piles);
void	ft_rotate_a(t_stacks *piles, t_writing_status status);
void	ft_rotate_b(t_stacks *piles, t_writing_status status);
void	ft_double_rotate(t_stacks *piles);
void	ft_reverse_rotate_a(t_stacks *piles, t_writing_status status);
void	ft_reverse_rotate_b(t_stacks *piles, t_writing_status status);
void	ft_double_reverse_rotate(t_stacks *piles);





#endif