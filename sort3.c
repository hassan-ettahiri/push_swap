/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hettahir <hettahir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 13:17:01 by hettahir          #+#    #+#             */
/*   Updated: 2025/01/07 13:17:02 by hettahir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_list *s)
{
	t_list	*tmp;

	tmp = s;
	while (tmp->next)
	{
		if (tmp->content > tmp->next->content)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	max_in_list(t_list *s1)
{
	int		max;
	t_list	*t;

	max = s1->content;
	t = s1;
	while (t)
	{
		if (t->content > max)
		{
			max = t->content;
		}
		t = t->next;
	}
	return (max);
}

void	sort_lst_3(t_list **a)
{
	int	max;

	max = max_in_list(*a);
	if ((*a)->content == max)
	{
		rotate(a);
		write(1, "ra\n", 3);
	}
	else if ((*a)->next->content == max)
	{
		reverse_rotate(a);
		write(1, "rra\n", 4);
	}
	if ((*a)->content > (*a)->next->content)
	{
		swap(a);
		write(1, "sa\n", 3);
	}
}

void	reset_best_move(t_list **s)
{
	t_list	*tmp;

	tmp = *s;
	while (tmp)
	{
		tmp->best_mv = 0;
		tmp = tmp->next;
	}
}

int	max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}
