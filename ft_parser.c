/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capapes <capapes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 15:34:04 by capapes           #+#    #+#             */
/*   Updated: 2024/05/08 19:53:39 by capapes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	ft_puterror(void)
{
	return (ft_putstr_fd("Error\n", 2), 1);
}

int	ft_createnode(int value, int index, t_list **node)
{
	t_list	*newnode;
	int		*content;

	newnode = malloc(sizeof(t_list));
	if (!newnode)
		return (0);
	content = malloc(sizeof(int) * 2);
	if (!content)
		return (0);
	content[0] = value;
	content[1] = index;
	newnode->content = (void *)content;
	*node = newnode;
	return (1);
}

void	ft_stackadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
	return ;
}

int	ft_createstack(int *arr, int *idx, int n, t_list **stack_a)
{
	int		i;
	t_list	*node;

	i = n;
	node = NULL;
	while (--i > -1)
	{
		if (!ft_createnode(arr[i], idx[i], &node))
			return (0); // clean all other nodes here
		ft_stackadd_front(stack_a, node);
	}
	return (1);
}

int	ft_parser(int argc, char *argv[], t_list **stack_a)
{
	int	*arr;
	int	*idx;

	if (argc <= 0)
		return (0);
	if (!ft_isarrint(argc, argv))
		return (ft_puterror());
	if (!ft_createarray(&arr, argc, argv))
		return (1);
	if (!ft_isunique(arr, argc))
		return (free (arr), ft_puterror());
	if (!ft_find_index(arr, &idx, argc))
		return (free(arr), 1);
	ft_putstr_fd("no errors\n", 1);
	if (!ft_createstack(arr, idx, argc, stack_a))
		return (free(arr), free(idx), 1);
	return (0);
}
