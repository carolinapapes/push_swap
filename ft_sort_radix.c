/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_radixsort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capapes <capapes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 19:52:03 by capapes           #+#    #+#             */
/*   Updated: 2024/05/15 15:21:00 by capapes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_get_bits_len(int nbr)
{
	int	digits;

	digits = 0;
	while (nbr && ++digits)
		nbr = nbr >> 1;
	return (digits);
}

int	ft_map_b(t_list **b, t_list **a, int len, int i)
{
	int	newlen;
	int	content;

	newlen = 0;
	len++;
	while (--len)
	{
		content = ft_get_content(*b);
		if (content >> i & 1 && ++newlen)
			ft_px(a, b, 'b');
		else
			ft_rx(b, 'b');
	}
	return (newlen);
}

int	ft_map_a(t_list **a, t_list **b, int len, int i)
{
	int	newlen;
	int	content;

	newlen = 0;
	len++;
	while (--len)
	{
		if (ft_is_sorted(*a, len))
			break ;
		content = ft_get_content(*a);
		if (!(content >> i & 1) && ++newlen)
			ft_px(b, a, 'a');
		else
			ft_rx(a, 'a');
	}
	return (newlen);
}

void	ft_radix_sort(t_list **stack_a, t_list **stack_b, int len)
{
	int	a_len;
	int	digits;
	int	i;

	if (!len)
		return ;
	a_len = len;
	digits = ft_get_bits_len(len - 1);
	i = -1;
	while (++i < digits)
	{
		a_len -= ft_map_a(stack_a, stack_b, a_len, i);
		if ((i + 1) < digits)
			a_len += ft_map_b(stack_b, stack_a, (len - a_len), i + 1);
	}
	ft_emptyb(stack_a, stack_b);
}
