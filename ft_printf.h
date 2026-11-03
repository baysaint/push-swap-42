/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgencogl <mgencogl@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 13:29:11 by mgencogl          #+#    #+#             */
/*   Updated: 2026/10/30 17:37:40 by mgencogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdio.h>
# include "libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdarg.h>
# include <limits.h>

int		ft_printf(const char *key, ...);
void	convcheck(char c, int *count, va_list *ap, int *idx);
void	printfstring(va_list *ap, int *count);
void	printvoidpointer(va_list *ap, int *count);
void	printdecimal(va_list *ap, int *count);
void	printundecimal(va_list *ap, int *count);
void	printhexadecimal(va_list *ap, int *count, char c);
char	*itoabase(unsigned long ptr, int base);

#endif 