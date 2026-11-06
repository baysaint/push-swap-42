/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   csdiu.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aude-la <aude-la@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 11:24:13 by aude-la           #+#    #+#             */
/*   Updated: 2026/11/05 12:42:21 by aude-la          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_lib.h"

int	print_c(char c)
{
	write(1, &c, 1);
	return (1);
}

int	print_s(char *s)
{
	if (s == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	write(1, s, ft_strlen(s));
	return (ft_strlen(s));
}

//printing a decimal (base 10) number or an integer in base 10
int	print_di(int n)
{
	long			nb;
	static int		i;

	i = 0;
	nb = n;
	if (n < 0)
	{
		write(1, "-", 1);
		nb = -nb;
	}
	if (nb >= 10)
	{
		print_di(nb / 10);
		i++;
	}
	print_c((nb % 10 + '0'));
	if (n < 0)
		i++;
	return (i + 1);
}

// printing an unsigned decimal (base 10) number
int	print_u(unsigned int n)
{
	static int	i;

	i = 0;
	if (n < 0)
	{
		print_c('-');
		n = -n;
		i++;
	}
	if (n >= 10)
	{
		print_u(n / 10);
		i++;
	}
	print_c((n % 10 + '0'));
	return (i + 1);
}
