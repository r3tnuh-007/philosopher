/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluis <aluis@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 07:46:25 by aluis             #+#    #+#             */
/*   Updated: 2026/03/22 20:45:48 by aluis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <pthread.h>
# include <sys/time.h>
# include <limits.h>
# include <errno.h>
# include "utils.h"

/*
 * ANSI Escape sequences for bold text colors
 * Usage:
 * 		printf(RED "This will be red" RST);
 * The RST will reset the color after setting it.
 *
 * RST -> restors
 * RED -> red
 * G -> green
 * Y -> yellow
 * B -> blue
 * M -> magenta
 * C -> cyan
 * W -> white
 */
# define RST	"\033[0m"
# define RED	"\033[1;31m"
# define G		"\033[1;32m"
# define Y		"\033[1;33m"
# define B		"\033[1;34m"
# define M		"\033[1;35m"
# define C		"\033[1;36m"
# define W		"\033[1;37m"

# define DEBUG_MODE 1

/*
 * creation of an alias for the mutex variable
 */
typedef pthread_mutex_t	t_mtx;

typedef enum e_opcode	t_opcode;
typedef enum e_status	t_philo_status;

/*
 * declaration of the table structure
 */
typedef struct s_table	t_table;

typedef struct s_fork
{
	t_mtx	fork;
	int		fork_id;
}			t_fork;

typedef struct s_philo
{
	int			id;
	long		meals_counter;
	bool		full;
	long		last_meal_time;
	t_fork		*first_fork;
	t_fork		*second_fork;
	pthread_t	thread_id;
	t_table		*table;
	t_mtx		philo_mutex;
}				t_philo;

struct s_table
{
	long		philo_nbr;
	long		time_to_die;
	long		time_to_eat;
	long		time_to_sleep;
	long		nbr_limit_meals;
	long		start_simulations;
	long		threads_running_nbr;
	bool		end_simulation;
	bool		all_threads_ready;
	pthread_t	monitor;
	t_mtx		table_mutex;
	t_mtx		write_mutex;
	t_fork		*forks;
	t_philo		*philos;
};

void	safe_mutex_handle(t_mtx *mutex, t_opcode opcode);
void	safe_thread_handle(pthread_t *thread, void *(*foo)(void *),
			void *data, t_opcode opcode);
void	set_bool(t_mtx *mutex, bool *dest, bool value);
bool	get_bool(t_mtx *mutex, bool *value);
void	set_long(t_mtx *mutex, long *dest, long value);
long	get_long(t_mtx *mutex, long *value);
bool	simulation_finished(t_table *table);
void	wait_all_threads(t_table *table);
void	dinner_start(t_table *table);
void	*monitor_dinner(void *data);
void	increase_long(t_mtx *mutex, long *value);
void	write_status(t_philo_status status, t_philo *philo, bool debug);

#endif
