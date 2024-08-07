/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneekhra <aneekhra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 19:10:33 by aneekhra          #+#    #+#             */
/*   Updated: 2024/07/23 18:21:12 by aneekhra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_arg_content(char *av)
{
	int	i;

	i = 0;
	while (av[i] != '\0')
	{
		if (av[i] < '0' || av[i] > '9')
			return (1);
		i++;
	}
	return (0);
}

int	check_valid_args(char **av)
{
	if (ft_atoi(av[1]) <= 0
		|| check_arg_content(av[1]) == 1)
		return (write(2, "Error: Invalid philosophers number\n", 36), 1);
	if (ft_atoi(av[2]) <= 0 || check_arg_content(av[2]) == 1)
		return (write(2, "Error: Invalid time to die\n", 28), 1);
	if (ft_atoi(av[3]) <= 0 || check_arg_content(av[3]) == 1)
		return (write(2, "Error: Invalid time to eat\n", 27), 1);
	if (ft_atoi(av[4]) <= 0 || check_arg_content(av[4]) == 1)
		return (write(2, "Error: Invalid time to sleep\n", 29), 1);
	if (av[5] && (ft_atoi(av[5]) <= 0 || check_arg_content(av[5]) == 1))
		return (write(2, "Error: Invalid number of times \
				each philosopher must eat\n", 57), 1);
	return (0);
}
