/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmimault <tmimault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 17:20:06 by tmimault          #+#    #+#             */
/*   Updated: 2024/09/19 14:27:05 by tmimault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <time.h>
# include <unistd.h>
# include <pthread.h>
# include <stdbool.h>
# include <stdlib.h>
# include <sys/time.h>
# include <stdio.h> // a degager (pour le printf)

typedef struct s_rules
{
	size_t			nb_philo;
	size_t			msec_die;
	size_t			msec_eat;
	size_t			msec_sleep;
	int				nb_philo_eat;
	pthread_mutex_t	m_print;
}				t_rules;

typedef struct s_fork
{
	pthread_mutex_t	mtx;
	int				fork;
}				t_fork;

typedef struct s_philo
{
	pthread_t		th_philo;
	pthread_mutex_t	*ptr_mtx_meal;
	pthread_mutex_t	*ptr_mtx_death;
	pthread_mutex_t	*ptr_mtx_start;
	size_t			index;
	size_t			start_time;
	size_t			lst_eat;
	size_t			eating;
	size_t			nb_meal;
	int				*death;
	struct s_fork	*fork_left;
	struct s_fork	*fork_right;
	struct s_rules	*rule;
}				t_philo;

typedef struct s_table
{
	pthread_t		start_watch;
	pthread_mutex_t	mtx_start;
	pthread_mutex_t	mtx_meal;
	pthread_mutex_t	mtx_death;
	int				is_death;
	struct s_fork	*all_fork;
	struct s_philo	*philo;
	struct s_rules	rules;
}				t_table;

int			test_argv(int argc, char **argv, t_rules *rules);
long int	ft_atolong(const char *nptr);
size_t		ms_time(t_philo *philo);
void		philo_think(t_philo *philo);
void		philo_sleep(t_philo *philo);
void		philo_eat(t_philo *philo);
int			mtx_print(t_philo *philo, char *str);
int			start_philo(void *v_table);
void		*routine_philo(void *v_philo);
void		ft_usleep(size_t milliseconds);
int			is_dead(t_philo *philo);
void		*watch_all(void *v_table);
int			free_all(t_table *table, int nb_create);
void		take_fork(t_philo *philo, t_fork *fork);
void		let_fork(t_fork *fork);
int			set_all_forks(t_table *table);

#endif
