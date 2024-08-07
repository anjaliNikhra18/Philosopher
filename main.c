/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneekhra <aneekhra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 19:09:21 by aneekhra          #+#    #+#             */
/*   Updated: 2024/07/03 19:09:24 by aneekhra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_prog			prog;
	t_philo			philos[200];
	pthread_mutex_t	forks[200];

	if (ac != 5 && ac != 6)
		return (write(2, "Wrong argument number\n", 22), 1);
	if (check_valid_args(av))
		return (1);
	init_prog(&prog, philos);
	init_forks(forks, ft_atoi(av[1]));
	init_philos(philos, &prog, forks, av);
	thread_create(&prog, forks);
	destroy_all(NULL, &prog, forks);
	return (0);
}
