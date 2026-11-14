/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgencogl <mgencogl@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 13:10:43 by mgencogl          #+#    #+#             */
/*   Updated: 2026/11/06 17:40:30 by mgencogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_lib.h"

void	del(void *content)
{
	free(content);
}

void	dispatch_strategy(t_list **a, t_list **b, t_rec *specs)
{
	if (specs.strategy == 1)
		sort_adaptive(a, b, specs);
	else if (specs.strategy == 2)
		sort_simple(a, b, specs);
	else if (specs.strategy == 3)
		sort_medium(a, b, specs);
	else if (specs.strategy == 4)
		sort_complex(a, b, specs);
}

float	compute_disorder(t_list *a, int listlen)
{
	t_list *curr;
	t_list *next;
	float	mistakes;
	float	total_pairs;

	mistakes = 0;
	total_pairs = (listlen * (listlen - 1) / 2);
	curr = a;
	if(!a || listlen < 2)
		return (0);
	while (curr)
	{
		next = curr.next;
		while (next)
			{
				if (*(int *)(curr.content) > *(int *)(next.content))
					mistakes++;
				next = next.next;
			}
		curr = curr.next;
	}
	return (mistakes / total_pairs);
}

int	main(int argc, char **argv)
{
	t_rec	specs;
	t_list	*a;
	t_list	*b;
	
	a = NULL;
	b = NULL;
	if(argc < 2)
		return (0);
	ft_bzero(&specs, sizeof(t_rec));
	input_parser(argv, argc, &specs, &a);
	if (specs.error_exists)
	{
		write(2, "Error\n", 6); //write.specs.error_message?
		ft_lstclear(&a, del);
		return (1);
	}
	specs.disorder = compute_disorder(a, specs.token_len);
	if(specs.token_len > 1 && specs.disorder > 0)
		dispatch_strategy(&a, &b, &specs);
	if (specs.bench_exists)
		print_benchtab(specs);
	ft_lstclear(&a, del);
	ft_lstclear(&b, del);
	return (0);
}
// void	mode_recorder(char *str, t_rec *ddash, int *err);

// void	list_recorder(char *str, t_list *a, int *err);

// int	ft_memcmp(const void *s1, const void *s2, size_t n)
// {
// 	const unsigned char	*ptr1;
// 	const unsigned char	*ptr2;
// 	size_t				i;

// 	ptr1 = (const unsigned char *)s1;
// 	ptr2 = (const unsigned char *)s2;
// 	i = 0;
// 	while (i < n)
// 	{
// 		if (ptr1[i] != ptr2[i])
// 			return (ptr1[i] - ptr2[i]);
// 		i++;
// 	}
// 	return (0);
// }

// t_list	*ft_lstnew(void *content)
// {
// 	t_list	*newnode;

// 	newnode = malloc(sizeof(t_list));
// 	if (!newnode)
// 		return (NULL);
// 	newnode->content = content;
// 	newnode->next = NULL;
// 	return (newnode);
// }

// void	ft_lstadd_back(t_list **lst, t_list *new)
// {
// 	t_list	*last;

// 	if (!lst || !new)
// 		return ;
// 	if (*lst == NULL)
// 	{
// 		*lst = new;
// 		return ;
// 	}
// 	last = ft_lstlast(*lst);
// 	last->next = new;
// }

// t_list	*ft_lstlast(t_list	*lst)
// {
// 	if (!lst)
// 		return (NULL);
// 	while (lst->next)
// 	{
// 		lst = lst->next;
// 	}
// 	return (lst);
// }

