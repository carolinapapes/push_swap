/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capapes <capapes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 14:43:17 by capapes           #+#    #+#             */
/*   Updated: 2024/05/11 20:14:36 by capapes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"

void	ft_change(char **str)
{
	++(*str);
}

void	ft_sortidx(t_list **stack_a, t_list **stack_b)
{
	int	i;
	int	j;
	int	len;
	int	index;

	i = -1;
	int digits;
	int aux;
	len = ft_lstsize(*stack_a);
	aux = len - 1;
	digits = 0;
	while (aux)
	{
		aux = aux >> 1;
		digits++;
	}

	while (++i < digits)
	{
		j = -1;
		len = ft_lstsize(*stack_a);
		while (*stack_a && ++j < len)
		{
			index = ((int *)(*stack_a)->content)[1];
			if ((index >> i & 1) != 1)
				ft_pb(stack_a, stack_b);
			else
				ft_r(stack_a);
		}
		while (*stack_b)
			ft_pa(stack_a, stack_b);
	}
}

int	main(int argc, char *argv[])
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (ft_parser(argc - 1, argv + 1, &stack_a))
		return (1);
	ft_sortidx(&stack_a, &stack_b);
	return (0);
}



