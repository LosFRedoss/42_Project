/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmimault <tmimault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 16:11:34 by tmimault          #+#    #+#             */
/*   Updated: 2024/09/15 05:42:51 by tmimault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_dead(t_philo *philo)
{
	pthread_mutex_lock(philo->ptr_mtx_death);
	if (*philo->death == 1)
	{
		pthread_mutex_unlock(philo->ptr_mtx_death);
		return (0);
	}
	pthread_mutex_unlock(philo->ptr_mtx_death);
	return (1);
}

void philo_think(t_philo *philo)
{
		mtx_print(philo, "is thinking");
}

void philo_sleep(t_philo *philo)
{
		mtx_print(philo, "is sleeping");
		ft_usleep(philo->rules->msec_sleep);
}

void even_eat(t_philo *philo)
{
		pthread_mutex_lock(&philo->fork_right->mtx);
		mtx_print(philo, "has taken a fork");
		pthread_mutex_lock(&philo->fork_left->mtx);
		mtx_print(philo, "has taken a fork");
		mtx_print(philo, "is eating");
		philo->eating = 1;
		pthread_mutex_lock(philo->ptr_mtx_meal);
		philo->lst_eat = ms_time(NULL);
		philo->nb_meal += 1;
		pthread_mutex_unlock(philo->ptr_mtx_meal);
		ft_usleep(philo->rules->msec_eat);
		philo->eating = 0;
		pthread_mutex_unlock(&philo->fork_right->mtx);
		pthread_mutex_unlock(&philo->fork_left->mtx);
}

void odd_eat(t_philo *philo)
{
		pthread_mutex_lock(&philo->fork_left->mtx);
		mtx_print(philo, "has taken a fork");
		pthread_mutex_lock(&philo->fork_right->mtx);
		mtx_print(philo, "has taken a fork");
		mtx_print(philo, "is eating");
		philo->eating = 1;
		pthread_mutex_lock(philo->ptr_mtx_meal);
		philo->lst_eat = ms_time(NULL);
		philo->nb_meal += 1;
		pthread_mutex_unlock(philo->ptr_mtx_meal);
		ft_usleep(philo->rules->msec_eat);
		philo->eating = 0;
		pthread_mutex_unlock(&philo->fork_left->mtx);
		pthread_mutex_unlock(&philo->fork_right->mtx);
}

void *routine_philo(void *v_philo)
{
	t_philo *philo;

	philo =(t_philo *) v_philo;
	while (is_dead(philo)) // tant que personne n'est mort ou que le nombre de repas total est atteint,
	{
		if (philo->index % 2)
			odd_eat(philo);
		else
			even_eat(philo);
		philo_sleep(philo);
		philo_think(philo);
	}
	return (NULL);
}

/*
Dans is_dead,
{
return 1 si Quelqu'un est mort ou nb_repas atteint
il vas just tchecker 
} 



*/

