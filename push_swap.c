/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capapes <capapes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 14:43:17 by capapes           #+#    #+#             */
/*   Updated: 2024/05/13 17:46:54 by capapes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
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

void	ft_emptyb(t_list **stack_a, t_list **stack_b)
{
	while (*stack_b)
		ft_pa(stack_a, stack_b);
}

void	ft_mapa(t_list **stack_a, t_list **stack_b, int len, int i)
{
	len++;
	while (--len)
	{
		if (!(((int *)(*stack_a)->content)[1] >> i & 1))
			ft_pb(stack_a, stack_b);
		else
			ft_r(stack_a);
	}
}

void	ft_sortidx(t_list **stack_a, t_list **stack_b, int len)
{
	int	i;
	int	digits;

	if (!len)
		return ;
	i = -1;
	digits = ft_getbitslen(len - 1);
	while (++i < digits)
	{
		ft_mapa(stack_a, stack_b, len, i);
		ft_emptyb(stack_a, stack_b);
	}
}

// int	ft_issorted(t_list *i, int len)
// {
// 	t_list	*j;

// 	while (*i)
// 	{
		
// 	}
	
// }

int	ft_mapa_modify(t_list **from, t_list **to, int len, int i, char stack)
{
	int	newlen;
	int	content;

	newlen = 0;
	len++;
	while (--len)
	{
		content = ((int *)(*from)->content)[1];
		if ((stack == 'a' && !(content >> i & 1))
			|| (stack == 'b' && (content >> i & 1)))
		{
			newlen++;
			ft_px(from, to, stack);
		}
		// if(stack == 'l' && !(content >> i & 1))
		// {
		// 	newlen++;
		// 	if(ft_issorted(from, len -1))
		// 		break;
		// 	ft_px(from, to, stack);
		// }
		else
			ft_rx(from, stack);
	}
	return (newlen);
}

void	ft_printlist(void *content)
{
	ft_putnbr_fd(((int *)content)[0], 1);
	ft_putstr_fd("\n", 1);
}

void	ft_sortidx_modify(t_list **stack_a, t_list **stack_b, int len)
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
		// ft_putstr_fd("\n### ITERATION: ", 1);
		// ft_putnbr_fd(i, 1);
		// ft_putstr_fd("stack a:\n", 1);
		moves = ft_mapa_modify(stack_a, stack_b, a_len, i, 'a');
		b_len += moves;
		a_len -= moves;
		// ft_putstr_fd("\n### ITERATION: ", 1);
		// ft_putnbr_fd(i, 1);
		// ft_putstr_fd("stack b:\n", 1);
		if ((i + 1) < digits)
		{
			moves = ft_mapa_modify(stack_b, stack_a, b_len, i + 1, 'b');
			b_len -= moves;
			a_len += moves;
		}
		// ft_putstr_fd("\n### stack_a len:\n", 1);
		// ft_putnbr_fd(a_len, 1);
		// ft_putstr_fd("\n### stack_b len:\n", 1);
		// ft_putnbr_fd(b_len, 1);
		// ft_putstr_fd("\nstack a:\n", 1);
		// ft_lstiter(*stack_a, ft_printlist);
		// ft_putstr_fd("stack b:\n", 1);
		// ft_lstiter(*stack_b, ft_printlist);
	}
	ft_emptyb(stack_a, stack_b);
}



int	main(int argc, char *argv[])
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (ft_parser(argc - 1, argv + 1, &stack_a))
		return (1);
	ft_sortidx_modify(&stack_a, &stack_b, argc - 1);
	// ft_lstiter(stack_a, ft_printlist);
	return (0);
}

	// 	int	i;
	// int	digits;

	// i = -1;
	// digits = ft_getbitslen(len - 1);
	// while (++i < digits * len)
	// {
	// 	if (!(((int *)(*stack_a)->content)[1] >> (i / digits) & 1))
	// 		ft_pb(stack_a, stack_b);
	// 	else
	// 		ft_r(stack_a);
	// 	while (((i + 1) % digits == 0) && *stack_b)
	// 		ft_pa(stack_a, stack_b);
	// }






	// ft_putstr_fd("\nlen:\n",1);
	// 	ft_putstr_fd("\nstack:\n",1);
	// 		ft_putstr_fd(&stack,1);
	// ft_putstr_fd("\n", 1);
