/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capapes <capapes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 20:05:46 by capapes           #+#    #+#             */
/*   Updated: 2024/05/09 15:46:11 by capapes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_p(t_list **to, t_list **from)
{
	t_list	*aux;

	aux = *from;
	*from = (*from)->next;
	aux->next = *to;
	*to = aux;
}

void	ft_pa(t_list **to, t_list **from)
{
	ft_putstr_fd("pa\n", 1);
	ft_p(to, from);
}

void	ft_pb(t_list **from, t_list **to)
{
	ft_putstr_fd("pb\n", 1);
	ft_p(to, from);
}

void	ft_r(t_list **target)
{
	t_list	*aux;
	t_list	*aux2;

	if (*target == NULL)
		return ;
	aux = *target;
	while (aux->next != NULL)
		aux = aux->next;
	aux2 = *target;
	while (aux2->next != NULL && aux2->next->next != NULL)
		aux2 = aux2->next;
	aux->next = (*target)->next;
	aux2->next = (*target);
	aux2->next->next = NULL;
	*target = aux;
	return ;
}
