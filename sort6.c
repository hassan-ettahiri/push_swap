/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort6.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hettahir <hettahir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 13:17:09 by hettahir          #+#    #+#             */
/*   Updated: 2025/01/07 13:17:10 by hettahir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	type_of_moves(int demi1, int demi2, int c1, int c2)
{
	if (demi1 >= c1 && demi2 >= c2)
		return (1);
	else if (demi1 <= c1 && demi2 <= c2)
		return (2);
	else if (demi1 >= c1 && demi2 <= c2)
	{
		if (c1 >= c2)
			return (1);
		else if (demi2 - c2 >= demi1 - c1)
			return (2);
		else
			return (3);
	}
	else
	{
		if (c2 >= c1)
			return (1);
		else if (demi1 - c1 >= demi2 - c2)
			return (2);
		else
			return (4);
	}
}

void	two_up(t_list **s1, t_list **s2, int indexa, int indexb)
{
	while ((*s1)->index != indexa && (*s2)->index != indexb)
	{
		rr(s1, s2);
		write(1, "rr\n", 3);
	}
	while ((*s1)->index != indexa)
	{
		rotate(s1);
		write(1, "ra\n", 3);
	}
	while ((*s2)->index != indexb)
	{
		rotate(s2);
		write(1, "rb\n", 3);
	}
}

void	two_down(t_list **s1, t_list **s2, int indexa, int indexb)
{
	while ((*s1)->index != indexa && (*s2)->index != indexb)
	{
		rrr(s1, s2);
		write(1, "rrr\n", 4);
	}
	while ((*s1)->index != indexa)
	{
		reverse_rotate(s1);
		write(1, "rra\n", 4);
	}
	while ((*s2)->index != indexb)
	{
		reverse_rotate(s2);
		write(1, "rrb\n", 4);
	}
}

void	up_and_down(t_list **s1, t_list **s2, int indexa, int indexb)
{
	while ((*s1)->index != indexa)
	{
		rotate(s1);
		write(1, "ra\n", 3);
	}
	while ((*s2)->index != indexb)
	{
		reverse_rotate(s2);
		write(1, "rrb\n", 4);
	}
}

void	down_and_up(t_list **s1, t_list **s2, int indexa, int indexb)
{
	while ((*s1)->index != indexa)
	{
		reverse_rotate(s1);
		write(1, "rra\n", 4);
	}
	while ((*s2)->index != indexb)
	{
		rotate(s2);
		write(1, "rb\n", 3);
	}
}
