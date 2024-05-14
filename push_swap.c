/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capapes <capapes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 14:43:17 by capapes           #+#    #+#             */
/*   Updated: 2024/05/14 19:16:50 by capapes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_printlist(void *content)
{
	ft_putnbr_fd(((int *)content)[0], 1);
	ft_putstr_fd("\n", 1);
}

void	ft_sort3(t_list **a)
{
	int	first;
	int	second;
	int	third;

	while (!ft_issorted(*a, 4))
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

void	ft_push_first(t_list **a, t_list **b, int len)
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

	ft_push_first(a, b, len);
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

int	main(int argc, char *argv[])
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (ft_parser(argc - 1, argv + 1, &stack_a))
		return (1);
	if (ft_issorted(stack_a, argc -1))
	{
		ft_lstclear(&stack_a, ft_freecontent);
		ft_lstclear(&stack_b, ft_freecontent);
		return (0);
	}
	if (argc == 4)
		ft_sort3(&stack_a);
	if (argc == 6)
		ft_sort5(&stack_a, &stack_b, argc - 1);
	else
		ft_sortidx(&stack_a, &stack_b, argc - 1);
	ft_lstclear(&stack_a, ft_freecontent);
	ft_lstclear(&stack_b, ft_freecontent);
	return (0);
}
