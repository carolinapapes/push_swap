/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capapes <capapes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 17:45:54 by capapes           #+#    #+#             */
/*   Updated: 2024/05/13 15:20:00 by capapes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H
# include "libft/libft.h"

# define STR_MAX_INT "2147483647"
# define STR_MIN_INT "2147483648"

int		ft_isunique(int *arr, int n);
int		ft_isarrint(int argc, char *argv[]);
int		ft_createarray(int **arr, int n, char *argv[]);
int		ft_find_index(int *arr, int **idx, int n);
int		ft_parser(int argc, char *argv[], t_list **stack_a);
void	ft_pa(t_list **to, t_list **from);
void	ft_pb(t_list **from, t_list **to);
void	ft_r(t_list **target);
void	ft_rx(t_list **target, char x);
void	ft_px(t_list **to, t_list **from, char x);

#endif