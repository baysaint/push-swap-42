/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_tester.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aude-la <aude-la@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 16:15:01 by aude-la           #+#    #+#             */
/*   Updated: 2026/11/05 12:15:08 by aude-la          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_lib.h"

int	main(int argc, char **argv)
{
	int	n = 1;
	char	*title_a = "a";
	t_list	*lst_a = NULL;
	while (n < 4)
	{
		ft_lstadd_back(&lst_a, ft_lstnew((char *)argv[n]));
		n++;
	}
	printf("%s\n", title_a);
	t_list	*currenta = lst_a;
	while (currenta)
	{
		printf("%s\n", (char *)currenta->content);
		currenta = currenta->next;
	}
	printf("\n");
	int	i = 4;
	char	*title_b = "b";
	t_list	*lst_b = NULL;
	while (i < argc)
	{
		ft_lstadd_back(&lst_b, ft_lstnew((char *)argv[i]));
		i++;
	}
	printf("%s\n", title_b);
	t_list	*currentb = lst_b;
	while (currentb)
	{
		printf("%s\n", (char *)currentb->content);
		currentb = currentb->next;
	}
	printf("-----------\n");
	ft_rr(&lst_a, &lst_b);
	currenta = lst_a;
	while (currenta)
	{
		printf("%s\n", (char *)currenta->content);
		currenta = currenta->next;
	}
	printf("\n");
	currentb = lst_b;
	while (currentb)
	{
		printf("%s\n", (char *)currentb->content);
		currentb = currentb->next;
	}
	return (0);
}
