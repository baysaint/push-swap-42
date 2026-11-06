/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra_rb_rr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aude-la <aude-la@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 16:15:01 by aude-la           #+#    #+#             */
/*   Updated: 2026/11/05 12:15:38 by aude-la          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_lib.h"

void	ft_ra(t_list **lst_a, int check)
{
	t_list	*first;
	t_list	*second;
	t_list	*current;
	
	if (!lst_a || !*lst_a || !(*lst_a)->next)
		return ;
	first = *lst_a;
	second = first->next;
	current = *lst_a;
	while(current->next)
		current = current->next;
	current->next = first;
	first->next = NULL;
	*lst_a = second;
	if (check != 1)
		ft_printf("ra\n");
}

void	ft_rb(t_list **lst_b, int check)
{
	t_list	*first;
	t_list	*second;
	t_list	*current;
	
	if (!lst_b || !*lst_b || !(*lst_b)->next)
		return ;
	first = *lst_b;
	second = first->next;
	current = *lst_b;
	while(current->next)
		current = current->next;
	current->next = first;
	first->next = NULL;
	*lst_b = second;
	if (check != 1)
		ft_printf("rb\n");
}

void	ft_rr(t_list **lst_a, t_list **lst_b)
{
	ft_ra(lst_a, 1);
	ft_rb(lst_b, 1);
	ft_printf("rr\n");
}
