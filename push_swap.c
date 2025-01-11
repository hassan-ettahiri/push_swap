/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hettahir <hettahir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 13:16:41 by hettahir          #+#    #+#             */
/*   Updated: 2025/01/07 19:06:50 by hettahir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	push_b_to_a(t_list **s1, t_list **s2)
{
	int	index_of_best_move;
	int	index_of_a;

	index_of_best_move = 0;
	index_of_a = 0;
	while (*s2)
	{
		index_array(s1);
		index_array(s2);
		reset_best_move(s2);
		count_move(*s1, s2);
		index_of_best_move = best_move_index(*s2);
		index_of_a = index_in_a(*s1, *s2, index_of_best_move);
		push_index_to_a(s1, s2, index_of_a, index_of_best_move);
	}
}

void	last_sort(t_list **stack1)
{
	int	min;

	index_array(stack1);
	if (!is_sorted(*stack1))
	{
		min = min_in_list(*stack1);
		if (get_index(*stack1, min) <= ft_lstsize(*stack1) / 2)
		{
			while (min != (*stack1)->content)
			{
				rotate(stack1);
				write(1, "ra\n", 3);
			}
		}
		else
		{
			while (min != (*stack1)->content)
			{
				reverse_rotate(stack1);
				write(1, "rra\n", 4);
			}
		}
	}
}

void	push_a_to_b(t_list **stack1, t_list **stack2, int size)
{
	int	i;

	i = 0;
	while (i < size - 3)
	{
		push(stack1, stack2);
		write(1, "pb\n", 3);
		i++;
	}
}

void	sort_lst(t_list **stack1, t_list **stack2)
{
	int	size;

	size = ft_lstsize(*stack1);
	if (size == 2)
	{
		if (!is_sorted(*stack1))
		{
			swap(stack1);
			write(1, "sa\n", 3);
		}
	}
	else if (size == 3)
		sort_lst_3(stack1);
	else
	{
		push_a_to_b(stack1, stack2, size);
		sort_lst_3(stack1);
		push_b_to_a(stack1, stack2);
		last_sort(stack1);
	}
}

int	main(int ac, char **av)
{
	t_list	*stack1;
	t_list	*stack2;

	stack2 = NULL;
	if (ac == 1)
		return (0);
	if (check_error(ac, av) == 1)
		return (write(2, "Error\n", 6), 0);
	stack1 = extract_data(ac, av);
	if (!stack1)
	{
		ft_lstclear(&stack1);
		ft_lstclear(&stack2);
		return (write(2, "Error\n", 6), 0);
	}
	if (is_sorted(stack1))
	{
		ft_lstclear(&stack1);
		ft_lstclear(&stack2);
		return (0);
	}
	sort_lst(&stack1, &stack2);
	ft_lstclear(&stack1);
	if (stack2 != NULL)
		ft_lstclear(&stack2);
}
