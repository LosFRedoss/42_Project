/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmimault <tmimault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 17:11:40 by tmimault          #+#    #+#             */
/*   Updated: 2024/08/30 02:02:15 by tmimault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int set_all_forks(t_table *table)
{
	size_t i;

	i = 0;
	while (i < table->rules.nb_philo)
	{
		pthread_mutex_init(&table->all_fork[i].mtx, NULL);
		i++;
	}
	return (0);
}

void set_side_fork(t_table *table, t_philo *philo)
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

void set_philo(t_table *table)
{
	size_t	i;

	i = 0;
	pthread_mutex_init(&table->mtx_meal, NULL);
	pthread_mutex_init(&table->mtx_death, NULL);
	while (i < table->rules.nb_philo)
	{
		table->philo[i].index = i + 1;
		table->philo[i].start_time = ms_time(NULL);
		table->philo[i].lst_eat = table->philo[i].start_time;
		set_side_fork(table, &table->philo[i]);
		table->philo[i].rules = &table->rules;
		table->philo[i].death = &table->is_death;
		table->philo[i].ptr_mtx_death = &table->mtx_death;
		table->philo[i].ptr_mtx_meal = &table->mtx_meal;
		i++;
	}
}
/*
 Role du watcher, 

regarder si des philo on depacer leurs temps de repas,
	pour chacun des philos tcheck si lst_time_eat - actuel time < time_limite_eat
		sinon MORT

reagrder si ils ont atteint le nombre de repas,
	si tout les philos->
	
si oui alors mettre la valeur 1 a dead
*/

int set_dead_philo(t_table *table)
{
	pthread_mutex_lock(&table->mtx_death);
	table->is_death = 1;
	pthread_mutex_unlock(&table->mtx_death);
	return (0);
}

int all_eat(t_table *table)
{
	int i;

	i = 0;
	if (table->rules.nb_philo_eat == -1)
		return (0);
	else
		return (-1);
	
}
int too_late(t_table *table)
{
	size_t i;

	i = 0;
//	printf("%zu\n\n\n",table->rules.nb_philo);
	while (i < table->rules.nb_philo)
	{
		pthread_mutex_lock(&table->mtx_meal);
		if (ms_time(NULL) - table->philo[i].lst_eat >= table->rules.msec_die)
		{
			mtx_print(&table->philo[i], "is dead");
			pthread_mutex_unlock(&table->mtx_meal);
			return (1);
		}
		pthread_mutex_unlock(&table->mtx_meal);
		i++;
	}
	return (0);
}

void *watch_all(void *v_table)
{
	t_table *table;

	table = (t_table *) v_table;
	while (1)
	{
		if (too_late(table) || all_eat(table) == 1)
		{
			set_dead_philo(table);
			return (NULL);
		}
	}
}







void *start_philo(void *v_table)
{
	size_t i;
	t_table *table;

	table = v_table;
	i = 0;
//	pthread_mutex_init(&table->mtx_start, NULL);
//	pthread_mutex_lock(&table->mtx_start);
	set_philo(table);
	if (pthread_create(&table->start_watch, NULL, watch_all, table))
		write(2, " error thread", 14);
	while (i < table->rules.nb_philo)
	{
		pthread_create(&table->philo[i].th_philo, NULL, routine_philo, &table->philo[i]);
		i++;
	}
	i = -1;
	while (++i < table->rules.nb_philo)
		pthread_join(table->philo[i].th_philo, NULL);
	pthread_join(table->start_watch, NULL);
//	pthread_mutex_unlock(&table->mtx_start);
	return (NULL);
}

int main (int argc, char **argv)
{
	t_table	table;

	if (test_argv(argc, argv, &table.rules))
		return (1);
	table.all_fork = malloc (sizeof(*table.all_fork) * table.rules.nb_philo);
	set_all_forks(&table);
	table.is_death = -1;
	table.philo = malloc (sizeof(*table.philo) * table.rules.nb_philo + 1);
	if (!table.all_fork || !table.philo)
		return (1);
	start_philo(&table);
/*if (pthread_create(&table.start, NULL, start_philo, &table))
		return (1);
	pthread_join(table.start, NULL);*/
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