/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneekhra <aneekhra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 19:18:35 by aneekhra          #+#    #+#             */
/*   Updated: 2024/07/18 11:30:59 by aneekhra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdlib.h>
# include <sys/time.h>
# include <stdio.h>
# include <unistd.h>

typedef struct s_philo
{
	int				id;
	int				eating;
	int				meals_eaten;
	int				num_of_philos;
	int				num_times_to_eat;
	int				*dead;
	size_t			last_meal;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	size_t			start_time;
	pthread_t		thread;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*write_lock;
	pthread_mutex_t	*dead_lock;
	pthread_mutex_t	*meal_lock;
}					t_philo;

typedef struct s_program
{
	int				dead_flag; // 0
	pthread_mutex_t	dead_lock;
	pthread_mutex_t	meal_lock;
	pthread_mutex_t	write_lock;
	t_philo			*philos;// philos
}					t_prog;

//check.c
int		check_arg_content(char *av);
int		check_valid_args(char **av);

//clean.c
void	destroy_all(char *str, t_prog *program, pthread_mutex_t *forks);

//init.c
void	init_input(t_philo *philo, char **av);
void	init_prog(t_prog *program, t_philo *philos);
void	init_philos(t_philo *philos, t_prog *program, pthread_mutex_t *forks,
			char **av);
void	init_forks(pthread_mutex_t *forks, int num_philo);

//monitoring.c
void	print_msg(char *str, t_philo *philo, int id);
int		philosopher_dead(t_philo *philo, size_t time_to_die);
int		check_if_dead(t_philo *philos);
int		check_if_all_ate(t_philo *philos);
void	*monitor(void *pointer);

//routine.c
void	thinking(t_philo *philo);
void	sleeping(t_philo *philo);
void	eating(t_philo *philo);
void	*philo_routine(void *pointer);

//threads.c
int		dead_loop(t_philo *philo);
int		thread_create(t_prog *program, pthread_mutex_t *forks);

//utils.c
int		ft_strlen(char *str);
int		ft_atoi(char *str);
size_t	get_current_time(void);
int		ft_usleep(size_t milliseconds);

#endif
