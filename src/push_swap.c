/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theodelgrange <theodelgrange@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 12:53:20 by tdelgran          #+#    #+#             */
/*   Updated: 2023/07/28 17:32:51 by theodelgran      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_sa(t_list **stack)
{
	int	temp;
	
	temp = (*stack)->data;
	if (*stack && (*stack)->next)
	{
		(*stack)->data = (*stack)->next->data;
		(*stack)->next->data = temp;
		ft_putstr_fd("sa\n", 1);
	}
}

void	ft_pa(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp;
	
	if (*stack_b)
	{
		temp = *stack_b;
		*stack_b = (*stack_b)->next;
		temp->next = *stack_a;
		*stack_a = temp;
		ft_putstr_fd("pa\n", 1);
	}
}

void	ft_ra(t_list **stack)
{
	t_list	*last;
	t_list	*temp;

	if (!(*stack) || !(*stack)->next)
		return ;
	last = *stack;
	temp = last->next;
	while (last->next)
		last = last->next;
	last->next = *stack;
	*stack = temp;
	last->next->next = NULL;
	ft_putstr_fd("ra\n", 1);
}

void    ft_rra(t_list **stack)
{
	t_list	*temp;
	int		i;

	i = 0;
	if (!(*stack) || !(*stack)->next)
		return ;
	temp = *stack;
	while ((*stack)->next)
	{
		*stack = (*stack)->next;
		i++;
	}
	(*stack)->next = temp;
	while (i > 1)
	{
		temp = temp->next;
		i--;
	}
	temp->next = NULL;
	ft_putstr_fd("rra\n", 1);
}

void	ft_pb(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp;
	
	if (*stack_a)
	{
		temp = *stack_a;
		*stack_a = (*stack_a)->next;
		temp->next = *stack_b;
		*stack_b = temp;
		ft_putstr_fd("pb\n", 1);
	}
}
