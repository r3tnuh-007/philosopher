/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluis <aluis@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 09:14:32 by aluis             #+#    #+#             */
/*   Updated: 2026/05/17 13:27:12 by aluis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils.h"

void	clean(t_table *table)
{
	t_philo	*philo;
	int		i;

	i = -1;
	while (++ i < table -> philo_nbr)
	{
		philo = table -> philos + i;
		safe_mutex_handle(&philo -> philo_mutex, DESTROY);
	}
	safe_mutex_handle(&table -> write_mutex, DESTROY);
	safe_mutex_handle(&table -> table_mutex, DESTROY);
	free(table -> forks);
	free(table -> philos);
}
