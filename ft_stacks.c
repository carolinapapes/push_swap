/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stacks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capapes <capapes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 14:31:12 by capapes           #+#    #+#             */
/*   Updated: 2024/05/15 15:33:40 by capapes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_get_content(t_list *node)
{
	return (((int *)(node->content))[1]);
}

void	ft_free_content(void *content)
{
	free(content);
}

int	ft_is_sorted(t_list *i, int len)
{
	t_list	*j;
	int		k;

	k = -1;
	while (i != NULL && ++k < len)
	{
		j = i -> next;
		while (j != NULL)
		{
			if (ft_get_content(i) > ft_get_content(j))
				return (0);
			j = j -> next;
		}
		i = i -> next;
	}
	return (1);
}

int	ft_new_node(int value, int index, t_list **node)
{
	int		*content;

	content = malloc(sizeof(int) * 2);
	if (!content)
		return (0);
	content[0] = value;
	content[1] = index;
	*node = ft_lstnew((void *)content);
	if (!(*node))
	{
		free(content);
		return (0);
	}
	return (1);
}

int	ft_new_stack(int *arr, int *idx, int n, t_list **stack_a)
{
	int		i;
	t_list	*node;

	i = n;
	while (--i > -1)
	{
		if (!ft_new_node(arr[i], idx[i], &node))
		{
			ft_lstclear(stack_a, ft_free_content);
			free(stack_a);
			return (0);
		}
		ft_lstadd_front(stack_a, node);
	}
	return (1);
}

