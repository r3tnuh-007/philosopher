/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   increase_long.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluis <aluis@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 20:38:37 by aluis             #+#    #+#             */
/*   Updated: 2026/03/22 20:40:31 by aluis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	increase_long(t_mtx *mutex, long *value)
{
	safe_mutex_handle(mutex, LOCK);
	(*value) ++;
	safe_mutex_handle(mutex, UNLOCK);
}
