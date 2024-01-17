/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmimault <tmimault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 22:25:45 by tmimault          #+#    #+#             */
/*   Updated: 2024/01/17 15:56:45 by tmimault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

static size_t	count_word(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	if (s[i] != c && s[i] != '\0')
		count++;
	while (s[i])
	{
		if (s[i] == c)
		{
			if (s[i + 1] == c || s[i + 1] == '\0')
				i++;
			else
			{
				count++;
				i++;
			}
		}
		else
			i++;
	}
	return (count);
}

static size_t	lengt_word(char const *s, char c, size_t i)
{
	size_t	count;
	int		stop;

	stop = 0;
	count = 0;
	while (s[i] && stop != 1)
	{
		if (s[i] == c)
			stop = 1;
		else
			count++;
		i++;
	}
	return (count);
}

static char	**freeall(char **big_array, size_t ind_array)
{
	while (ind_array > 0)
	{
		ind_array--;
		free(*(big_array + ind_array));
	}
	free(big_array);
	return (NULL);
}

static char	**split_array(char const *s, char c, char **big_array,
			size_t *ind_array)
{
	size_t	ind_s;
	int		ind_word;
	size_t	lgt_word;

	ind_s = 0;
	while (s[ind_s] && *ind_array != count_word(s, c))
	{
		ind_word = 0;
		while (s[ind_s] == c)
			ind_s++;
		lgt_word = lengt_word(s, c, ind_s);
		big_array[*ind_array] = malloc(sizeof(char) * (lgt_word + 1));
		if (big_array[*ind_array] == (void *)0)
			return (freeall (big_array, *ind_array));
		lgt_word = lgt_word + ind_s;
		while (ind_s < lgt_word && s[ind_s])
		{
			big_array[*ind_array][ind_word++] = s[ind_s];
			ind_s++;
		}
		big_array[*ind_array][ind_word++] = '\0';
		*ind_array = *ind_array + 1;
	}
	big_array[*ind_array] = NULL;
	return (big_array);
}

char	**ft_split(char const *s, char c)
{
	size_t	nb_word;
	char	**big_array;
	size_t	ind_array;

	ind_array = 0;
	nb_word = count_word(s, c);
	big_array = malloc(sizeof(char *) * (nb_word + 1));
	if (big_array == (void *)0)
		return ((void *)0);
	big_array = split_array(s, c, big_array, &ind_array);
	if (big_array == (void *)0)
		return ((void *)0);
	return (big_array);
}
