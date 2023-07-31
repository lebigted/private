/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltestard <ltestard@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 15:55:35 by theodelgran       #+#    #+#             */
/*   Updated: 2023/07/31 20:00:11 by ltestard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	find_min(t_list **stack_a, t_list **min, int *min_index)
{
	t_list	*tmp;
	int		index;

	tmp = *stack_a;
	*min = tmp;
	*min_index = 0;
	index = 0;
	while (tmp)
	{
		if (tmp->data < (*min)->data)
		{
			*min = tmp;
			*min_index = index;
		}
		tmp = tmp->next;
		index++;
	}
}

void	rotate_to_min(t_list **stack_a, t_list *min, int min_index)
{
	if (min_index > ft_lstsize(*stack_a) / 2)
		while ((*stack_a) != min)
			ft_rra(stack_a);
	else
		while ((*stack_a) != min)
			ft_ra(stack_a);
}

void    push_min(t_list **stack_a, t_list **stack_b, int n)
{
	t_list	*min;
	int		min_index;

	while (n--)
	{
		find_min(stack_a, &min, &min_index);
		rotate_to_min(stack_a, min, min_index);
		ft_pb(stack_a, stack_b);
	}
}
t_list	*sort_4(t_list *stack_a, t_list *stack_b)
{
	if (sort_invers(&stack_a) == 0)
		verif_pile(&stack_a);
	else
		push_min(&stack_a, &stack_b, 1);
	stack_a = sort_3(stack_a);
	ft_pa(&stack_a, &stack_b);
	return (stack_a);
}