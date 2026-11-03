/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgencogl <mgencogl@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 13:30:23 by mgencogl          #+#    #+#             */
/*   Updated: 2026/10/30 17:42:57 by mgencogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	void	print_nonkey_chars(const char *key, int *count, int *idx)
{
	ft_putchar_fd (key[*idx], 1);
	(*count)++;
	(*idx)++;
}

static	int	checknext(char c)
{
	char	*str;

	str = "cspdiuxX%";
	if (!ft_strchr(str, c) || c == '\0')
		return (0);
	return (1);
}

int	ft_printf(const char *key, ...)
{
	va_list	ap;
	int		count;
	int		idx;

	va_start (ap, key);
	count = 0;
	idx = 0;
	while (key[idx])
	{
		if (key[idx] == '%' && checknext (key[idx + 1]))
		{
			convcheck (key[idx + 1], &count, &ap, &idx);
			if (count == -1)
			{
				va_end (ap);
				return (count);
			}
		}
		else if (key[idx] == '%' && key[idx + 1])
			idx++;
		else if (key[idx])
			print_nonkey_chars (key, &count, &idx);
	}
	va_end(ap);
	return (count);
}
/*
int	main(void)
{
	int	ret_std;
	int	ret_ft;

	printf("=== STARTING FT_PRINTF TESTS ===\n\n");

	// 1. Character Tests (%c)
	printf("--- [%%c] Character Tests ---\n");
	ret_std = printf("  Std: [%c] [%c] [%c]\n", 'A', '0', '\0');
	ret_ft  = ft_printf("   Ft: [%c] [%c] [%c]\n", 'A', '0', '\0');
	printf("  Return values -> Std: %d | Ft: %d\n\n", ret_std, ret_ft);

	// 2. String Tests (%s)
	printf("--- [%%s] String Tests ---\n");
	ret_std = printf("  Std: [%s] [%s]\n", "Hello World", (char *)NULL);
	ret_ft  = ft_printf("   Ft: [%s] [%s]\n", "Hello World", (char *)NULL);
	printf("  Return values -> Std: %d | Ft: %d\n\n", ret_std, ret_ft);

	// 3. Integer & Decimal Tests (%d / %i)
	printf("--- [%%d / %%i] Integer Tests ---\n");
	ret_std = printf("  Std: [%d] [%i] [%d]\n", 0, -42, 2147483647);
	ret_ft  = ft_printf("   Ft: [%d] [%i] [%d]\n", 0, -42, 2147483647);
	printf("  Return values -> Std: %d | Ft: %d\n", ret_std, ret_ft);
	
	ret_std = printf("  Std Min Int: [%d]\n", INT_MIN);
	ret_ft  = ft_printf("   Ft Min Int: [%d]\n", INT_MIN);
	printf("  Return values -> Std: %d | Ft: %d\n\n", ret_std, ret_ft);

	// 4. Unsigned Integer Tests (%u)
	printf("--- [%%u] Unsigned Tests ---\n");
	ret_std = printf("  Std: [%u] [%u]\n", 0, 4294967295U);
	ret_ft  = ft_printf("   Ft: [%u] [%u]\n", 0, 4294967295U);
	printf("  Return values -> Std: %d | Ft: %d\n\n", ret_std, ret_ft);

	// 5. Hexadecimal Tests (%x / %X)
	printf("--- [%%x / %%X] Hexadecimal Tests ---\n");
	ret_std = printf("  Std: [%x] [%X] [%x]\n", 0, 3735928559U, 42);
	ret_ft  = ft_printf("   Ft: [%x] [%X] [%x]\n", 0, 3735928559U, 42);
	printf("  Return values -> Std: %d | Ft: %d\n\n", ret_std, ret_ft);

	// 6. Pointer Tests (%p)
	printf("--- [%%p] Pointer Tests ---\n");
	int	a = 42;
	ret_std = printf("  Std Address: [%p] [%p]\n", &a, (void *)NULL);
	ret_ft  = ft_printf("   Ft Address: [%p] [%p]\n", &a, (void *)NULL);
	printf("  Return values -> Std: %d | Ft: %d\n\n", ret_std, ret_ft);

	// 7. Percent Escape Tests (%%)
	printf("--- [%%%%] Percent Sign Tests ---\n");
	ret_std = printf("  Std: [%%] [%%%%] [%% d]\n");
	ret_ft  = ft_printf("   Ft: [%%] [%%%%] [%% d]\n");
	printf("  Return values -> Std: %d | Ft: %d\n\n", ret_std, ret_ft);

	// 8. Mixed Format Test
	printf("--- Mixed Format Validation ---\n");
	ret_std = printf("  Std: Score: %d%% for player %s (ID: %x)\n",
			100, "mgencogl", 255);
	ret_ft = ft_printf("   Ft: Score: %d%% for player %s (ID: %x)\n",
			100, "mgencogl", 255);
	printf("  Return values -> Std: %d | Ft: %d\n\n",
			ret_std, ret_ft);

	printf("=== TESTING COMPLETE ===\n");
	return (0);
}
*/
