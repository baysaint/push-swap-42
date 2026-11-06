/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aude-la <aude-la@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 11:44:09 by aude-la           #+#    #+#             */
/*   Updated: 2026/11/05 12:41:17 by aude-la          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_lib.h"

int	print_x(unsigned long long n, char *base)
{
	static int	i;

	i = 0;
	if (n >= 16)
	{
		print_x(n / 16, base);
		i++;
	}
	n = n % 16;
	write(1, &base[n], 1);
	return (i + 1);
}

int	print_p(unsigned long n, char *base)
{
	int		count;

	count = 0;
	if ((void *)n == 0)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	write(1, "0x", 2);
	count += 2;
	count += print_x(n, base);
	return (count);
}

int	ft_triage(int c, va_list arglst)
{
	if (c == 'c')
		return (print_c((char)va_arg(arglst, int)));
	if (c == '%')
	{
		write(1, "%", 1);
		return (1);
	}
	if (c == 's')
		return (print_s(va_arg(arglst, char *)));
	if ((c == 'd') || (c == 'i'))
		return (print_di(va_arg(arglst, int)));
	if (c == 'u')
		return (print_u(va_arg(arglst, unsigned int)));
	if (c == 'x')
		return (print_x(va_arg(arglst, unsigned int),
				"0123456789abcdef"));
	if (c == 'X')
		return (print_x(va_arg(arglst, unsigned int),
				"0123456789ABCDEF"));
	if (c == 'p')
		return (print_p((unsigned long)va_arg(arglst, void *),
				"0123456789abcdef"));
	else
		return (-1);
}

int	ft_printf(const char *input, ...)
{
	int		i;
	int		count;
	int		written;
	va_list	arglst;

	va_start(arglst, input);
	i = 0;
	count = 0;
	while (input[i])
	{
		if ((input[i] == '%') && (input[i + 1]))
		{
			written = ft_triage(input[i + 1], arglst);
			i++;
		}
		else
			written = print_c(input[i]);
		if (written == -1)
			return (-1);
		i++;
		count += written;
	}
	va_end(arglst);
	return (count);
}
