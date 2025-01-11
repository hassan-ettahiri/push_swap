/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hettahir <hettahir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 13:16:45 by hettahir          #+#    #+#             */
/*   Updated: 2025/01/07 13:16:46 by hettahir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int				content;
	int				index;
	int				flag;
	int				best_mv;
	struct s_list	*next;
}	t_list;

size_t	ft_strlen(const char *s);
int		ft_isdigit(int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
long	ft_atoi(const char *s);
t_list	*ft_lstnew(int content);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstclear(t_list **lst);
char	**ft_split(char const *s, char c);
void	swap(t_list **s1);
void	ss(t_list **s1, t_list **s2);
void	push(t_list **s1, t_list **s2);
void	rotate(t_list **s1);
void	rr(t_list **s1, t_list **s2);
void	reverse_rotate(t_list **s1);
void	rrr(t_list **s1, t_list **s2);
int		ft_lstsize(t_list *lst);

void	index_array(t_list **s);
int		check_dup(t_list *lst, int c);
int		is_digit(char **str);
int		check_param(char *str);
int		check_error(int ac, char **av);
int		check_dup_and_max_int(t_list *lst, char *str);
int		add_to_stack(t_list **lst, char *str);
t_list	*extract_data(int ac, char **av);
int		best_move_index(t_list *s);
int		is_sorted(t_list *s);
int		max_in_list(t_list *s1);
void	sort_lst_3(t_list **a);
void	reset_best_move(t_list **s);
int		max(int a, int b);
int		check_moves(t_list *s1, t_list *s2, int c1, int c2);
int		min_in_list(t_list *s1);
void	handle_min_case(t_list *s1, t_list **s2, t_list *t2, int counter2);
void	handle_normal_case(t_list *s1, t_list **s2, t_list *t2, int counter2);
void	handle_first_case(t_list *s1, t_list **s2, t_list *t2, t_list *last);
void	count_move(t_list *s1, t_list **s2);
t_list	*find_target_node(t_list *s2, int index);
int		handle_min_case_a(t_list *s1);
int		handle_normal_case_a(t_list *s1, t_list *t2);
int		index_in_a(t_list *s1, t_list *s2, int index);
int		type_of_moves(int demi1, int demi2, int c1, int c2);
void	two_up(t_list **s1, t_list **s2, int indexa, int indexb);
void	two_down(t_list **s1, t_list **s2, int indexa, int indexb);
void	up_and_down(t_list **s1, t_list **s2, int indexa, int indexb);
void	down_and_up(t_list **s1, t_list **s2, int indexa, int indexb);
void	push_index_to_a(t_list **s1, t_list **s2, int indexa, int indexb);
void	push_b_to_a(t_list **s1, t_list **s2);
int		get_index(t_list *s, int nb);
void	last_sort(t_list **stack1);
void	push_a_to_b(t_list **stack1, t_list **stack2, int size);
void	sort_lst(t_list **stack1, t_list **stack2);

#endif