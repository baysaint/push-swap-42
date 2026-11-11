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

int	parse_flag(char *tok, t_rec *specs);

int parse_number(char *tok, int number, t_list **a);

int append_note(t_list **a, int number);

int	token_processor(char *tok, t_rec *specs, t_list **a)
{
	int	number;

	if(tok[0] == '-' && tok[1] == '-')
		return(parse_flag(tok, specs));
	if(!parse_number(tok, &number, a))
		return(0);
	return(append_note(a, number));
}

int	arg_processor(char *arg, t_rec *specs, t_list **a)
{
	char **tokens;
	int i;

	i = 0;
	tokens = ft_split_ps(arg);
	if(!tokens || !tokens[0])
	{
		ft_free_result(tokens);
		return (0);
	}
	while(tokens[i])
	{
		if(!token_processor(tokens[i], specs, a))
		{
			ft_free_result(tokens);
			return (0);
		}
		i++;
	}
	ft_free_result(tokens);
	return (1);
}

void	input_parser(char **argv, int argc, t_rec *specs, t_list **a)
{
	int i;

	i = 0;
	while(i<argc)
	{
		if(!arg_processor(argv[i], specs, a))
		{
			specs->error_exists = 1;
			return ;
		}
		i++;
	}
	if(specs->strategy == 0)
		specs.strategy = 1;
}

