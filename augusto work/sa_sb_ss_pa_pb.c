/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa_sb_ss_pa_pb.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aude-la <aude-la@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 16:15:01 by aude-la           #+#    #+#             */
/*   Updated: 2026/11/05 12:15:42 by aude-la          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_lib.h"

void	ft_sa(t_list **lst_a)
{
	t_list	*first;
	t_list	*second;
	
	if (!lst_a || !*lst_a || !(*lst_a)->next)
		return ;
	first = *lst_a;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*lst_a = second;
	ft_printf("sa\n");
}

void	ft_sb(t_list **lst_b)
{
	t_list	*first;
	t_list	*second;
	
	if (!lst_b || !*lst_b || !(*lst_b)->next)
		return ;
	first = *lst_b;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*lst_b = second;
	ft_printf("sb\n");
}

void	ft_ss(t_list **lst_a, t_list **lst_b)
{
	t_list	*firsta;
	t_list	*seconda;
	t_list	*firstb;
	t_list	*secondb;
	
	if (!lst_a || !*lst_a || !(*lst_a)->next)
		return ;
	firsta = *lst_a;
	seconda = firsta->next;
	firsta->next = seconda->next;
	seconda->next = firsta;
	*lst_a = seconda;
	if (!lst_b || !*lst_b || !(*lst_b)->next)
		return ;
	firstb = *lst_b;
	secondb = firstb->next;
	firstb->next = secondb->next;
	secondb->next = firstb;
	*lst_b = secondb;
	ft_printf("ss\n");
}

void	ft_pa(t_list **lst_a, t_list **lst_b)
{
	t_list	*firstb;

	firstb = *lst_b;
	if (!lst_b || !*lst_b)
		return ;
	if (!lst_a || !*lst_a)
	{
		*lst_a = firstb;
		*lst_b = firstb->next;
		firstb->next = NULL;
	}
	else if (!firstb->next)
	{
		firstb->next = *lst_a;
		*lst_a = firstb;
		*lst_b = NULL;
	}
	else
	{
		*lst_b = firstb->next;
		firstb->next = *lst_a;
		*lst_a = firstb;
	}
	printf("pa\n");
}

void	ft_pb(t_list **lst_a, t_list **lst_b)
{
	t_list	*firsta;

	firsta = *lst_a;
	if (!lst_a || !*lst_a)
		return ;
	if (!lst_b || !*lst_b)
	{
		*lst_b = firsta;
		*lst_a = firsta->next;
		firsta->next = NULL;
	}
	else if (!firsta->next)
	{
		firsta->next = *lst_b;
		*lst_b = firsta;
		*lst_a = NULL;
	}
	else
	{
		*lst_a = firsta->next;
		firsta->next = *lst_b;
		*lst_b = firsta;
	}
	printf("pb\n");
}
