/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmimault <tmimault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 20:52:57 by tmimault          #+#    #+#             */
/*   Updated: 2024/02/07 15:22:25 by tmimault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rang_elem_a_to_b(int a_place, int a_temp, t_list **list_b);

void sort_3(t_list **list_a, t_list **list_b)
{
	int fi_elem;
	int se_elem;
	int th_elem;
	
	fi_elem = (*list_a)->first->content;
	se_elem = (*list_a)->first->next->content;
	th_elem = (*list_a)->first->next->next->content;

	if(fi_elem > se_elem && fi_elem > th_elem)
	{
		rotate_ty('a', list_a, list_b);
		if (se_elem > th_elem)
				swap_ty('a', list_a, list_b);
	}
	else if (fi_elem < th_elem && (fi_elem > se_elem || se_elem > th_elem))
	{
		swap_ty('a', list_a, list_b);
		if(se_elem > th_elem)
			rotate_ty('a', list_a, list_b);
	}
	else if (fi_elem > th_elem)
		rev_rotate_ty('a',list_a,list_b);
}

void sort_2(char type,t_list **list_a, t_list **list_b)
{
	int fi_elem;
	int se_elem;

if (type == 'a')
{
	fi_elem = (*list_a)->first->content;
	se_elem = (*list_a)->first->next->content;
	if(fi_elem > se_elem)
	swap_ty('a', list_a, list_b);
}
if (type == 'b')
{
	fi_elem = (*list_b)->first->content;
	se_elem = (*list_b)->first->next->content;
	if (fi_elem < se_elem)
		swap_ty('b', list_a, list_b);
}
}

int	check_litle_sort(char type, t_list **list_a,t_list **list_b)
{
	int nb_elem_l;

	nb_elem_l = 4;
	if(type == 'a')
	{
		nb_elem_l = count_list(*list_a);
		if (nb_elem_l == 3)
			sort_3(list_a, list_b);
		else if (nb_elem_l == 2)
			sort_2('a',list_a,list_b);
	}
	if (nb_elem_l <= 3)
		return (1);
	else
		return (0);
}

int start_big_sort(t_list **list_a, t_list **list_b)
{
	int i;
	
	i = 0;
	if (check_litle_sort('a',list_a,list_b) == 0)
	{
		push_ty('b', list_a, list_b);
		push_ty('b', list_a, list_b);
		while (check_litle_sort('a',list_a,list_b) == 0)
		{
			move_a_to_b(cmp_elem_a_to_b(list_a,list_b),list_a,list_b);
			push_ty('b',list_a,list_b);
		}	
		//print_list(*list_a);
		//print_list(*list_b);
		//printf("rank_elem_to b = %i",to_b_rank(2,*list_b));
		//printf(" rank_elem_place_a = %i",place_a_rank(1,*list_a));
		//printf("rank_total_elem = %i\n,",total_rank(1,2,*list_a,*list_b));
		while (count_list(*list_b) != 0)
			put_first_b_to_a((*list_b)->first->content,list_a,list_b);
		sort_entire_list(list_a, list_b);
	}
	return (1);
}

void	sort_entire_list(t_list **list, t_list **list_b)
{
	int size_list;
	int	place_start;
	int	min_list;

	size_list = count_list(*list);
	min_list = min_elem_list(*list);
	place_start = place_elem_list(min_list,*list);
	if (place_start > (size_list / 2))
		while ((*list)->first->content != min_list)
			rev_rotate_ty('a', list, list_b);
	else 
		while ((*list)->first->content != min_list)
			rotate_ty('a',list,list_b);
}

//PROJET GESTION DES RANG POUR OPTIMISER L'AJOUT D'ELEMENT DANS B

int cmp_elem_a_to_b(t_list **list_a, t_list **list_b) // sert a determiner le meilleur rang de la list a et de retourner l'elem avec le meilleur rang
{
	t_element	*temp_a;//element ou je suis dans a
	int	elem_place;// place de l'element dans a;
	int elem_rang;// Prix du deplacement pour l'element;
	int	final_place;// place de l'element avec un meilleur rang;

	elem_place = 0;
	elem_rang = 0;
	if (!list_a || !(*list_a))
		return (0);
	temp_a = (*list_a)->first;
	while(temp_a)
	{
		elem_place++;
		temp_a->rang = total_rank(elem_place, temp_a->content,*list_a, *list_b);
		if(!elem_rang || temp_a->rang < elem_rang)
		{
			elem_rang = temp_a->rang;
			final_place = elem_place;
		}
		temp_a = temp_a->next;
	}
	return (final_place);
}

/*int	rang_elem_a_to_b(int elem_place_a, int elem_content_a,t_list **list_b) // determine rang d'un elem de a
{
	t_element *temp_b;
	//t_element *last_elem_b;
	int nb_elem_b;
	int	count_rang;
	
	
	nb_elem_b = count_list(*list_b);
	count_rang = 0;
	if (!list_b || !(*list_b))
		return (0);
	temp_b = (*list_b)->first;
	if (elem_place_a > 1)
	{
		if(nb_elem_b == 2 && if_decroissant(*list_b))
		{
			nb_elem_b += 2;
			if(elem_place_a == 2)
				nb_elem_b--;
		}
	}
	
}

if (place = 1)
	fonction aui deplace le premier element trier dans b
else 
{
	fonction qui deplace element en 1;
}

fonction qui deplace element en premiere position ()

void put_elem_first_place(int place_elem_a, t_list **list_a, t_list **list_b)
{
	
}
*/