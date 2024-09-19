/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   watcher.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmimault <tmimault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 19:54:53 by tmimault          #+#    #+#             */
/*   Updated: 2024/09/19 14:32:53 by tmimault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
 Role du watcher, 

regarder si des philo on depacer leurs temps de repas,
	pour chacun des philos tcheck si lst_time_eat - actuel time < time_limite_eat
		sinon MORT

reagrder si ils ont atteint le nombre de repas,
	si tout les philos->
	
si oui alors mettre la valeur 1 a dead
*/

int	set_dead_philo(t_table *table)
{
	pthread_mutex_lock(&table->mtx_death);
	table->is_death = 1;
	pthread_mutex_unlock(&table->mtx_death);
	return (0);
}

size_t	count_all_meal(t_table *table)
{
	size_t	i_ph;
	size_t	all_meal;

	i_ph = 0;
	all_meal = 0;
	while (i_ph < table->rules.nb_philo)
	{
		pthread_mutex_lock(&table->mtx_meal);
		all_meal += table->philo[i_ph].nb_meal;
		pthread_mutex_unlock(&table->mtx_meal);
		i_ph++;
	}
	return (all_meal / table->rules.nb_philo);
}

int	all_eat(t_table *table)
{
	size_t	nb_philo_eat;

	if (table->rules.nb_philo_eat < 0)
		return (0);
	nb_philo_eat = (size_t) table->rules.nb_philo_eat;
	if (count_all_meal(table) == nb_philo_eat)
	{
		mtx_print(&table->philo[0], "eat everything");
		return (1);
	}
	return (0);
}

int	too_late(t_table *table)
{
	size_t	i;

	i = 0;
	while (i < table->rules.nb_philo)
	{
		pthread_mutex_lock(&table->mtx_meal);
		if (ms_time(NULL) - table->philo[i].lst_eat >= table->rules.msec_die)
		{
			pthread_mutex_unlock(&table->mtx_meal);
			mtx_print(&table->philo[i], "is dead");
			return (1);
		}
		pthread_mutex_unlock(&table->mtx_meal);
		i++;
	}
	return (0);
}

void	*watch_all(void *v_table)
{
	t_table	*table;

	table = (t_table *) v_table;
	while (1)
	{
		if (too_late(table) || all_eat(table))
		{
			set_dead_philo(table);
			return (NULL);
		}
	}
}
