/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myerturk <myerturk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 17:59:44 by myerturk          #+#    #+#             */
/*   Updated: 2024/05/03 15:42:40 by myerturk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>

typedef struct s_philosopher
{
	int				id;
	int				x_ate;
	int				left_fork_id;
	int				right_fork_id;
	long long		last_dinner_time;
	struct s_rules	*rules;
	pthread_t		thread_id;
}					t_philosopher;

typedef struct s_rules
{
	int				nb_philo;
	int				death_drtion;
	int				eat_duration;
	int				sleep_duration;
	int				nb_eat;
	int				all_ate;
	int				dieded;
	long long		first_timestamp;
	pthread_mutex_t	t_last_meal_check;
	pthread_mutex_t	x_ate_check;
	pthread_mutex_t	dieded_check;
	pthread_mutex_t	all_ate_check;
	pthread_mutex_t	*forks;
	t_philosopher	*philosophers;
}					t_rules;

/*
** ----- utils2.c -----
*/

int					write_error(char *str);
void				eat_control(t_rules *r, t_philosopher *p);
void				ft_free(t_rules *rules);
void				action_print(t_rules *rules, int id, char *string);
void				philo_eats(t_philosopher *philo);
/*
** ----- init.c -----
*/

int					parse_to_values(t_rules *rules, char **argv);
int					philo_init(t_rules *rules);
int					init_mutex(t_rules *rules);

/*
** ----- utils.c -----
*/

int					ft_atoi(const char *str);
int					ft_isdigit(char **array);
long long			timestamp(void);
long long			time_diff(long long past, long long pres);
void				smart_sleep(long long time, t_rules *rules);

/*
** ----- launcher.c -----
*/

int					philo_main(t_rules *rules);
void				exit_launcher(t_rules *rules, t_philosopher *philos);

int					destroy_mutex(t_rules *rules);
void				chose_mutex(t_rules *rules, int x);

#endif
