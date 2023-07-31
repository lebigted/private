/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdelgran <tdelgran@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 14:08:49 by tdelgran          #+#    #+#             */
/*   Updated: 2023/07/12 08:57:50 by tdelgran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_list	*ft_lstnew(int n)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->data = n;
	new->next = NULL;
	return (new);
}

void	add_front(t_list **lst, int content)
{
    t_list	*new;

    new = ft_lstnew(content);
    if (*lst)
        new->next = *lst;
    *lst = new;
}

void	add_back(t_list **lst, int content)
{
    t_list	*new;
    t_list	*tmp;

    new = ft_lstnew(content);
    if (!*lst)
    {
        *lst = new;
        return;
    }
    tmp = *lst;
    while (tmp->next)
        tmp = tmp->next;
    tmp->next = new;
}

