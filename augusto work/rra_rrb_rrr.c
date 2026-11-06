/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra_rrb_rrr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aude-la <aude-la@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 16:15:01 by aude-la           #+#    #+#             */
/*   Updated: 2026/11/05 12:15:40 by aude-la          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_lib.h"

void	ft_rra(t_list **lst_a, int	check)
{
	t_list	*first;
	t_list	*current;
	t_list	*last;
	
	if (!lst_a || !*lst_a || !(*lst_a)->next)
		return ;
	first = *lst_a;
	current = *lst_a;
	while(current->next->next)
		current = current->next;
	last = current->next;
	last->next = first;
	current->next = NULL;
	*lst_a = last;
	if (check != 1)
		ft_printf("rra\n");
}

void	ft_rrb(t_list **lst_b, int check)
{
	t_list	*first;
	t_list	*current;
	t_list	*last;
	
	if (!lst_b || !*lst_b || !(*lst_b)->next)
		return ;
	first = *lst_b;
	current = *lst_b;
	while(current->next->next)
		current = current->next;
	last = current->next;
	last->next = first;
	current->next = NULL;
	*lst_b = last;
	if (check != 1)
		ft_printf("rrb\n");
}

void	ft_rrr(t_list **lst_a, t_list **lst_b)
{
	ft_rra(lst_a, 1);
	ft_rrb(lst_b, 1);
	ft_printf("rrr\n");
}
