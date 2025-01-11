/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hettahir <hettahir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 13:15:38 by hettahir          #+#    #+#             */
/*   Updated: 2025/01/07 16:31:16 by hettahir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_free(char ***strs, int i)
{
	while (i >= 0)
		free((*strs)[i--]);
	free(*strs);
}

int	add_to_stack(t_list **lst, char *str)
{
	char	**split;
	int		j;
	t_list	*new;

	split = ft_split(str, ' ');
	j = 0;
	while (split[j])
	{
		if (check_dup_and_max_int(*lst, split[j]) == 1)
			return (ft_free(&split, j), 0);
		new = ft_lstnew(ft_atoi(split[j]));
		if (new == NULL)
			return (ft_free(&split, j), 0);
		ft_lstadd_back(lst, new);
		j++;
	}
	return (ft_free(&split, j), 1);
}

t_list	*extract_data(int ac, char **av)
{
	t_list	*lst;
	int		i;
	int		j;

	lst = NULL;
	i = 1;
	while (i < ac)
	{
		j = add_to_stack(&lst, av[i]);
		if (j == 0)
			return (NULL);
		i++;
	}
	return (lst);
}

int	conditions(t_list **s1, t_list **s2, char *s)
{
	if (ft_strncmp("sa\n", s, 3) == 0)
		return (swap(s1), 0);
	else if (ft_strncmp("sb\n", s, 3) == 0)
		return (swap(s2), 0);
	else if (ft_strncmp("ra\n", s, 3) == 0)
		return (rotate(s1), 0);
	else if (ft_strncmp("rb\n", s, 3) == 0)
		return (rotate(s2), 0);
	else if (ft_strncmp("rr\n", s, 3) == 0)
		return (rr(s1, s2), 0);
	else if (ft_strncmp("rra\n", s, 4) == 0)
		return (reverse_rotate(s1), 0);
	else if (ft_strncmp("rrb\n", s, 4) == 0)
		return (reverse_rotate(s2), 0);
	else if (ft_strncmp("rrr\n", s, 4) == 0)
		return (rrr(s1, s2), 0);
	else if (ft_strncmp("pb\n", s, 3) == 0)
		return (push(s1, s2), 0);
	else if (ft_strncmp("pa\n", s, 3) == 0)
		return (push(s2, s1), 0);
	else
		return (write(2, "Error\n", 6), 1);
}

int	moves(t_list **s1, t_list **s2)
{
	char	*s;
	int		d;

	s = get_next_line(0);
	while (s)
	{
		d = conditions(s1, s2, s);
		if (d == 1)
			return (1);
		free(s);
		s = get_next_line(0);
	}
	return (0);
}
