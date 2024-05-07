/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capapes <capapes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 14:43:17 by capapes           #+#    #+#             */
/*   Updated: 2024/05/06 15:35:07 by capapes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <stdio.h>

int	main(int argc, char *argv[])
{

	char *prog = argv[0];

	prog = "null";

	if (argc == 1)
	{
		ft_putstr_fd("error no input", 1);
		return (1);
	}
	return (0);
}
