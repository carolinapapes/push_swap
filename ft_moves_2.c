/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capapes <capapes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 19:17:42 by capapes           #+#    #+#             */
/*   Updated: 2024/05/14 19:18:49 by capapes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	return ;
}

void	ft_rx(t_list **target, char x)
{
	if (x == 'a')
		ft_putstr_fd("ra\n", 1);
	if (x == 'b')
		ft_putstr_fd("rb\n", 1);
	ft_r(target);
	return ;
}

void	ft_rr(t_list **target)
{
	t_list	*aux;
	t_list	*second;

	if (*target == NULL || (*target)->next == NULL)
		return ;
	second = *target;
	aux = *target;
	while (aux->next->next != NULL)
		aux = aux->next;
	*target = aux->next;
	aux->next = NULL;
	(*target)->next = second;
	return ;
}

void	ft_rrx(t_list **target, char x)
{
	if (x == 'a')
		ft_putstr_fd("rra\n", 1);
	if (x == 'b')
		ft_putstr_fd("rrb\n", 1);
	ft_rr(target);
}
