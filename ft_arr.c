/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_idx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capapes <capapes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 17:57:38 by capapes           #+#    #+#             */
/*   Updated: 2024/05/15 15:15:49 by capapes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_are_repeated(int *arr, int n)
{
	int	i;
	int	j;

	i = -1;
	while (++i < n)
	{
		j = i;
		while (++j < n && arr[j] != arr[i])
			;
		if (j != n)
			return (1);
	}
	return (0);
}

int	ft_new_array(int **arr, int n, char *argv[])
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

int	ft_get_index(int *arr, int n, int nbr)
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

int	ft_add_indexes(int *arr, int **idx, int n)
{
	int	i;

	*idx = (int *) malloc(n * sizeof(int));
	if (!(*idx))
		return (0);
	i = -1;
	while (++i < n)
		(*idx)[i] = ft_get_index(arr, n, arr[i]);
	return (1);
}
