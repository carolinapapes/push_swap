/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aux.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capapes <capapes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 14:25:09 by capapes           #+#    #+#             */
/*   Updated: 2024/05/15 15:21:31 by capapes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_printlist(void *content)
{
	ft_putnbr_fd(((int *)content)[0], 1);
	ft_putstr_fd("\n", 1);
}

int	ft_puterror(void)
{
	return (ft_putstr_fd("Error\n", 2), 1);
}
