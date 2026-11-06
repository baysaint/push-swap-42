/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printdecimals.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgencogl <mgencogl@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/30 13:03:18 by mgencogl          #+#    #+#             */
/*   Updated: 2026/10/30 17:00:17 by mgencogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int	ft_ulen(unsigned int num)
{
	int	len;

	len = 1;
	while (num >= 10)
	{
		num /= 10;
		len ++;
	}
	return (len);
}

static	char	*ft_utoa(unsigned int num)
{
	char	*str;
	int		len;

	len = ft_ulen(num);
	str = malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[len] = '\0';
	while (len > 0)
	{
		str[len - 1] = (num % 10) + '0';
		num /= 10;
		len--;
	}
	return (str);
}

void	printundecimal(va_list *ap, int *count)
{
	char			*str;
	unsigned int	num;

	num = va_arg(*ap, unsigned int);
	str = ft_utoa(num);
	if (!str)
	{
		*count = -1;
		return ;
	}
	ft_putstr_fd(str, 1);
	*count += ft_strlen(str);
	free(str);
}

void	printdecimal(va_list *ap, int *count)
{
	char	*str;
	int		num;

	num = va_arg(*ap, int);
	str = ft_itoa(num);
	if (!str)
	{
		*count = -1;
		return ;
	}
	ft_putstr_fd(str, 1);
	*count += ft_strlen(str);
	free(str);
}
