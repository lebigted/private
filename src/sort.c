/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theodelgrange <theodelgrange@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 09:40:20 by tdelgran          #+#    #+#             */
/*   Updated: 2023/07/28 16:36:52 by theodelgran      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_list	*sort_2(t_list *stack)
{
	if ((stack)->data > (stack)->next->data)
		ft_sa(&stack);
	return (stack);
}

int	sort_3_brut(t_list *stack)
{
	int a;
	int b;
	int c;

	a = stack->data;
	b = stack->next->data;
	c = stack->next->next->data;
	if (a < b && a > c)
		return (1);
	else if (a < b && a < c)
		return (2);
	else if (a > b && a > c)
		return (3);
	else if (a > b && b > c)
		return (4);
	else if (a > b && a < c)
		return (5);
	else
		return (0);
}

t_list	*sort_3(t_list *stack)
{	
	if (sort_3_brut(stack) == 1)
		ft_rra(&stack);
	else if (sort_3_brut(stack) ==  2)
	{
		ft_sa(&stack);
		ft_ra(&stack);
	}
	else if (sort_3_brut(stack) ==  3)
		ft_ra(&stack);
	else if (sort_3_brut(stack) ==  4)
	{
		ft_sa(&stack);
		ft_rra(&stack);
	}
	else if (sort_3_brut(stack) ==  5)
		ft_sa(&stack);
	return (stack);
}
