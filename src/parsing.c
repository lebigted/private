/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltestard <ltestard@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 12:55:19 by tdelgran          #+#    #+#             */
/*   Updated: 2023/07/31 19:51:35 by ltestard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

size_t	ft_strlen(const char *str)
{
	size_t i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_free_str(char **str)
{
	int	i;

	if (!str)
		return ;
	i = 0;
	while (str[i])
	{
		free(str[i]); // libère chaque chaîne de caractères individuelle
		i++;
	}
	free(str); // libère le tableau lui-même
}

int	is_number(char *str)
{
	int	i;

	if (str[0] == '+' || str[0] == '-')
		i = 1;
	else
		i = 0;
	while (str[i])
		if (!ft_isdigit(str[i++]))
			return (0);
	return (1);
}

int	is_duplicate(t_list *lst, int data)
{
	while (lst)
		if (lst->data == data)
			return (1);
		else
			lst = lst->next;
	return (0);
}

void	print_error_and_clear(t_list **lst, char *message)
{
	ft_lstclear(lst);
	ft_putendl_fd(message, 2);
}

static void	handle_error(t_list **lst, char ***numbers, char *msg)
{
	print_error_and_clear(lst, msg);
	ft_free_str(*numbers); 
}

t_list	*parse_args(int argc, char **argv)
{
	t_list	*lst;
	int		i;
	int		data;
	char	**numbers;
	int		j;

	lst = NULL;
	i = 1;
	while (i < argc && (numbers = ft_split(argv[i], ' ')))
	{
		j = 0;
		while (numbers[j])
		{
			if (!is_number(numbers[j]))
				return (handle_error(&lst, &numbers, "Error: Non-number argument"), NULL);
			data = ft_atoi(numbers[j]);
			if (is_duplicate(lst, data))
				return (handle_error(&lst, &numbers, "Error: Duplicate numbers not allowed"), NULL);
			add_back(&lst, data);
			j++;
		}
		ft_free_str(numbers);
		i++;
	}
	return (lst);
}










