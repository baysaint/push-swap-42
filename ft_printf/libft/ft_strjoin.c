/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgencogl <mgencogl@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 12:49:04 by mgencogl          #+#    #+#             */
/*   Updated: 2026/10/15 18:41:37 by mgencogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	joiner(char *str, char const *insert, size_t index)
{
	size_t	idx;

	idx = 0;
	while (insert[idx])
	{
		str[index] = insert[idx];
		idx++;
		index++;
	}
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*newstr;
	size_t	i;
	size_t	j;
	size_t	m;

	if (!s1 || !s2)
		return (NULL);
	i = ft_strlen(s1);
	j = ft_strlen(s2);
	m = i + j;
	newstr = malloc(sizeof(char) * (m + 1));
	if (!newstr)
		return (NULL);
	joiner(newstr, s1, 0);
	joiner(newstr, s2, i);
	newstr[m] = '\0';
	return (newstr);
}
