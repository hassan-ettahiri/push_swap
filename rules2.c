/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hettahir <hettahir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 13:16:51 by hettahir          #+#    #+#             */
/*   Updated: 2025/01/07 13:16:52 by hettahir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(t_list **s1)
{
	t_list	*second_last;
	t_list	*last;

	if (!*s1 || !(*s1)->next)
		return ;
	second_last = *s1;
	while (second_last->next->next)
		second_last = second_last->next;
	last = second_last->next;
	second_last->next = NULL;
	last->next = *s1;
	*s1 = last;
}

void	rrr(t_list **s1, t_list **s2)
{
	reverse_rotate(s1);
	reverse_rotate(s2);
}
