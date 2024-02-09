/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmimault <tmimault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 10:28:28 by tmimault          #+#    #+#             */
/*   Updated: 2024/02/09 18:39:37 by tmimault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	test_val(char *value);
int	*test_double_val(int *tab_values, char *char_value, int nb_values);

int	*tester(int *nb_values, char **values)
{
	int	i;
	int	*tab_values;

	i = 0;
	tab_values = NULL;
	if (*nb_values <= 1)
		return (NULL);
	values = use_split(nb_values, values);
	if (!values)
		return (ft_printf("Error\n"), NULL);
	while (i < *nb_values)
	{
		if (test_val(values[i]) == -1)
			return (ft_printf("Error\n"), free(tab_values),
				freeall(values,*nb_values), NULL);
		tab_values = test_double_val(tab_values, values[i], i + 1);
		if (!tab_values)
			return (ft_printf("Error\n"), free(tab_values),
				freeall(values,*nb_values), NULL);
		i++;
	}
	return (freeall(values, *nb_values), tab_values);
}

int	test_val(char *value)
{
	int			i;
	long int	long_val;

	i = 0;
	long_val = ft_atoi_l(value);
	if (value[i] == '-')
	{
		i++;
		if (!value[i])
			return (-1);
	}
	while (value[i])
	{
		if (value[i] < 48 || value[i] > 57)
			return (-1);
		if (long_val > INT_MAX || long_val < INT_MIN)
			return (-1);
		i++;
	}
	return (1);
}

int	*test_double_val(int *tab_values, char *char_value, int nb_values)
{
	int	i;
	int	y;
	int	*nw_tab_values;
	int	int_value;

	i = 0;
	y = 0;
	int_value = (int) ft_atoi_l(char_value);
	while (i < nb_values - 1)
	{
		if (int_value == tab_values[i])
			return (free(tab_values), NULL);
		i++;
	}
	nw_tab_values = malloc (sizeof(int) * (nb_values));
	while (y < nb_values - 1)
	{
		nw_tab_values[y] = tab_values[y];
		y++;
	}
	nw_tab_values[y] = int_value;
	return (free(tab_values), nw_tab_values);
}

char	**use_split(int *nb_values, char **values)
{
	char	**new_values;
	int		i;

	i = 0;
	new_values = NULL;
	while (values[++i])
	{
		new_values = add_value(new_values, ft_split(values[i], ' '), nb_values);
		if (!new_values)
			return (NULL);
	}
	i = 0;
	return (new_values);
}

char	**add_value(char **prev_tab_values, char **split_values, int *nb_value)
{
	char	**new_tab_val;
	int		nb_of_split;
	int		nb_of_prev_tab;
	int		i;

	nb_of_split = 0;
	i = -1;
	nb_of_prev_tab = 0;
	if (!split_values)
		return (free(prev_tab_values), free(split_values), NULL);
	while (split_values[nb_of_split])
		nb_of_split++;
	if (prev_tab_values)
		nb_of_prev_tab = *nb_value;
	new_tab_val = malloc (sizeof(char *) * (nb_of_split + nb_of_prev_tab + 1));
	if (!new_tab_val)
		return (free(prev_tab_values), free(split_values), NULL);
	while (++i < nb_of_prev_tab)
		new_tab_val[i] = prev_tab_values[i];
	i = -1;
	while (++i < nb_of_split)
		new_tab_val[i + nb_of_prev_tab] = split_values[i];
	new_tab_val[nb_of_split + nb_of_prev_tab] = NULL;
	*nb_value = nb_of_split + nb_of_prev_tab;
	return (free(prev_tab_values), free(split_values), new_tab_val);
}
