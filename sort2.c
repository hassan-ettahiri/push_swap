/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hettahir <hettahir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 13:16:57 by hettahir          #+#    #+#             */
/*   Updated: 2025/01/07 13:16:58 by hettahir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

	new = NULL;
	split = ft_split(str, ' ');
	j = 0;
	while (split[j])
	{
		if (check_dup_and_max_int(*lst, split[j]) == 1)
			return (ft_lstclear(lst), ft_free(&split, j), 0);
		new = ft_lstnew(ft_atoi(split[j]));
		if (new == NULL)
			return (ft_lstclear(lst), ft_free(&split, j), 0);
		ft_lstadd_back(lst, new);
		new = NULL;
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

void	index_array(t_list **s)
{
	t_list	*tmp;
	int		i;

	tmp = *s;
	i = 0;
	while (tmp)
	{
		tmp->index = i;
		i++;
		tmp = tmp->next;
	}
}

int	best_move_index(t_list *s)
{
	int		min;
	int		index;
	t_list	*tmp;

	min = s->best_mv;
	index = s->index;
	tmp = s->next;
	while (tmp)
	{
		if (tmp->flag == 0)
		{
			if (tmp->best_mv <= min)
			{
				min = tmp->best_mv;
				index = tmp->index;
			}
		}
		tmp = tmp->next;
	}
	return (index);
}
