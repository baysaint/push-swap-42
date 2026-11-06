/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgencogl <mgencogl@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 14:17:32 by mgencogl          #+#    #+#             */
/*   Updated: 2026/10/15 18:45:55 by mgencogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// explanation to parameter 'direction':
// it is telling if search is from start[0] or from end[1]. 

static int	ismatch(char c, char const *set)
{
	size_t	idx;

	idx = 0;
	while (set[idx])
	{
		if (set[idx] == c)
			return (1);
		idx++;
	}
	return (0);
}

static	int	getidx(char const *str, char const *set, int direction, size_t len)
{
	size_t	outeridx;

	if (direction == 0)
	{
		outeridx = 0;
		while (str[outeridx])
		{
			if (ismatch(str[outeridx], set))
				outeridx++;
			else
				break ;
		}
	}
	else
	{
		outeridx = len;
		while (outeridx > 0)
		{
			if (!ismatch(str[outeridx - 1], set))
				break ;
			outeridx--;
		}
	}
	return (outeridx);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	idx1;
	size_t	idx2;
	size_t	i;
	size_t	len;
	char	*newstr;

	if (!s1 || !set)
		return (NULL);
	len = ft_strlen(s1);
	idx1 = getidx(s1, set, 0, len);
	idx2 = getidx(s1, set, 1, len);
	if (idx1 >= idx2)
		return (ft_strdup(""));
	newstr = malloc(sizeof(char) * (idx2 - idx1 + 1));
	if (!newstr)
		return (NULL);
	i = 0;
	while (idx1 < idx2)
	{
		newstr[i] = s1[idx1];
		i++;
		idx1++;
	}
	newstr[i] = '\0';
	return (newstr);
}
