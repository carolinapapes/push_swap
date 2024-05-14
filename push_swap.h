/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capapes <capapes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 17:45:54 by capapes           #+#    #+#             */
/*   Updated: 2024/05/14 12:42:50 by capapes          ###   ########.fr       */
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
void	ft_rx(t_list **target, char x);
void	ft_px(t_list **to, t_list **from, char x);
void	ft_emptyb(t_list **stack_a, t_list **stack_b);
void	ft_printlist(void *content);
void	ft_sortidx(t_list **stack_a, t_list **stack_b, int len);
void	ft_freecontent(void *content);
void	ft_sx(t_list **target, char x);
void	ft_rrx(t_list **target, char x);
int		ft_issorted(t_list *i, int len);

#endif