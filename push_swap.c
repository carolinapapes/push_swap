/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capapes <capapes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 14:43:17 by capapes           #+#    #+#             */
/*   Updated: 2024/05/11 22:36:37 by capapes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"

void	ft_change(char **str)
{
	++(*str);
}

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

void	ft_sortidx(t_list **stack_a, t_list **stack_b, int len)
{
	int	i;
	int	j;
	int	digits;

	if (!len)
		return ;
	i = -1;
	digits = ft_getbitslen(len - 1);
	while (++i < digits)
	{
		j = -1;
		while (++j < len)
		{
			if (!(((int *)(*stack_a)->content)[1] >> i & 1))
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
	ft_sortidx(&stack_a, &stack_b, argc - 1);
	return (0);
}



