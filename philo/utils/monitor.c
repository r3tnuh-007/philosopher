/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluis <aluis@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 09:14:32 by aluis             #+#    #+#             */
/*   Updated: 2026/05/17 14:48:05 by aluis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils.h"

/*
*                 time to die
* last_meal_______________________last_meal
*
* maybe philo is full
*
*/
static bool	philo_died(t_philo *philo)
{
	long	elapsed;
	long	t_to_die;

	if (get_bool(&philo -> philo_mutex, &philo -> full))
		return (false);
	elapsed = gettime(MILLISECOND) - get_long(&philo -> philo_mutex,
			&philo -> last_meal_time);
	t_to_die = philo -> table -> time_to_die / 1e3;
	if (elapsed >= t_to_die)
		return (true);
	return (false);
}

void	*monitor_dinner(void *data)
{
	int		i;
	t_table	*table;

	table = (t_table *) data;
	while (!all_threads_running(&table -> table_mutex,
			&table -> threads_running_nbr, table -> philo_nbr))
		;
	while (!simulation_finished(table))
	{
		i = -1;
		while (++i < table -> philo_nbr && !simulation_finished(table))
		{
			if (philo_died(table -> philos + i))
			{
				set_bool(&table -> table_mutex, &table -> end_simulation, true);
				write_status(DIED, table -> philos + i, DEBUG_MODE);
				return (NULL);
			}
		}
	}
	return (NULL);
}
