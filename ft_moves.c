/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capapes <capapes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 20:05:46 by capapes           #+#    #+#             */
/*   Updated: 2024/05/14 19:18:45 by capapes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_p(t_list **to, t_list **from)
{
	t_list	*aux;

	if (!*to)
	{
		*to = *from;
		*from = (*from)->next;
		(*to)->next = NULL;
		return ;
	}
	aux = *from;
	*from = (*from)->next;
	aux->next = *to;
	*to = aux;
}

void	ft_px(t_list **to, t_list **from, char x)
{
	if (x == 'a')
		ft_putstr_fd("pb\n", 1);
	if (x == 'b')
		ft_putstr_fd("pa\n", 1);
	ft_p(to, from);
}

void	ft_emptyb(t_list **stack_a, t_list **stack_b)
{
	while (*stack_b)
		ft_px(stack_a, stack_b, 'b');
}

void	ft_s(t_list **target)
{
	t_list	*aux;

	aux = (*target)->next;
	(*target)->next = aux->next;
	aux->next = *target;
	*target = aux;
	return ;
}

void	ft_sx(t_list **target, char x)
{
	if (x == 'a')
		ft_putstr_fd("sa\n", 1);
	if (x == 'b')
		ft_putstr_fd("sb\n", 1);
	ft_s(target);
}
