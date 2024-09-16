/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmimault <tmimault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 16:11:34 by tmimault          #+#    #+#             */
/*   Updated: 2024/09/16 20:06:01 by tmimault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void take_fork(t_philo *philo, t_fork *fork)
{
	pthread_mutex_lock(&fork->mtx);
	mtx_print(philo, "has taken a fork");
	fork->fork = 1;
}
void let_fork(t_fork *fork)
{
	fork->fork = 0;
	pthread_mutex_unlock(&fork->mtx);
}

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
		ft_usleep(philo->rule->msec_sleep);
}

void even_eat(t_philo *philo)
{
		take_fork(philo, philo->fork_right);
		take_fork(philo, philo->fork_left);
		mtx_print(philo, "is eating");
		pthread_mutex_lock(philo->ptr_mtx_meal);
		philo->lst_eat = ms_time(NULL);
		philo->nb_meal += 1;
		pthread_mutex_unlock(philo->ptr_mtx_meal);
		ft_usleep(philo->rule->msec_eat);
		let_fork(philo->fork_right);
		let_fork(philo->fork_left);
}

void odd_eat(t_philo *philo)
{
		take_fork(philo, philo->fork_left);
		take_fork(philo, philo->fork_right);
		mtx_print(philo, "is eating");
		pthread_mutex_lock(philo->ptr_mtx_meal);
		philo->lst_eat = ms_time(NULL);
		philo->nb_meal += 1;
		pthread_mutex_unlock(philo->ptr_mtx_meal);
		ft_usleep(philo->rule->msec_eat);
		let_fork(philo->fork_left);
		let_fork(philo->fork_right);
}

void *routine_philo(void *v_philo)
{
	t_philo *philo;

	philo =(t_philo *) v_philo;
	pthread_mutex_lock(philo->ptr_mtx_start);
	pthread_mutex_unlock(philo->ptr_mtx_start);
	if (philo->index % 2)
		ft_usleep(philo->rule->msec_eat / 2);
	while (is_dead(philo)) // tant que personne n'est mort ou que le nombre de repas total est atteint,
	{
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

