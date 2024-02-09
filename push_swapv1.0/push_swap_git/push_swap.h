/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmimault <tmimault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 23:21:16 by tmimault          #+#    #+#             */
/*   Updated: 2024/02/09 18:21:30 by tmimault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <stdint.h> 

typedef struct s_element
{
	int					content;
	int					rang;
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
void		rev_rotate_ty(char type, t_list **list_a, t_list **list_b);
void		rotate_ty(char type, t_list **list_a, t_list **list_b);
char		**use_split(int *nb_values, char **values);
char		**ft_split(char const *s, char c);
char		**add_value(char **prev_tab_values,
				char **split_values, int *nb_value);
char		**freeall(char **big_array, size_t ind_array);
int			if_croissant(t_list *list);
void		sort_3(t_list **list_a, t_list **list_b);
void		sort_2(t_list **list_a, t_list **list_b);
int			count_list(t_list *list);
int			if_decroissant(t_list *list);
t_element	*last_elem_list(t_list *list);
int			max_elem_list(t_list *list);
int			min_elem_list(t_list *list);
t_element	*chose_elem_list_place(int plc_elem, t_list *list);
int			start_big_sort(t_list **list_a, t_list **list_b);
int			check_litle_sort(t_list **list_a, t_list **list_b);
void		put_first_b_to_a(int elem_content_b, t_list **list_a,
				t_list **list_b);
int			place_elem_list(int nb_elem, t_list	*list);
void		sort_entire_list(t_list **list, t_list **list_b);
int			betwen_elem_list(int content_elem, t_list *list);
int			betwen_elem_list_b(int content_elem, t_list *list);
int			place_a_rank(int place_a, t_list *list_a);
int			to_b_rank(int content_elem, t_list *list_b);
int			total_rank(int elem_place, int content_elem,
				t_list *list_b, t_list *list_a);
void		move_a_to_b(int elem_place, t_list **list_a, t_list **list_b);
void		move_neg(int s, t_element *elem, t_list **list_a, t_list **list_b);
void		move_pos(int s, t_element *elem, t_list **list_a, t_list **list_b);
void		move_mid(int s, t_element *elem, t_list **list_a, t_list **list_b);
int			cmp_elem_a_to_b(t_list **list_a, t_list **list_b);
int			ft_printf(const char *test, ...);

#endif