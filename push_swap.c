/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capapes <capapes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 14:43:17 by capapes           #+#    #+#             */
/*   Updated: 2024/05/08 19:54:33 by capapes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h>
#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_list	*stack_a;

	stack_a = NULL;
	if (ft_parser(argc - 1, argv + 1, &stack_a))
		return (1);
	int *node = stack_a->content;
	ft_putnbr_fd(node[0], 1);
	return (0);
}
