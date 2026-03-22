/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gettime.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluis <aluis@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 18:02:13 by aluis             #+#    #+#             */
/*   Updated: 2026/03/22 18:12:57 by aluis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

/*
 * Retuen a time according with a time code
 *
 * time code -> SECONDS MILLISECONDS MICROSECONDS
 *
 */
long	gettime(t_time_code time_code)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL))
		error_exit("ERROR: Gettimeofday failed!\n");
	if (SECOND == time_code)
		return (tv.tv_sec + tv.tv_usec / 1e6);
	else if (MILLISECOND == time_code)
		return ((tv.tv_sec * 1e3) + tv.tv_usec / 1e3);
	else if (MICROSECOND == time_code)
		return ((tv.tv_sec * 1e6) + tv.tv_usec);
	else
		error_exit("ERRR: Wrong input to gettime!\n");
	return (1337);
}
