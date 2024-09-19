/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmimault <tmimault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 13:24:07 by tmimault          #+#    #+#             */
/*   Updated: 2024/09/19 13:53:47 by tmimault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	take_fork(t_philo *philo, t_fork *fork)
{
	pthread_mutex_lock(&fork->mtx);
	while (fork->fork && philo->rule->nb_philo != 1)
	{
		pthread_mutex_unlock(&fork->mtx);
		pthread_mutex_lock(philo->ptr_mtx_meal);
		if (ms_time(NULL) + 1 - philo->lst_eat >= philo->rule->msec_die)
		{
			pthread_mutex_unlock(philo->ptr_mtx_meal);
			ft_usleep(1);
		}
		else
			pthread_mutex_unlock(philo->ptr_mtx_meal);
		pthread_mutex_lock(&fork->mtx);
	}
	fork->fork = 1;
	pthread_mutex_unlock(&fork->mtx);
	mtx_print(philo, "has taken a fork");
}

void	let_fork(t_fork *fork)
{
	pthread_mutex_lock(&fork->mtx);
	fork->fork = 0;
	pthread_mutex_unlock(&fork->mtx);
}

int	set_all_forks(t_table *table)
{
	size_t	i;

	i = 0;
	while (i < table->rules.nb_philo)
	{
		pthread_mutex_init(&table->all_fork[i].mtx, NULL);
		table->all_fork[i].fork = 0;
		i++;
	}
	return (0);
}
