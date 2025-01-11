/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort7.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hettahir <hettahir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 13:17:12 by hettahir          #+#    #+#             */
/*   Updated: 2025/01/07 13:17:13 by hettahir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_index_to_a(t_list **s1, t_list **s2, int indexa, int indexb)
{
	int	type;

	type = type_of_moves(ft_lstsize(*s1) / 2, ft_lstsize(*s2) / 2,
			indexa, indexb);
	if (type == 1)
		two_up(s1, s2, indexa, indexb);
	else if (type == 2)
		two_down(s1, s2, indexa, indexb);
	else if (type == 3)
		up_and_down(s1, s2, indexa, indexb);
	else if (type == 4)
		down_and_up(s1, s2, indexa, indexb);
	push(s2, s1);
	write(1, "pa\n", 3);
}

int	get_index(t_list *s, int nb)
{
	while (s)
	{
		if (s->content == nb)
		{
			return (s->index);
		}
		s = s->next;
	}
	return (0);
}
