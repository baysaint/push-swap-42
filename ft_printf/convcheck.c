/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convcheck.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgencogl <mgencogl@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/30 11:30:55 by mgencogl          #+#    #+#             */
/*   Updated: 2026/10/30 17:01:43 by mgencogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	convcheck(char c, int *count, va_list *ap, int *idx)
{
	unsigned char	ch;

	if (c == 'c')
	{
		ch = (unsigned char)va_arg(*ap, int);
		ft_putchar_fd(ch, 1);
		(*count)++;
	}
	if (c == 's')
		printfstring(ap, count);
	if (c == 'p')
		printvoidpointer(ap, count);
	if (c == 'i' || c == 'd')
		printdecimal(ap, count);
	if (c == 'u')
		printundecimal(ap, count);
	if (c == 'x' || c == 'X')
		printhexadecimal(ap, count, c);
	if (c == '%')
	{
		ft_putchar_fd('%', 1);
		(*count)++;
	}
	(*idx) += 2;
}
