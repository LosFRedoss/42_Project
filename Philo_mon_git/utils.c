/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmimault <tmimault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 17:35:19 by tmimault          #+#    #+#             */
/*   Updated: 2024/08/29 23:43:56 by tmimault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static long int	signtest(const char *nptr, int *y);

unsigned int	ft_atoi(const char *nptr)
{
	unsigned long int	nbfinal;
	unsigned long int	nbtemp;
	long int			i;
	int					y;

	y = 0;
	nbfinal = 0;
	i = signtest(nptr, &y);
	if (y == 1)
		return(0);
	while (nptr[i] && nptr[i] >= '0' && nptr[i] <= '9')
	{
		nbtemp = nbfinal;
		nbfinal = nbfinal * 10 + (nptr[i] - '0');
		i++;
		if (nbtemp > nbfinal)
			return (0);
	}
	if (y != 0)
		nbfinal = -nbfinal;
	return (nbfinal);
}

static long int	signtest(const char *nptr, int *y)
{
	long int	i;

	i = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == ' ')
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			*y = 1;
		i++;
	}
	return (i);
}

size_t ms_time(t_philo *philo)
{
	struct timeval current_time;
	size_t ms_time;

	if (gettimeofday(&current_time, NULL) == -1)
		write(2,"Error gettime\n", 15);
	ms_time = current_time.tv_sec * 1000 + current_time.tv_usec / 1000;
	if(philo)
		ms_time -= philo->start_time;
	return (ms_time);
}

void ft_usleep(size_t milliseconds)
{
	size_t	start;

	start = ms_time(NULL);
	while ((ms_time(NULL) - start) < milliseconds)
		usleep(50);
}