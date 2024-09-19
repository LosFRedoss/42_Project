/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmimault <tmimault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 16:11:34 by tmimault          #+#    #+#             */
/*   Updated: 2024/09/19 14:28:19 by tmimault         ###   ########.fr       */
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

void	philo_sleep(t_philo *philo)
{
	mtx_print(philo, "is sleeping");
	ft_usleep(philo->rule->msec_sleep);
}

void	philo_think(t_philo *philo)
{
	mtx_print(philo, "is thinking");
}

void	philo_eat(t_philo *philo)
{
	if (philo->rule->nb_philo == 1)
	{
		take_fork(philo, philo->fork_right);
		while (is_dead(philo))
			ft_usleep(5);
		return ;
	}
	take_fork(philo, philo->fork_right);
	take_fork(philo, philo->fork_left);
	mtx_print(philo, "is eating");
	pthread_mutex_lock(philo->ptr_mtx_meal);
	philo->nb_meal += 1;
	philo->lst_eat = ms_time(NULL);
	pthread_mutex_unlock(philo->ptr_mtx_meal);
	ft_usleep(philo->rule->msec_eat);
	let_fork(philo->fork_right);
	let_fork(philo->fork_left);
}

void	*routine_philo(void *v_philo)
{
	t_philo	*philo;

	philo = (t_philo *) v_philo;
	pthread_mutex_lock(philo->ptr_mtx_start);
	pthread_mutex_unlock(philo->ptr_mtx_start);
	if (philo->index % 2 == 0)
		ft_usleep(philo->rule->msec_eat / 2);
	while (is_dead(philo))
	{
		philo_eat(philo);
		philo_sleep(philo);
		philo_think(philo);
	}
	return (NULL);
}
