/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgencogl <mgencogl@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 16:18:40 by mgencogl          #+#    #+#             */
/*   Updated: 2026/11/10 18:07:37 by mgencogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_lib.h"

/*void	check_flag_record(char **argv, int argc, t_rec *specs)
{
	int		i;
	int		j;
	char	*str;

	
}

int	has_illegal_char(char **argv, int argc, t_rec *specs)
{
	int		i;
	int		j;
	char	c;
	char	*str;

	i = 1;
	str = " +-\t\n\v\f\rsimpleducoxatvbnh0123456789";
	while (i < argc)
	{
		j = 0;
		while(argv[i][j])
		{
			c = argv[i][j];
			if (!ft_strchr(str, c))
			{
				return (1);
				break;
			}
			j++;
		}
		i++;
	}
	return (0);
}*/



int	parse_flag(char *tok, t_rec *specs)
{
	int	flag;

	flag = 0;
	if (ft_strncmp(tok, "--bench", 8) == 0)
	{
		if (specs->bench_exists)
			return (0);
		specs->bench_exists = 1;
		return (1);
	}
	if (ft_strncmp(tok, "--adaptive", 11) == 0)
		flag = 1;
	else if (ft_strncmp(tok, "--simple", 9) == 0)
		flag = 2;
	else if (ft_strncmp(tok, "--medium", 9) == 0)
		flag = 3;
	else if (ft_strncmp(tok, "--complex", 10) == 0)
		flag = 4;
	if (flag == 0 || specs->strategy != 0)
		return (0);
	specs->strategy = flag;
	return (1);
}

void	input_parser(char **argv, int argc, t_rec *specs, t_list **a)
{
	int i;

	i = 1;
	while(i < argc)
	{
		if(!arg_processor(argv[i], specs, a))
		{
			specs->error_exists = 1;
			return ;
		}
		i++;
	}
	if (specs->token_len == 0)
	{
		specs->error_exists = 1;
		return ;
	}
	if(specs->strategy == 0)
		specs.strategy = 1;
}

