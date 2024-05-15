/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capapes <capapes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 14:43:17 by capapes           #+#    #+#             */
/*   Updated: 2024/05/15 15:40:29 by capapes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_parser(int argc, char *argv[], t_list **stack_a)
{
	int	*arr;
	int	*idx;

	if (argc <= 0)
		return (0);
	if (!ft_are_str_int(argc, argv))
		return (ft_puterror());
	if (!ft_new_array(&arr, argc, argv))
		return (1);
	if (ft_are_repeated(arr, argc))
		return (free (arr), ft_puterror());
	if (!ft_add_indexes(arr, &idx, argc))
		return (free(arr), 1);
	if (!ft_new_stack(arr, idx, argc, stack_a))
		return (free(arr), free(idx), 1);
	free(arr);
	free(idx);
	return (0);
}

void	ft_free_all(t_list **stack_a, t_list **stack_b)
{
	ft_lstclear(stack_a, ft_free_content);
	ft_lstclear(stack_b, ft_free_content);
}

int	main(int argc, char *argv[])
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (ft_parser(argc - 1, argv + 1, &stack_a))
		return (1);
	if (ft_is_sorted(stack_a, argc -1))
		return (ft_free_all(&stack_a, &stack_b), 0);
	if (argc == 4)
		ft_sort3(&stack_a);
	if (argc == 6)
		ft_sort5(&stack_a, &stack_b, argc - 1);
	else
		ft_radix_sort(&stack_a, &stack_b, argc - 1);
	return (ft_free_all(&stack_a, &stack_b), 0);
}

// ft_lstiter(stack_a, ft_printlist);