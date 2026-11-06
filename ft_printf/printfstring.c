/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printfstring.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgencogl <mgencogl@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/30 13:01:56 by mgencogl          #+#    #+#             */
/*   Updated: 2026/10/30 16:58:41 by mgencogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	printfstring(va_list *ap, int *count)
{
	char	*str;

	str = va_arg(*ap, char *);
	if (!str)
	{
		ft_putstr_fd("(null)", 1);
		*count += 6;
		return ;
	}
	ft_putstr_fd(str, 1);
	*count += ft_strlen(str);
}
