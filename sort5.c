/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort5.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hettahir <hettahir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 13:17:07 by hettahir          #+#    #+#             */
/*   Updated: 2025/01/07 13:17:08 by hettahir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	min_in_list(t_list *s1)
{
	int		min;
	t_list	*t;

	min = s1->content;
	t = s1;
	while (t)
	{
		if (t->content < min)
		{
			min = t->content;
		}
		t = t->next;
	}
	return (min);
}

t_list	*find_target_node(t_list *s2, int index)
{
	while (s2)
	{
		if (index == s2->index)
			return (s2);
		s2 = s2->next;
	}
	return (NULL);
}

int	handle_min_case_a(t_list *s1)
{
	while (s1)
	{
		if (min_in_list(s1) == s1->content)
			return (s1->index);
		s1 = s1->next;
	}
	return (-1);
}

int	handle_normal_case_a(t_list *s1, t_list *t2)
{
	while (s1->next)
	{
		if (t2->content > s1->content && t2->content < s1->next->content)
			return (s1->next->index);
		s1 = s1->next;
	}
	return (s1->index);
}

int	index_in_a(t_list *s1, t_list *s2, int index)
{
	t_list	*t2;
	t_list	*last;
	int		max;

	t2 = find_target_node(s2, index);
	if (!t2)
		return (-1);
	max = max_in_list(s1);
	last = s1;
	while (last->next)
		last = last->next;
	if (s1->content > t2->content && last->content < t2->content)
		return (s1->index);
	else if (max < t2->content || min_in_list(s1) > t2->content)
		return (handle_min_case_a(s1));
	else
		return (handle_normal_case_a(s1, t2));
}
