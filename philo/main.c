/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluis <aluis@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 08:01:05 by aluis             #+#    #+#             */
/*   Updated: 2026/03/22 19:51:51 by aluis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo.h"

/*
* The main is a TL;DR of the program
* input: ./philo 42 400 200 200 [8]
*/
int	main(int argc, char **argv)
{
	t_table	table;

	if (argc == 5 || argc == 6)
	{
		parse_input(&table, argv);
		data_init(&table);
		dinner_start(&table);
		//clean(&table);
	}
	else
	{
		error_exit("ERROR: Wrong input!\n"
			G"A correct exemple is ./philo 5 800 200 200 [42]" RST);
	}
	return (0);
}
