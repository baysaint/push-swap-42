#include "push_swap_lib.h"

void	ft_free_result(char **result)
{
	int j;

	j = 0;
	if (!result)
		return ;
	while (result[j])
	{
		free(result[j]);
		j++;
	}
	free(result);
	return ;
}

static int	ft_count_words(char const *s, char *ws)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] && ft_strchr(ws, s[i]))
			i++;
		if (s[i] && !ft_strchr(ws, s[i]))
		{
			count++;
			while (s[i] && !ft_strchr(ws, s[i]))
				i++;
		}
	}
	return (count);
}

static int	ft_create_words(char **result, char const *s, char *ws)
{
	int		i;
	int		j;
	int		start;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] && ft_strchr(ws, s[i]))
			i++;
		if (!s[i])
			break ;
		start = i;
		while (s[i] && !ft_strchr(ws, s[i]))
			i++;
		result[j] = ft_substr(s, start, i - start);
		if (!result[j])
		{
			ft_free_result(result, j);
			return (0);
		}
		j++;
	}
	result[j] = NULL;
	return (1);
}

char	**ft_split_ps(char	const *s)
{
	char	**result;
	int		count;
    char    *whitespaces;

    whitespaces = " \n\t\r\v\f";
	if (!s)
		return (NULL);
	count = ft_count_words(s, whitespaces);
	result = (char **)malloc((count + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	if (!ft_create_words(result, s, whitespaces))
		return (NULL);
	return (result);
}