/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltestard <ltestard@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 17:36:10 by theodelgran       #+#    #+#             */
/*   Updated: 2023/07/31 20:03:35 by ltestard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	sort_invers(t_list **stack_a)
{
	t_list	*tmp;
	int		i;

	tmp = *stack_a;
	i = 0;
	while (tmp->next != NULL)
	{
		if (tmp->data < tmp->next->data)
			i++;
		else
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int	is_reverse_sorted(t_list **stack_a)
{
	t_list	*tmp;

	tmp = *stack_a;
	while (tmp->next != NULL)
	{
		if (tmp->data <= tmp->next->data)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void	verif_pile(t_list **stack_a)
{
	t_list	*prev;
	t_list	*last;

	last = *stack_a;
	prev = NULL;
	if (is_reverse_sorted(stack_a))
	{
		while (last->next != NULL)
		{
			prev = last;
			last = last->next;
		}
		prev->next = NULL;
		last->next = *stack_a;
		*stack_a = last;
	}
}

t_list	*sort_5(t_list *stack_a, t_list *stack_b)
{
	int	i;

	i = 0;
	if (sort_invers(&stack_a) == 0)
		verif_pile(&stack_a);
	else
        push_min(&stack_a, &stack_b, 2);
	stack_a = sort_3(stack_a);
	while (i < 2)
	{
		ft_pa(&stack_a, &stack_b);
		i++;
	}
    print_stack(stack_a);
	return (stack_a);
}
