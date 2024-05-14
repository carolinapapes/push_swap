/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_idx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capapes <capapes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 17:57:38 by capapes           #+#    #+#             */
/*   Updated: 2024/05/14 19:16:19 by capapes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_createarray(int **arr, int n, char *argv[])
{
	int	i;

	*arr = (int *) malloc(n * sizeof(int));
	if (!(*arr))
		return (0);
	i = -1;
	while (++i < n)
		(*arr)[i] = ft_atoi(argv[i]);
	return (1);
}

int	ft_index(int *arr, int n, int nbr)
{
	int	i;
	int	res;

	res = 0;
	i = -1;
	while (++i < n)
		if (arr[i] < nbr)
			res++;
	return (res);
}

int	ft_find_index(int *arr, int **idx, int n)
{
	int	i;

	*idx = (int *) malloc(n * sizeof(int));
	if (!(*idx))
		return (0);
	i = -1;
	while (++i < n)
		(*idx)[i] = ft_index(arr, n, arr[i]);
	return (1);
}
