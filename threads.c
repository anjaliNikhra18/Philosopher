/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneekhra <aneekhra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 11:31:40 by aneekhra          #+#    #+#             */
/*   Updated: 2024/07/23 18:24:21 by aneekhra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//dead_loop function checks regularly if a philo is dead
//If he's dead : the associated mutex is unlocked, the 
//function returns 1 (abnormal behaviour)
//If he's not dead : the mutex is unlocked, the functions
//returns 0 (normal behaviour)
int	dead_loop(t_philo *philo)
{
	pthread_mutex_lock(philo->dead_lock);
	if (*philo->dead == 1)
	{
		pthread_mutex_unlock(philo->dead_lock);
		return (1);
	}
	pthread_mutex_unlock(philo->dead_lock);
	return (0);
}

int	thread_create(t_prog *program, pthread_mutex_t *forks)
{
	pthread_t	observer;
	int			i;

	if (pthread_create(&observer, NULL, &monitor, program->philos) != 0)
		destroy_all("Thread creation error", program, forks);
	i = 0;
	while (i < program->philos[0].num_of_philos)
	{
		if (pthread_create(&program->philos[i].thread, NULL, &philo_routine,
				&program->philos[i]) != 0)
			destroy_all("Thread creation error", program, forks);
		i++;
	}
	i = 0;
	if (pthread_join(observer, NULL) != 0)
		destroy_all("Thread join error", program, forks);
	while (i < program->philos[0].num_of_philos)
	{
		if (pthread_join(program->philos[i].thread, NULL) != 0)
			destroy_all("Thread join error", program, forks);
		i++;
	}
	return (0);
}
