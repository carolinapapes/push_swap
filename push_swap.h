/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capapes <capapes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 17:45:54 by capapes           #+#    #+#             */
/*   Updated: 2024/05/15 15:50:58 by capapes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H
# include "libft/libft.h"

# define STR_MAX_INT "2147483647"
# define STR_MIN_INT "2147483648"

int		ft_are_str_int(int argc, char *argv[]);
int		ft_new_array(int **arr, int n, char *argv[]);
int		ft_are_repeated(int *arr, int n);
int		ft_add_indexes(int *arr, int **idx, int n);
int		ft_new_stack(int *arr, int *idx, int n, t_list **stack_a);
int		ft_is_sorted(t_list *i, int len);
int		ft_puterror(void);
void	ft_emptyb(t_list **stack_a, t_list **stack_b);
void	ft_printlist(void *content);
void	ft_radix_sort(t_list **stack_a, t_list **stack_b, int len);
void	ft_free_content(void *content);
void	ft_px(t_list **to, t_list **from, char x);
void	ft_sx(t_list **target, char x);
void	ft_rx(t_list **target, char x);
void	ft_rrx(t_list **target, char x);
void	ft_sort3(t_list **a);
void	ft_sort5(t_list **a, t_list **b, int len);
int		ft_get_content(t_list *node);

#endif