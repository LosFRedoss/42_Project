/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmimault <tmimault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 19:11:54 by tmimault          #+#    #+#             */
/*   Updated: 2024/02/06 18:30:53 by tmimault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*list_a;
	t_list	*list_b;
	int		*int_list;
	int		i;

	i = 1;
	int_list = tester(&argc, argv);
	if (!int_list)
		return (0);
	list_a = init_list(int_list[0]);
	list_b = NULL;
	while (i < argc)
		add_list(list_a,int_list[i++]);
	free(int_list);
	apply_rules(&list_a, &list_b);
}

void	apply_rules(t_list **list_a, t_list **list_b)
{
	if (if_croissant(*list_a) == 1)
		return;
	start_big_sort(list_a, list_b);
	//print_list(*list_a);
	free_list(*list_b);
	free_list(*list_a);
}
