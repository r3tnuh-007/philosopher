/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner_start.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluis <aluis@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 11:15:36 by aluis             #+#    #+#             */
/*   Updated: 2026/03/22 21:13:00 by aluis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static void	thinking(t_philo *philo)
{
	write_status(THINKING, philo, DEBUG_MODE);
}

static void	eat(t_philo *philo)
{
	safe_mutex_handle(&philo -> first_fork -> fork, LOCK);
	write_status(TAKE_FIRST_FORK, philo, DEBUG_MODE);
	safe_mutex_handle(&philo -> second_fork -> fork, LOCK);
	write_status(TAKE_SECOND_FORK, philo, DEBUG_MODE);
	set_long(&philo -> philo_mutex, &philo -> last_meal_time,
			gettime(MILLISECOND));
	philo -> meals_counter ++;
	write_status(EATING, philo, DEBUG_MODE);
	precise_usleep(philo -> table -> time_to_eat, philo -> table);
	if (philo -> table -> nbr_limit_meals > 0
		&& philo -> meals_counter == philo -> table -> nbr_limit_meals)
		set_bool(&philo -> philo_mutex, &philo -> full, true);
	safe_mutex_handle(&philo -> first_fork -> fork, UNLOCK);
	safe_mutex_handle(&philo -> second_fork -> fork, UNLOCK);
}

/*
 * 0) wait all philos, synchro start
 *
 * 1) endless loop philo
 *
 *
 */
void	*dinner_simulation(void *data)
{
	t_philo	*philo;

	philo = (t_philo * ) data;
	wait_all_threads(philo -> table);
	set_long(&philo -> philo_mutex,
		&philo -> last_meal_time, gettime(MILLISECOND));
	increase_long(&philo -> table -> table_mutex,
		&philo -> table -> threads_running_nbr);
	while (!simulation_finished(philo -> table))
	{
		if (philo -> full)
			break ;
		eat(philo);
		write_status(SLEEPING, philo, DEBUG_MODE);
		precise_usleep(philo -> table -> time_to_sleep, philo -> table);
		thinking(philo);
	}
	return (NULL);
}

/*
 * actual meat
 * ./philo 5 800 200 200 [6]
 *
 * 0) if no meals, return [0]
 * 0.1) if only one philo -> ad hoc function
 * 1) create all threads, all philos
 * 2) create a monitor thread -> check if a philo is dead
 * 3) sychronize the  begginning of the simulation
 * 		pthread_create -> philo starts runnning!
 * 		eevery philo start simultaneosly
 * 4) JOIN everyone
 */
void	dinner_start(t_table *table)
{
	int	i;

	i = -1;
	if (table -> nbr_limit_meals == 0)
		return ;
	else if (table -> philo_nbr == 1)
		; // to do
	else
	{
		while (++ i < table -> philo_nbr)
			safe_thread_handle(&table -> philos[i].thread_id, dinner_simulation,
					&table -> philos[i], CREATE);
	}
	safe_thread_handle(&table -> monitor, monitor_dinner, table, CREATE);
	table -> start_simulations = gettime(MILLISECOND);
	set_bool(&table -> table_mutex, &table -> all_threads_ready, true);
	i = -1;
	while (++ i < table -> philo_nbr)
		safe_thread_handle(&table -> philos[i].thread_id, NULL, NULL, JOIN);

}
