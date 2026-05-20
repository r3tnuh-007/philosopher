/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_all_threads.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluis <aluis@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 14:05:35 by aluis             #+#    #+#             */
/*   Updated: 2026/05/17 14:47:17 by aluis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	wait_all_threads(t_table *table)
{
	while (!get_bool(&table -> table_mutex, &table -> all_threads_ready))
		;
}

/*
* Monitor busy waits untill
* all threadrs are not running
*/
bool	all_threads_running(t_mtx *mutex, long *threads,
		long philo_nbr)
{
	bool	ret;

	ret = false;
	safe_mutex_handle(mutex, LOCK);
	if (*threads == philo_nbr)
		ret = true;
	safe_mutex_handle(mutex, UNLOCK);
	return (ret);
}

/*
* Increase threads running
* to syncro with monitor*/
void	increase_long(t_mtx *mutex, long *value)
{
	safe_mutex_handle(mutex, LOCK);
	(*value)++;
	safe_mutex_handle(mutex, UNLOCK);
}

/*
* Make the system fair
*/
void	de_sincronize_philos(t_philo *philo)
{
	if (philo -> table -> philo_nbr % 2 == 0)
	{
		if (philo -> id % 2 == 0)
			precise_usleep(3e4, philo -> table);
	}
	else
	{
		if (philo -> id % 2)
			thinking(philo, true);
	}
}
