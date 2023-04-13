/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_push_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 17:37:46 by donghyu2          #+#    #+#             */
/*   Updated: 2023/04/13 15:40:22 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "push_swap.h"

void	init_stack(t_stack **head, int ac, char **av);

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	av++;

	test_print_input(av);

	init_stack(&a, ac, av);
	sort(&a, &b);

	printf("\n[FINISH]\n");
	test_print_stack(a, b);
}

void	init_stack(t_stack **head, int ac, char **av)
{
	if (ac)
	{
		while (*av)
			ft_stkadd_back(head, ft_stknew(ft_atoi(*(av++))));
	}
}

int	ref(t_stack *stk, int idx)
{
	t_stack	*stk_idx;

	stk_idx = ft_stkidx(stk, idx);
	if (stk_idx)
		return (ft_stkidx(stk, idx)->data);
	else
		return (0);
}