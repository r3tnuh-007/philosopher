/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_status.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluis <aluis@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 18:30:11 by aluis             #+#    #+#             */
/*   Updated: 2026/03/22 20:00:35 by aluis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static void	write_status_debug(t_philo_status status,
				t_philo *philo, long elapsed)
{
	if (TAKE_FIRST_FORK == status && !simulation_finished(philo -> table))
		printf(W"%-6ld"RST" %d has taken the 1º fork"
			"\t\t\tnº"B"[%d]\n"RST, elapsed, philo -> id,
			philo -> first_fork -> fork_id);
	if (TAKE_SECOND_FORK == status && !simulation_finished(philo -> table))
		printf(W"%-6ld"RST" %d has taken the 2º fork"
			"\t\t\tnº"B"[%d]\n"RST, elapsed, philo -> id,
			philo -> second_fork -> fork_id);
	else if (EATING == status && !simulation_finished(philo -> table))
		printf(W"%-6ld"C" %d is eating"
			"\t\t\t"Y"[%ld]\n"RST, elapsed, philo -> id,
			philo -> meals_counter);
	else if (SLEEPING == status && !simulation_finished(philo -> table))
		printf(W"%-6ld"RST" %d is sleeping\n", elapsed, philo -> id);
	else if (THINKING == status && !simulation_finished(philo -> table))
		printf(W"%-6ld"RST" %d is thinking\n", elapsed, philo -> id);
	else if (DIED == status)
		printf(RED"\t\t%6ld %d died\n"RST, elapsed, philo -> id);

}

void	write_status(t_philo_status status, t_philo *philo, bool debug)
{
	long	elapsed;

	if (philo -> full)
		return ;
	elapsed = gettime(MILLISECOND);
	if (debug)
		write_status_debug(status, philo, elapsed);
	else
	{
		safe_mutex_handle(&philo -> table -> write_mutex, LOCK);
		if ((TAKE_FIRST_FORK == status || TAKE_SECOND_FORK == status)
			&& !simulation_finished(philo -> table))
			printf(W"%-6ld"RST" %d has taken a fork\n", elapsed, philo -> id);
		else if (EATING == status && !simulation_finished(philo -> table))
			printf(W"%-6ld"C" %d is eating\n"RST, elapsed, philo -> id);
		else if (SLEEPING == status && !simulation_finished(philo -> table))
			printf(W"%-6ld"RST" %d is sleeping\n", elapsed, philo -> id);
		else if (THINKING == status && !simulation_finished(philo -> table))
			printf(W"%-6ld"RST" %d is thinking\n", elapsed, philo -> id);
		else if (DIED == status)
			printf(RED"%-6ld %d died\n"RST, elapsed, philo -> id);
	}
	safe_mutex_handle(&philo -> table -> write_mutex, UNLOCK);
}
