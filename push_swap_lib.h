/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_lib.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgencogl <mgencogl@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/08 12:27:18 by aude-la           #+#    #+#             */
/*   Updated: 2026/11/10 16:16:06 by mgencogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_LIB_H
# define PUSH_SWAP_LIB_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include <stdarg.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;


typedef	struct s_mode_recorder
/*benchexists is boolean, 0 false, 1 true*/
/*strategy is default(or adaptive) = 1 
others with ascending complexity 2,3,4*/
/*error_exists is boolean*/
{
	char *error_message;
	int	bench_exists;
	int	strategy;
	int error_exists;
	int token_len;
	float disorder;
}	t_rec;

size_t		ft_strlen(char const	*s);
t_list		*ft_lstnew(void *content);
void		ft_lstadd_back(t_list **lst, t_list *new);
void		ft_lstdelone(t_list *lst, void (*del)(void*));
void		ft_lstclear(t_list **lst, void (*del)(void *));
int			print_c(char c);
int			print_s(char *s);
int			print_di(int n);
int			print_u(unsigned int n);
int			print_x(unsigned long long n, char *base);
int			print_p(unsigned long n, char *base);
int			ft_printf(const char *input, ...);
int			ft_triage(int c, va_list arglst);

void		ft_sa(t_list **lst_a);
void		ft_sb(t_list **lst_b);
void		ft_ss(t_list **lst_a, t_list **lst_b);
void		ft_pa(t_list **lst_a, t_list **lst_b);
void		ft_pb(t_list **lst_a, t_list **lst_b);
void		ft_ra(t_list **lst_a, int check);
void		ft_rb(t_list **lst_b, int check);
void		ft_rr(t_list **lst_a, t_list **lst_b);
void		ft_rra(t_list **lst_a, int	check);
void		ft_rrb(t_list **lst_b, int check);
void		ft_rrr(t_list **lst_a, t_list **lst_b);

#endif