/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hettahir <hettahir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 13:16:48 by hettahir          #+#    #+#             */
/*   Updated: 2025/01/07 13:16:49 by hettahir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list **s1)
{
	int	c;

	if (!*s1 || !(*s1)->next)
		return ;
	c = (*s1)->next->content;
	(*s1)->next->content = (*s1)->content;
	(*s1)->content = c;
}

void	ss(t_list **s1, t_list **s2)
{
	swap(s1);
	swap(s2);
}

void	push(t_list **s1, t_list **s2)
{
	t_list	*new;
	t_list	*del;

	if (*s1 == NULL || s1 == NULL)
		return ;
	del = *s1;
	new = ft_lstnew((*s1)->content);
	ft_lstadd_front(s2, new);
	*s1 = (*s1)->next;
	free(del);
}

void	rotate(t_list **s1)
{
	t_list	*first;
	t_list	*last;

	if (!*s1 || !(*s1)->next)
		return ;
	first = *s1;
	*s1 = first->next;
	first->next = NULL;
	last = *s1;
	while (last->next)
		last = last->next;
	last->next = first;
}

void	rr(t_list **s1, t_list **s2)
{
	rotate(s1);
	rotate(s2);
}
