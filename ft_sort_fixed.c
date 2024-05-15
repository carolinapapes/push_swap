/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_fixed.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capapes <capapes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 15:27:29 by capapes           #+#    #+#             */
/*   Updated: 2024/05/15 15:41:34 by capapes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort3(t_list **a)
{
	int	first;
	int	second;
	int	third;

	while (!ft_is_sorted(*a, 4))
	{
		first = ((int *)((*a)->content))[1];
		second = ((int *)((*a)->next->content))[1];
		third = ((int *)((*a)->next->next->content))[1];
		if ((first < second && first < third)
			|| (first < second && first > third))
			ft_rrx(a, 'a');
		if (first > second && first < third)
			ft_sx(a, 'a');
		if (first > second && first > third)
			ft_rx(a, 'a');
	}
	return ;
}

void	ft_move_till_three(t_list **a, t_list **b, int len)
{
	int	last;
	int	first;

	while (len > 3)
	{
		first = ((int *)((*a)->content))[1];
		last = ((int *)((ft_lstlast(*a))->content))[1];
		if (first == 0 || first == 1)
		{
			ft_px(b, a, 'a');
			len--;
		}
		if (last == 0 || last == 1)
		{
			ft_rrx(a, 'a');
			ft_px(b, a, 'a');
			len--;
		}
		if (len > 3)
			ft_rx(a, 'a');
	}
}

void	ft_sort5(t_list **a, t_list **b, int len)
{
	int	first;
	int	b_node;

	ft_move_till_three(a, b, len);
	ft_sort3(a);
	ft_px(a, b, 'b');
	b_node = ((int *)((*b)->content))[1];
	first = ((int *)((*a)->content))[1];
	if (b_node < first)
		ft_px(a, b, 'b');
	else
	{
		ft_px(a, b, 'b');
		ft_sx(a, 'a');
	}
	return ;
}