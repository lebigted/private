/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltestard <ltestard@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 10:11:45 by tdelgran          #+#    #+#             */
/*   Updated: 2023/07/31 20:14:50 by ltestard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	get_max_bits(t_list **stack)
{
	t_list	*head;
	int		max;
	int		max_bits;

	head = *stack;
	max = head->data;
	max_bits = 0;
	while (head)
	{
		if (head->data > max)
			max = head->data;
		head = head->next;
	}
	while ((max >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

void	radix_sort(t_list **stack_a, t_list **stack_b)
{
	int		i;
	int		j;
	int		size;
	int		max_bits;

	i = 0;
	size = ft_lstsize(*stack_a);
	max_bits = get_max_bits(stack_a);
	while (i < max_bits)
	{
		j = 0;
		while (j++ < size)
		{
			if ((((*stack_a)->data >> i) & 1) == 0)
				ft_pb(stack_a, stack_b);
			else
				ft_ra(stack_a);
		}
		while (*stack_b)
			ft_pa(stack_a, stack_b);
		i++;
	}
	print_stack(*stack_a);
}



