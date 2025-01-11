/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hettahir <hettahir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 13:16:03 by hettahir          #+#    #+#             */
/*   Updated: 2025/01/07 13:16:04 by hettahir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 7
# endif

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
int		ft_strncmp(const char *s1, const char *s2, size_t n);
long	ft_atoi(const char *s);
t_list	*ft_lstnew(int content);
void	ft_lstadd_back(t_list **lst, t_list *new);
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

int		check_dup(t_list *lst, int c);
int		ft_is_digit(char **str);
int		check_param(char *str);
int		check_error(int ac, char **av);
int		check_dup_and_max_int(t_list *lst, char *str);
int		add_to_stack(t_list **lst, char *str);
t_list	*extract_data(int ac, char **av);
char	*ft_strjoin(char const *s1, char const *s2);
char	*alloc_and_free(char *buffer, char *fake_buffer);
char	*ft_strdup(const char *s1);
int		is_line(char *s);
char	*read_file(int fd, char *buffer);
char	*ft_get_line(char *buffer);
char	*ft_next_line(char *buffer);
int		is_sorted(t_list *s);
int		moves(t_list **s1, t_list **s2);

char	*get_next_line(int fd);

#endif