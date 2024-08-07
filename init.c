/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneekhra <aneekhra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 19:09:09 by aneekhra          #+#    #+#             */
/*   Updated: 2024/07/23 18:25:29 by aneekhra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_input(t_philo *philo, char **av)
{
	int	num_times;

	philo->num_of_philos = ft_atoi(av[1]);
	philo->time_to_die = ft_atoi(av[2]);
	philo->time_to_eat = ft_atoi(av[3]);
	philo->time_to_sleep = ft_atoi(av[4]);
	if (av[5])
	{
		num_times = ft_atoi(av[5]);
		if (num_times <= 0 || check_arg_content(av[5]))
		{
			write(2, "Error: Invalid number of times each \
				philosopher must eat\n", 57);
			exit(EXIT_FAILURE);
		}
		philo->num_times_to_eat = num_times;
	}
	else
		philo->num_times_to_eat = -1;
}

void	init_prog(t_prog *program, t_philo *philos)
{
	program->dead_flag = 0;
	program->philos = philos;
	if (pthread_mutex_init(&program->write_lock, NULL) != 0 || \
		pthread_mutex_init(&program->dead_lock, NULL) != 0 || \
		pthread_mutex_init(&program->meal_lock, NULL) != 0)
	{
		write(2, "Error: Failed to initialize mutex locks\n", 39);
		exit(EXIT_FAILURE);
	}
}

void	init_philos(t_philo *philos, t_prog *program, pthread_mutex_t *forks,
		char **av)
{
	int	i;
	int	num_philos;

	i = 0;
	num_philos = ft_atoi(av[1]);
	while (i < num_philos)
	{
		philos[i].id = i + 1;
		philos[i].eating = 0;
		philos[i].meals_eaten = 0;
		init_input(&philos[i], av);
		philos[i].dead = &program->dead_flag;
		philos[i].last_meal = get_current_time();
		philos[i].start_time = get_current_time();
		philos[i].write_lock = &program->write_lock;
		philos[i].dead_lock = &program->dead_lock;
		philos[i].meal_lock = &program->meal_lock;
		philos[i].l_fork = &forks[i];
		if (i == 0)
			philos[i].r_fork = &forks[philos[i].num_of_philos - 1];
		else
			philos[i].r_fork = &forks[i - 1];
		i++;
	}
}

void	init_forks(pthread_mutex_t *forks, int num_philo)
{
	int	i;

	i = 0;
	while (i < num_philo)
	{
		pthread_mutex_init(&forks[i], NULL);
		i++;
	}
}
