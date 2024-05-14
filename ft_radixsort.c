/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_radixsort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capapes <capapes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 19:52:03 by capapes           #+#    #+#             */
/*   Updated: 2024/05/14 19:16:35 by capapes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_getbitslen(int nbr)
{
	int	digits;

	digits = 0;
	while (nbr)
	{
		nbr = nbr >> 1;
		digits++;
	}
	return (digits);
}

int	ft_issorted(t_list *i, int len)
{
	t_list	*j;
	int		k;

	k = -1;
	while (i != NULL && ++k < len)
	{
		j = i -> next;
		while (j != NULL)
		{
			if (((int *)(i->content))[1] > (((int *)(j->content))[1]))
				return (0);
			j = j -> next;
		}
		i = i -> next;
	}
	return (1);
}

int	ft_map_b(t_list **b, t_list **a, int len, int i)
{
	int	newlen;
	int	content;

	newlen = 0;
	len++;
	while (--len)
	{
		content = ((int *)(*b)->content)[1];
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
		content = ((int *)(*a)->content)[1];
		if (!(content >> i & 1))
		{
			if (ft_issorted(*a, len))
				break ;
			newlen++;
			ft_px(b, a, 'a');
		}
		else
			ft_rx(a, 'a');
	}
	return (newlen);
}

void	ft_sortidx(t_list **stack_a, t_list **stack_b, int len)
{
	int	i;
	int	digits;
	int	b_len;
	int	a_len;
	int	moves;

	if (!len)
		return ;
	i = -1;
	digits = ft_getbitslen(len - 1);
	b_len = 0;
	a_len = len;
	while (++i < digits)
	{
		moves = ft_map_a(stack_a, stack_b, a_len, i);
		b_len += moves;
		a_len -= moves;
		if ((i + 1) < digits)
		{
			moves = ft_map_b(stack_b, stack_a, b_len, i + 1);
			b_len -= moves;
			a_len += moves;
		}
	}
	ft_emptyb(stack_a, stack_b);
}
