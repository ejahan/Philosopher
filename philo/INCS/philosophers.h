/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejahan <ejahan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 00:09:58 by ejahan            #+#    #+#             */
/*   Updated: 2022/03/17 15:53:17 by ejahan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct s_data
{
	int				error;
	int				number_of_philosophers;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				exist;
	int				number_of_times_each_philosopher_must_eat;
	pthread_mutex_t	mutex_death;
	int				death;
	pthread_mutex_t	mutex_enough;
	int				enough;
	pthread_mutex_t	*fork;
	pthread_t		check_death;
}	t_data;

typedef struct s_philo
{
	pthread_t			thread;
	int					nb;
	pthread_mutex_t		mutex_nb_of_meal;
	int					nb_of_meal;
	int					fork_right;
	int					fork_left;
	pthread_mutex_t		mutex_time;
	long long int		time;
	pthread_mutex_t		mutex_last_meal;
	long long int		time_last_meal;
	t_data				*data;
}	t_philo;

typedef struct s_struct
{
	t_data	data;
	t_philo	*philo;
}	t_struct;

long			ft_atoi(const char *str);
int				ft_isdigit(int c);
void			*fonction(void *data);
t_philo			*init_philo(t_struct *all);
void			parsing(int ac, char **av, t_data *data);
void			start_philo(int nb, t_struct *all);
long long int	get_time(long long int start_time);
int				philo_eat(t_philo *philo, int nb);
int				philo_sleep(t_philo *philo, int nb);
int				check_death_or_time(t_philo *philo);
void			*check_death(void *arg);
int				check_all_philo_meal(t_struct *all);
int				check_philo_dead(t_struct *all, int i);
void			init_time(t_philo *philo);

#endif
