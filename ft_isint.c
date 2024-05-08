/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isint.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capapes <capapes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 17:35:14 by capapes           #+#    #+#             */
/*   Updated: 2024/05/08 17:55:58 by capapes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isnbr(char *s)
{
	if (ft_isempty(s))
		return (0);
	if (ft_issign(*s))
		++s;
	if (ft_isempty(s))
		return (0);
	while (ft_isdigit(*s))
		++s;
	if (!ft_isempty(s))
		return (0);
	return (1);
}

char	*ft_getnonzero(char *s)
{
	if (ft_issign(*s))
		++s;
	while (*s && *s == '0')
		++s;
	return (s);
}

int	ft_isint(char *s)
{
	char	sign;
	int		len;

	if (!ft_isnbr(s))
		return (0);
	sign = *s;
	s = ft_getnonzero(s);
	if (ft_isempty(s))
		return (1);
	len = ft_strlen(s);
	if (len != 10)
		return (len < 10);
	if (sign == '-')
		return (ft_strncmp(STR_MIN_INT, s, len) >= 0);
	return (ft_strncmp(STR_MAX_INT, s, len) >= 0);
}

int ft_isarrint(int argc, char *argv[])
{
	int	i;
	int	isvalid;

	i = -1;
	isvalid = 1;
	while (isvalid && ++i < argc)
		isvalid = ft_isint(argv[i]);
	if (!isvalid)
		return (0);
	return (1);
}

int	ft_isunique(int *arr, int n)
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
			return (0);
	}
	return (1);
}