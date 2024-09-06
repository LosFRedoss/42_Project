/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmimault <tmimault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 19:25:13 by tmimault          #+#    #+#             */
/*   Updated: 2024/08/30 01:05:22 by tmimault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	test_argv(int argc,char **argv, t_rules *rules)
{

	if (argc < 5 || argc > 6)
	{
		write(2,"Wrong number of arguments!\n",28);
		return (1);
	}
	rules->nb_philo = ft_atoi(argv[1]);
	rules->msec_die = ft_atoi(argv[2]);
	rules->msec_eat = ft_atoi(argv[3]);
	rules->msec_sleep = ft_atoi(argv[4]);
	rules->nb_philo_eat = -1;
	rules->nb_total_eat = 0;
	pthread_mutex_init(&rules->m_print, NULL);
	if (argc == 6)
		rules->nb_philo_eat = ft_atoi(argv[5]);
	if (!rules->nb_philo || !rules->msec_die || !rules->msec_eat ||
		!rules->msec_sleep || (argc == 6 && !rules->nb_philo_eat))
	{
		write(2,"Arguments errors!\n",19);
		return (1);
	}
	return (0);
}
