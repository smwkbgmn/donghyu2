/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_semaphore.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 23:45:42 by donghyu2          #+#    #+#             */
/*   Updated: 2023/08/31 00:39:40 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	do_sem(sem_t *key, t_switch in);

sem_t	*init_sem(char *name, t_uint value)
{
	sem_t	*ptr;

	ptr = sem_open(name, O_CREAT | O_EXCL, 777, value);
	if (ptr == (sem_t *)ERROR)
		exit_with_error("sem_open");
	return (ptr);
}

void	del_semaphore(t_uint cnt)
{
	t_uint	idx;
	char	*name;

	sem_unlink("EATING");
	sem_unlink("DEATH");
	sem_unlink("PRINT");
	sem_unlink("FORK_L");
	sem_unlink("FORK_R");

	idx = 0;
	while (idx < cnt)
	{
		name = ft_itoa(idx + 1);
		sem_unlink(name);
		idx++;
	}
}

void	semaphore(t_list *data, t_keyname name, t_switch in)
{
	if (name < 5)
		do_sem(data->share->key[name], in);
	else
		do_sem(data->philo->info.key_timer, in);
}

static void	do_sem(sem_t *key, t_switch in)
{
	if (in)
	{
		if (sem_wait(key) == ERROR)
			exit_with_error("sem_wait");
	}
	else
		if (sem_post(key) == ERROR)
			exit_with_error("sem_post");
}
