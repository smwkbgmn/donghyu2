/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 21:54:32 by donghyu2          #+#    #+#             */
/*   Updated: 2024/01/05 09:35:28 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_obj	*sphere(t_point center, t_scl radius, t_mtral mtral);

int	main(void)
{
	// t_scl	R = cos(PI / 4);

	t_mtral	mtral_ground = material(LMBRT, color(0.8, 0.8, 0.0));
	t_mtral	mtral_center = material(LMBRT, color(0.7, 0.3, 0.3));
	t_mtral	mtral_left = material(METAL, color(0.8, 0.8, 0.8));
	t_mtral	mtral_right = material(METAL, color(0.8, 0.6, 0.2));

	t_list	*objs = NULL;

	// ft_lstadd_back(&objs, ft_lstnew(new_sphere(point(0, 0, -1), 0.5)));
	// ft_lstadd_back(&objs, ft_lstnew(new_sphere(point(0, -100.5, -1), 100)));

	// ft_lstadd_back(&objs, ft_lstnew(new_sphere(point(-R, 0, -1), R)));
	// ft_lstadd_back(&objs, ft_lstnew(new_sphere(point(R, 0, -1), R)));

	ft_lstadd_back(&objs, ft_lstnew(sphere(point(0.0	,-100.5	,-1.0	), 100.0, mtral_ground)));
	ft_lstadd_back(&objs, ft_lstnew(sphere(point(0.0	,0.0	,-1.0	), 0.5, mtral_center)));
	ft_lstadd_back(&objs, ft_lstnew(sphere(point(-1.0	,0.0	,-1.0	), 0.5, mtral_left)));
	ft_lstadd_back(&objs, ft_lstnew(sphere(point(1.0	,0.0	,-1.0	), 0.5, mtral_right)));

	t_camera	cam = camera(16.0 / 9.0, 400, 90, 10, 50);

	render(objs, &cam);
	
	return (EXIT_SUCCESS);
}

t_obj	*sphere(t_point center, t_scl radius, t_mtral mtral)
{
	t_obj	*sp = ft_calloc(1, sizeof(t_obj));

	sp->name = SPHERE;
	sp->val.cir.center = center;
	sp->val.cir.radius = radius;
	sp->mtral = mtral;
	return (sp);
}
