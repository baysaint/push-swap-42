/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printvoidpointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgencogl <mgencogl@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/30 13:02:39 by mgencogl          #+#    #+#             */
/*   Updated: 2026/10/30 16:59:23 by mgencogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	printvoidpointer(va_list *ap, int *count)
{
	void	*ptr;
	char	*str;

	ptr = va_arg(*ap, void *);
	if (!ptr)
	{
		ft_putstr_fd("(nil)", 1);
		*count += 5;
		return ;
	}
	str = itoabase((unsigned long)ptr, 1);
	if (!str)
	{
		*count = -1;
		return ;
	}
	ft_putstr_fd("0x", 1);
	*count += 2;
	ft_putstr_fd(str, 1);
	*count += ft_strlen(str);
	free(str);
}
