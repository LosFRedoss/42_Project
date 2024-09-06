/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmimault <tmimault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 18:30:13 by tmimault          #+#    #+#             */
/*   Updated: 2024/08/29 23:08:15 by tmimault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int mtx_print(t_philo *philo, char * str)
{
	pthread_mutex_lock(&philo->rules->m_print);
	printf("%li %zi %s\n", ms_time(philo), philo->index, str);
	pthread_mutex_unlock(&philo->rules->m_print);
	return (0);
}

