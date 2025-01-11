/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hettahir <hettahir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 13:17:04 by hettahir          #+#    #+#             */
/*   Updated: 2025/01/07 13:17:05 by hettahir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_moves(t_list *s1, t_list *s2, int c1, int c2)
{
	if (ft_lstsize(s1) / 2 >= c1 && ft_lstsize(s2) / 2 >= c2)
		return (max(c1, c2) + 1);
	else if (ft_lstsize(s1) / 2 <= c1 && ft_lstsize(s2) / 2 <= c2)
		return (max(ft_lstsize(s1) - c1, ft_lstsize(s2) - c2) + 1);
	else if (ft_lstsize(s1) / 2 >= c1 && ft_lstsize(s2) / 2 <= c2)
	{
		if (c1 >= c2)
			return (c1 + 1);
		else if (ft_lstsize(s2) - c2 >= ft_lstsize(s1) - c1)
			return (ft_lstsize(s2) - c2 + 1);
		else
			return (c1 + (ft_lstsize(s2) - c2) + 1);
	}
	else
	{
		if (c2 >= c1)
			return (c2 + 1);
		else if (ft_lstsize(s1) - c1 >= ft_lstsize(s2) - c2)
			return (ft_lstsize(s1) - c1 + 1);
		else
			return (c2 + (ft_lstsize(s1) - c1) + 1);
	}
}

void	handle_min_case(t_list *s1, t_list **s2, t_list *t2, int counter2)
{
	t_list	*t1;
	int		counter1;

	t1 = s1;
	counter1 = 0;
	while (t1)
	{
		if (min_in_list(s1) == t1->content)
		{
			t2->best_mv = check_moves(s1, *s2, counter1, counter2);
			break ;
		}
		counter1++;
		t1 = t1->next;
	}
}

void	handle_normal_case(t_list *s1, t_list **s2, t_list *t2, int counter2)
{
	t_list	*t1;
	int		counter1;

	t1 = s1;
	counter1 = 0;
	while (t1->next)
	{
		if (t1->content < t2->content && t1->next->content > t2->content)
		{
			t2->best_mv = check_moves(s1, *s2, ++counter1, counter2);
			break ;
		}
		counter1++;
		t1 = t1->next;
	}
}

void	handle_first_case(t_list *s1, t_list **s2, t_list *t2, t_list *last)
{
	if (s1->content > t2->content && last->content < t2->content)
	{
		if (ft_lstsize(*s2) / 2 > t2->index)
			t2->best_mv = ft_lstsize(*s2) - t2->index + 1;
		else
			t2->best_mv = t2->index + 1;
	}
}

void	count_move(t_list *s1, t_list **s2)
{
	t_list	*t2;
	t_list	*last;
	int		counter2;
	int		max;

	t2 = *s2;
	counter2 = 0;
	last = s1;
	max = max_in_list(s1);
	while (last->next)
		last = last->next;
	while (t2)
	{
		if (max < t2->content || min_in_list(s1) > t2->content)
			handle_min_case(s1, s2, t2, counter2);
		else if (s1->content > t2->content && last->content < t2->content)
			handle_first_case(s1, s2, t2, last);
		else
			handle_normal_case(s1, s2, t2, counter2);
		counter2++;
		t2 = t2->next;
	}
}
