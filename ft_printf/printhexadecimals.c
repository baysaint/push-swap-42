/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printhexadecimals.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgencogl <mgencogl@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/30 13:03:51 by mgencogl          #+#    #+#             */
/*   Updated: 2026/10/30 17:23:57 by mgencogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printdecimals.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgencogl <mgencogl@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/30 13:03:18 by mgencogl          #+#    #+#             */
/*   Updated: 2026/10/30 16:14:29 by mgencogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	printhexadecimal(va_list *ap, int *count, char c)
{
	char			*str;
	unsigned int	num;

	str = NULL;
	num = va_arg(*ap, long);
	if (c == 'x')
		str = itoabase(num, 1);
	else if (c == 'X')
		str = itoabase(num, 2);
	if (!str)
	{
		*count = -1;
		return ;
	}
	ft_putstr_fd (str, 1);
	(*count) += ft_strlen(str);
	free(str);
}
