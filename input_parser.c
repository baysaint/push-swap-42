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

void	has_illegal_char(char **argv, int argc, t_rec *specs)
{
	int		i;
	int		j;
	char	c;
	char	*str;

	i = 1;
	j = 0;
	str = " +-\t\n\v\f\rsimpleducoxatvbnh0123456789";
	while (i < argc)
	{
		while(argv[i][j] && specs->error_exists == 0)
		{
			c = argv[i][j];
			if (!ft_strchr(str, c))
			{
				specs->error_exists = 1;
				break;
			}
			j++;
		}
		i++;
	}
}

void	input_parser(char **argv, int argc, t_rec *specs, t_list **a)
{
	int i;
	
	i = 1;
	has_illegal_char(argv, argc, specs);
	
	
	
}
