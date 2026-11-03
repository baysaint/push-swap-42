/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoabase.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgencogl <mgencogl@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/30 16:32:24 by mgencogl          #+#    #+#             */
/*   Updated: 2026/10/30 17:30:01 by mgencogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	void	convertbase(unsigned long ptr, char *bc, char *numstr, int len)
{
	if (ptr >= 16)
		convertbase (ptr / 16, bc, numstr, len - 1);
	numstr[len] = bc[ptr % 16];
}

// if base == 1, lowercase, if base == 2, uppercase
char	*itoabase(unsigned long ptr, int base)
{
	unsigned long	num;
	char			*basechar;
	char			*numstr;
	int				len;

	num = ptr;
	if (base == 1)
		basechar = "0123456789abcdef";
	else if (base == 2)
		basechar = "0123456789ABCDEF";
	len = 1;
	while (num >= 16)
	{
		num /= 16;
		len++;
	}
	numstr = malloc ((len + 1) * sizeof(char));
	if (!numstr)
		return (NULL);
	numstr[len] = '\0';
	convertbase(ptr, basechar, numstr, (len - 1));
	return (numstr);
}
