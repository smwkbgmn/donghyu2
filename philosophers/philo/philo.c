/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 20:12:30 by donghyu2          #+#    #+#             */
/*   Updated: 2023/08/28 15:41:32 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	static t_list	*data;
	static t_vars	program;

	if ((ac == 5 || ac == 6)
		&& validate_input(av + 1))
	{
		init_data(ac, av, &data, &program);
		start_life(data);
		free_data(data);
	}
	return (0);
}
