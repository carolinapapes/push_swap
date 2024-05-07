/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capapes <capapes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 15:34:04 by capapes           #+#    #+#             */
/*   Updated: 2024/05/07 20:38:31 by capapes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_puterror(void)
{
	return (ft_putstr_fd("Error", 1), 1);
}

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

int	ft_isint(char *s)
{
	char	sign;
	int		len;

	if (!ft_isnbr(s))
		return (0);
	sign = s[0];
	if (ft_issign(sign))
		++s;
	while (*s && *s == '0')
		++s;
	if (ft_isempty(s))
		return (1);
	len = ft_strlen(s);
	if (len > 10)
		return (0);
	if (len < 10)
		return (1);
	if (len == 10 && sign == '-')
		return (ft_strncmp(s, "2147483648", len) <= 0);
	return (ft_strncmp("2147483647", s, len) >= 0);
}

int	ft_parser(int argc, char *argv[])
{
	int		i;
	int		isvalid;

	if (argc <= 1)
		return (ft_puterror());
	i = 0;
	isvalid = 1;
	while (isvalid && ++i < argc)
		isvalid = ft_isint(argv[i]);
	if (!isvalid)
		return (ft_puterror());
	ft_putstr_fd("todo ok!", 1);
	return (0);
}

// INT_MIN : -2147483648
// INT_MAX :  2147483647

// int	ft_puterror(int i)
// {
// 	if (i == 1)
// 		ft_putstr_fd("[Error] No input", 2);
// 	if (i == 2)
// 		ft_putstr_fd("[Error] Invalid charset or format", 2);
// 	if (i == 3)
// 		ft_putstr_fd("[Error] Invalid format", 2);
// 	if (i == 4)
// 		ft_putstr_fd("[Error] All numbers must be intergers", 2);
// 	if (i == 5)
// 		ft_putstr_fd("[Error] No duplicates allowed", 2);
// 	return (1);
// }

// [2 = INVALID CHARSET] only valid characters [-, +, ' ', 0-9];
// [3 = INVALID FORMAT]if a digit must be only followed by number or space;
// [3 = INVALID FORMAT] if a sign only be follow by number;

// Si es el primer caracter puede ser un signo.
// Todos los caracteres (excepto el primero) solo deben ser digitos.


// [4 = NUMBER MUST BE AN INTERGER] if the length its longer than the max int but its preceded by 00000000, dont count them until the space. 
// [4 = NUMBER MUST BE AN INTERGER] if its the same length compare the characters if its equal, compare the next, if its less its ok.
// [4 = NUMBER MUST BE AN INTERGER] biggest string must be length < MAX_INT. Lenght > - MIN_INT

// 1 trim sign
// 2 trim zeros

	// err = ft_findup(&argv[1]);
	// if (err)x
	// 	return (ft_puterror(err));