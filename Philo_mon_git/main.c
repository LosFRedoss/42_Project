/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmimault <tmimault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 17:11:40 by tmimault          #+#    #+#             */
/*   Updated: 2024/09/19 13:24:50 by tmimault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	set_side_fork(t_table *table, t_philo *philo)
{
	if (philo->index == 1)
	{
		philo->fork_right = &table->all_fork[philo->index - 1];
		philo->fork_left = &table->all_fork[table->rules.nb_philo - 1];
	}
	else
	{
		philo->fork_right = &table->all_fork[philo->index - 1];
		philo->fork_left = &table->all_fork[philo->index - 2];
	}
}

void	set_philo(t_table *table)
{
	size_t	i;

	i = 0;
	pthread_mutex_init(&table->mtx_meal, NULL);
	pthread_mutex_init(&table->mtx_death, NULL);
	pthread_mutex_init(&table->mtx_start, NULL);
	while (i < table->rules.nb_philo)
	{
		table->philo[i].index = i + 1;
		set_side_fork(table, &table->philo[i]);
		table->philo[i].rule = &table->rules;
		table->philo[i].death = &table->is_death;
		table->philo[i].ptr_mtx_death = &table->mtx_death;
		table->philo[i].ptr_mtx_meal = &table->mtx_meal;
		table->philo[i].ptr_mtx_start = &table->mtx_start;
		table->philo[i].start_time = ms_time(NULL);
		table->philo[i].lst_eat = table->philo[i].start_time;
		i++;
	}
}

int	start_philo(void *v_table)
{
	size_t	i;
	t_table	*table;

	table = v_table;
	i = 0;
	set_philo(table);
	if (pthread_create(&table->start_watch, NULL, watch_all, table))
		return (free_all(table, -1));
	pthread_mutex_lock(&table->mtx_start);
	while (i < table->rules.nb_philo)
	{
		if (pthread_create(&table->philo[i].th_philo, NULL,
				routine_philo, &table->philo[i]))
		{
			pthread_mutex_unlock(&table->mtx_start);
			return (free_all(table, i));
		}
		i++;
	}
	pthread_mutex_unlock(&table->mtx_start);
	i = -1;
	while (++i < table->rules.nb_philo)
		pthread_join(table->philo[i].th_philo, NULL);
	pthread_join(table->start_watch, NULL);
	return (0);
}

int	main(int argc, char **argv)
{
	t_table	table;

	if (test_argv(argc, argv, &table.rules))
		return (1);
	table.all_fork = malloc (sizeof(*table.all_fork) * table.rules.nb_philo);
	if (!table.all_fork)
		return (1);
	set_all_forks(&table);
	table.is_death = -1;
	table.philo = malloc (sizeof(*table.philo) * table.rules.nb_philo);
	if (!table.philo)
	{
		free(table.all_fork);
		return (1);
	}
	if (start_philo(&table))
		return (1);
	free(table.all_fork);
	free(table.philo);
	return (0);
}

/*

Ordre : Eat -> Sleep -> Think

temp de eat et sleep definie
think apres sleep jusqu'a qu'ils puissent eat de nouveaux

ordre des tour :

philo prend fourchettes (d'apres une fonction)

si il a ses deux fourchettes (fork[0] == true && fork[1] == true)
	eat 
		sleep(time_to_eat - (lst_eat - time_stand));
		lst_eat = time_stand;
	fin eat
		 	unlock_mutex(fork_left)
			unlock_mutex(fork_right);
quand il attend ses fourchettes il think; 


sleep = duree prevue de sleep - duree deja passe;






*/