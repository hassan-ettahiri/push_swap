/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hettahir <hettahir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 13:16:00 by hettahir          #+#    #+#             */
/*   Updated: 2025/01/07 16:29:42 by hettahir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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
		return (ft_lstclear(&stack1), write(2, "Error\n", 6), 0);
	if (moves(&stack1, &stack2) == 1)
		return (ft_lstclear(&stack1), 0);
	if (is_sorted(stack1) && stack2 == NULL)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	ft_lstclear(&stack1);
	if (stack2 == NULL)
		ft_lstclear(&stack2);
	return (0);
}
