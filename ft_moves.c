/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capapes <capapes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 20:05:46 by capapes           #+#    #+#             */
/*   Updated: 2024/05/13 18:31:56 by capapes          ###   ########.fr       */
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
	if (x == 'a' || x == 'l')
		ft_putstr_fd("pb\n", 1);
	if (x == 'b')
		ft_putstr_fd("pa\n", 1);
	ft_p(from, to);
}

void	ft_pb(t_list **from, t_list **to)
{
	ft_putstr_fd("pb\n", 1);
	ft_p(to, from);
}


void	ft_pa(t_list **to, t_list **from)
{
	ft_putstr_fd("pa\n", 1);
	ft_p(to, from);
}



void	ft_rx(t_list **target, char x)
{
	t_list	*aux;

	if (*target == NULL || (*target)->next == NULL)
		return ;
	aux = *target;
	while (aux->next != NULL)
		aux = aux->next;
	aux->next = (*target);
	*target = (*target)->next;
	aux->next->next = NULL;
	if (x == 'a' || x == 'l')
		ft_putstr_fd("ra\n", 1);
	if (x == 'b')
		ft_putstr_fd("rb\n", 1);
	return ;
}

void	ft_r(t_list **target)
{
	t_list	*aux;

	if (*target == NULL || (*target)->next == NULL)
		return ;
	aux = *target;
	while (aux->next != NULL)
		aux = aux->next;
	aux->next = (*target);
	*target = (*target)->next;
	aux->next->next = NULL;
	ft_putstr_fd("ra\n", 1);
	return ;
}


