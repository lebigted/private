/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltestard <ltestard@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 12:55:38 by tdelgran          #+#    #+#             */
/*   Updated: 2023/07/31 20:11:04 by ltestard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef	struct	s_list
{
	int				data;
	struct s_list	*next;
	int				index;
	
}				t_list;

/*FONCTIONS*/
void	add_front(t_list **lst, int content);
void	add_back(t_list **lst, int content);
t_list	*ft_lstnew(int n);
t_list	*parse_args(int argc, char **argv);
void	ft_sa(t_list **stack);
void	ft_pa(t_list **stack_a, t_list **stack_b);
void	ft_ra(t_list **stack);
void	ft_rra(t_list **stack);
void	ft_pb(t_list **stack_a, t_list **stack_b);
void	ft_lstclear(t_list **lst);
void	radix_sort(t_list **stack_a, t_list **stack_b);
void	print_stack(t_list *stack);

/*TRI*/
t_list	*sort_2(t_list *stack);
t_list	*sort_3(t_list *stack);
t_list  *sort_4(t_list *stack_a, t_list *stack_b);
t_list  *sort_5(t_list *stack_a, t_list *stack_b);
void	radix_sort(t_list **stack_a, t_list **stack_b);
void    push_min(t_list **stack_a, t_list **stack_b, int n);
void	find_min(t_list **stack_a, t_list **min, int *min_index);
void	verif_pile(t_list **stack_a);
int		sort_invers(t_list **stack_a);

/*FONCTIONS UTILS*/
int	ft_atoi(const char *str);
int	ft_isdigit(int c);
void	ft_putendl_fd(char *s, int fd);
int	ft_lstsize(t_list *lst);
void	ft_putstr_fd(char *s, int fd);
char	**ft_split(char const *s, char c);
size_t	ft_strlen(const char *str);

#endif