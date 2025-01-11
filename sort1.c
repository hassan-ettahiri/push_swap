/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hettahir <hettahir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 13:16:54 by hettahir          #+#    #+#             */
/*   Updated: 2025/01/07 13:16:55 by hettahir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_dup(t_list *lst, int c)
{
	t_list	*tmp;

	tmp = lst;
	if (lst == NULL)
		return (0);
	while (tmp)
	{
		if (tmp->content == c)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int	is_digit(char **str)
{
	int	flag;

	flag = 0;
	if (**str == '+' || **str == '-')
		(*str)++;
	while (**str && **str != ' ')
	{
		if (!(**str >= '0' && **str <= '9'))
			return (0);
		(*str)++;
		flag = 1;
	}
	if (flag == 0)
		return (0);
	return (1);
}

int	check_param(char *str)
{
	int	check;
	int	flag;

	flag = 0;
	while (*str)
	{
		while (*str && *str == ' ')
			str++;
		if (*str == '\0')
			break ;
		check = is_digit(&str);
		if (check == 0)
			return (1);
		else
			flag = 1;
	}
	if (flag == 0)
		return (1);
	return (0);
}

int	check_error(int ac, char **av)
{
	int	i;

	i = 1;
	if (ac == 1)
		return (1);
	if (ac > 1)
	{
		while (i < ac)
		{
			if (check_param(av[i]) == 1)
				return (1);
			else
				i++;
		}
	}
	return (0);
}

int	check_dup_and_max_int(t_list *lst, char *str)
{
	t_list	*tmp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] && str[i] == '0')
		i++;
	while (str[i + j])
		j++;
	if (((str[0] == '-' || str[0] == '+') && j > 11) || j > 10)
		return (1);
	if (!(ft_atoi(str) >= -2147483648 && ft_atoi(str) <= 2147483647))
		return (1);
	tmp = lst;
	while (tmp)
	{
		if (tmp->content == ft_atoi(str))
			return (1);
		tmp = tmp->next;
	}
	return (0);
}
