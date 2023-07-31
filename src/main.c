/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltestard <ltestard@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 14:15:16 by tdelgran          #+#    #+#             */
/*   Updated: 2023/07/31 20:04:02 by ltestard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include <stdio.h>
void	print_stack(t_list *stack)
{
	while (stack)
	{
		printf("%d\n", stack->data);
		stack = stack->next;
	}
}

int	is_sort(t_list *stack_a)
{
	if (!stack_a || !stack_a->next)
		return (1);
	if (stack_a->data > stack_a->next->data)
		return (0);
	return (is_sort(stack_a->next));
}

void	check(t_list *stack_a, t_list *stack_b)
{
	int i;

	i = ft_lstsize(stack_a);
	if (is_sort(stack_a))
		return ;
	if (i == 2)
		stack_a = sort_2(stack_a);
	else if (i == 3)
		stack_a = sort_3(stack_a);
	else if (i == 4)
		stack_a = sort_4(stack_a, stack_b);
	else if (i == 5)
		stack_a = sort_5(stack_a, stack_b);
	else
	 	radix_sort(&stack_a, &stack_b);
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	
	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		return (0);
	stack_a = parse_args(argc, argv);
	check(stack_a, stack_b);
	//system("leaks push_swap");
    return (0);
}



