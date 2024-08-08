/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Push_Swap_Command.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscheupl <lscheupl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 17:07:29 by lscheupl          #+#    #+#             */
/*   Updated: 2024/08/08 18:05:49 by lscheupl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Push_Swap.h"

// sa (swap a) : Intervertit les 2 premiers éléments au sommet de la pile a.
// Ne fait rien s’il n’y en a qu’un ou aucun.

void	ft_swap_a(t_pile *stack_a)
{
	int	swap;

	if (stack_a != NULL && stack_a->next != NULL)
	{
		swap = stack_a->content;
		stack_a = stack_a->next;
		stack_a->prev->content = stack_a->content;
		stack_a->content = swap;
	}
}

// sb (swap b ) : Intervertit les 2 premiers éléments au sommet de la pile b.
// Ne fait rien s’il n’y en a qu’un ou aucun.

void	ft_swap_b(t_pile *stack_b)
{
	int	swap;

	if (stack_b != NULL && stack_b->next != NULL)
	{
		swap = stack_b->content;
		stack_b = stack_b->next;
		stack_b->prev->content = stack_b->content;
		stack_b->content = swap;
	}
}

// ss : sa et sb en même temps.

void	ft_double_swap(t_pile *stack_a, t_pile *stack_b)
{
	ft_swap_a(stack_a);
	ft_swap_b(stack_b);
}

// pa (push a) : Prend le premier élément au sommet de b et le met sur a.
// Ne fait rien si b est vide.

void	ft_push_a(t_pile *stack_a, t_pile *stack_b)
{
	if (stack_b != NULL)
	{
		ft_pilefirst(stack_b);
		ft_pileadd_front(&stack_a, stack_b);
		ft_piledelone(stack_b, del);
	}
}

void	del(int contenu)
{
	contenu = 0;
}

// pb (push b) : Prend le premier élément au sommet de a et le met sur b.
// Ne fait rien si a est vide.

void	ft_push_a(t_pile *stack_a, t_pile *stack_b)
{
	if (stack_a != NULL)
	{
		ft_pilefirst(stack_a);
		ft_pileadd_front(&stack_b, stack_a);
		ft_piledelone(stack_a, del);
	}
}

// ra (rotate a) : Décale d’une position vers le haut tous les élements de la pile a.
// Le premier élément devient le dernier.

// rb (rotate b) : Décale d’une position vers le haut tous les élements de la pile b.
// Le premier élément devient le dernier.

// rr : ra et rb en même temps.

// rra (reverse rotate a) : Décale d’une position vers le bas tous les élements de
// la pile a. Le dernier élément devient le premier.

// rrb (reverse rotate b) : Décale d’une position vers le bas tous les élements de
// la pile b. Le dernier élément devient le premier.

// rrr : rra et rrb en même temps.
