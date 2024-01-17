/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmimault <tmimault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 23:21:16 by tmimault          #+#    #+#             */
/*   Updated: 2024/01/17 19:06:14 by tmimault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <stdint.h> 

typedef struct s_element
{
	int	content;
	struct s_element	*next;
}			t_element;

typedef struct s_list
{
	struct s_element	*first;
}			t_list;

long int	ft_atoi_l(const char *nptr);
int			ft_strcmp(const char *s1, const char *s2);
int			*tester(int *nb_values, char **values);
void		*ft_calloc(size_t nmemb, size_t size);
void		apply_rules(t_list **list_a, t_list **list_b);
void		swap(t_list *list);
void		swap_ty(char type, t_list **list_a, t_list **list_b);
void		push_ty(char type, t_list **list_a, t_list **list_b);
void		free_list(t_list *list);
void		print_list(t_list *list);
t_list		*init_list(int elem_int);
t_list		*add_list(t_list *list, int elem_int);
void		rotate(t_list *list);
void		rev_rotate(t_list *list);
void		rotate_ty(char type, t_list **list_a, t_list **list_b);
char		**use_split(int *nb_values,char **values);
char		**ft_split(char const *s, char c);
char		**add_value(char **prev_tab_values, char **split_values, int *nb_value);


#endif