/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluis <aluis@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 08:32:44 by aluis             #+#    #+#             */
/*   Updated: 2026/03/22 11:11:08 by aluis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils.h"

int	is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

int	is_space(char c)
{
	return ((c >= 9 && c <= 13) || 32 == c);
}

/*
* check for negative numbers
* check if the number is legit
* check for INT_MAX
* check for len. INT_MAX len 2.147.483.647
*/
static const char	*valid_input(const char *str)
{
	int			len;
	const char	*number;

	len = 0;
	while (is_space(*str))
		str ++;
	if (*str == '+')
		str ++;
	else if (*str == '-')
		error_exit("ERROR: Only positive numbers allowed\n");
	if (!is_digit(*str))
		error_exit("ERROR: The input is not a correct digit\n");
	number = str;
	while (is_digit(*str ++))
		len ++;
	if (len > 10)
		error_exit("ERROR: The value is too big, INT_MAX is the limit\n");
	return (number);
}

static long	ft_atol(const char *str)
{
	long	num;

	num = 0;
	str = valid_input(str);
	while (is_digit(*str))
		num = (num * 10) + (*str ++ - 48);
	if (num > INT_MAX)
		error_exit("ERROR: The value is too big, INT_MAX is the limit\n");
	return (num);
}

/*
* 1) - confirm if the arguments are actually numbers
* 2) - confirm if they are not greater than the INT_MAX
* 3) - timestamps > 60ms
*/
void	parse_input(t_table *table, char **argv)
{
	table -> philo_nbr = ft_atol(argv[1]);
	table -> time_to_die = ft_atol(argv[2]) * 1e3;
	table -> time_to_eat = ft_atol(argv[3]) * 1e3;
	table -> time_to_sleep = ft_atol(argv[4]) * 1e3;
	if (table -> time_to_die < 6e4
		|| table -> time_to_eat < 6e4
		|| table -> time_to_sleep < 6e4)
		error_exit("ERROR: Use timestamps major than 60ms\n");
	if (argv[5])
		table -> nbr_limit_meals = ft_atol(argv[5]);
	else
		table -> nbr_limit_meals = -1;
}
