/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmimault <tmimault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 20:52:57 by tmimault          #+#    #+#             */
/*   Updated: 2024/02/02 00:53:59 by tmimault         ###   ########.fr       */
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
				swap_ty('a', list_a, list_a);
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
	swap_ty('a', list_a, list_b);
}
if (type == 'b')
{
	fi_elem = (*list_b)->first->content;
	se_elem = (*list_b)->first->next->content;
	if (fi_elem > se_elem)
		swap_ty('b', list_a, list_b);
}
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
			put_first_a_to_b((*list_a)->first->content,list_a,list_b);
		while (count_list(*list_b) != 0)
			put_first_b_to_a((*list_b)->first->content,list_a,list_b);
		sort_entire_list(list_a, list_b);
	}
	return (1);
}
/*
PROJET GESTION DES RANG POUR OPTIMISER L'AJOUT D'ELEMENT DANS B

int cmp_elem_a_to_b(t_list **list_a, t_list **list_b) // sert a determiner le meilleur rang de la list a et de retourner l'elem avec le meilleur rang
{
	t_element	*temp_a;//element ou je suis dans a
	//t_element	*temp_b;//element ou je suis dans b;
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
		temp_a->rang = rang_elem_a_to_b(elem_place, temp_a->content,list_b);
		if(!elem_rang ||temp_a->rang < elem_rang)
		{
			elem_rang = temp_a->rang;
			final_place = elem_place;
		}
		temp_a = temp_a->next;
	}
	return (final_place);
}*/
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