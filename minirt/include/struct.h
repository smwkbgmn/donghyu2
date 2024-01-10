/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyu2 <donghyu2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 02:30:19 by donghyu2          #+#    #+#             */
/*   Updated: 2024/01/10 10:40:16 by donghyu2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "libft.h"

// # define MIN 0
// # define MAX 1
# define NONE 0

typedef double	t_scl;

/* ELEMENT */
typedef enum e_name	t_name;

typedef struct s_bias3	t_vec;
typedef struct s_bias3	t_uvec;
typedef struct s_bias3	t_point;
typedef struct s_bias3	t_color;
typedef struct s_size	t_size;
typedef struct s_grid	t_grid;
typedef struct s_frame	t_frame;

enum e_name
{
	SPHERE,
	CYLNDR,
	PLANE,
	MT_LMBRT,
	MT_METAL,
	MT_DIELCT,
	MT_LIGHT,
	TX_SOLID,
	TX_CHKER,
	TX_BUMP
};

struct s_bias3
{
	t_scl	x;
	t_scl	y;
	t_scl	z;
};

struct s_size
{
	t_scl	w;
	t_scl	h;
};

struct s_grid
{
	t_vec	w;
	t_vec	h;
};

struct s_frame
{
	t_vec	x;
	t_vec	y;
	t_vec	z;
};

/* MLX */
typedef struct s_window	t_win;

struct s_window
{
	t_size	size;
	void	*mlx;
	void	*ptr;
};

/* VIEW */
typedef struct s_image	t_image;
typedef struct s_camera	t_camera;
typedef struct s_view	t_view;
typedef struct s_scene	t_scene;

struct s_image
{
	t_size	size;
	t_scl	aspect;	// Ratio of img width over height
};

struct s_view
{
	t_point	pxl00;	// Location of pixel 0, 0
	t_grid	pxl;	// Offset to pxl to the right(w) and below(h)
};

struct s_camera
{
	t_point	from;
	// t_point	from; // Point camera is looking from
	t_point	at; // Point camera is looking at
	t_uvec	up; // Camera-relative "up" direction
	t_scl	fov;
	t_frame	frame; // Camera frame vasis vectors
};

struct s_scene
{
	t_camera	cam;
	t_image		img;
	t_view		view;
	t_scl		sample;
	t_scl		depth;
};

/* RAY */
typedef struct s_ray		t_ray;
typedef struct s_interval	t_intvl;
typedef struct s_material	t_mtral;
typedef struct s_texture	t_txtr;
typedef struct s_hit		t_hit;
typedef struct s_equation	t_eqa;

typedef t_bool	(*t_scatter_fp)(const t_mtral *, const t_ray *, const t_hit *, t_color *, t_ray *);
typedef t_color	(*t_value_fp)(const t_txtr *, t_scl, t_scl, const t_point *);

struct s_ray
{
	t_point	origin;
	t_vec	direc;
};

struct s_interval
{
	t_scl	min;
	t_scl	max;
};

struct s_texture
{
	t_color		c1;
	t_color		c2;
	t_scl		inv_scale;
	t_value_fp	value;
};

struct s_material
{
	t_name			name;
	t_txtr			texture;
	t_scatter_fp	scatter;
	// t_color			albedo;
	t_scl			fuzz;
	t_scl			ir; // Index of refraction
};

struct s_hit
{
	t_point			point;
	t_uvec			normal;
	t_scl			t;
	t_scl			tx_u; // Surface coord of the ray-object hit point
	t_scl			tx_v;
	t_bool			face;
	const t_mtral	*mtral;
};

struct s_equation
{
	t_vec	oc;
	t_scl	a;
	t_scl	b_half;
	t_scl	c;
	t_scl	dscr;
};

/* OBJECTS */
typedef struct s_circle		t_circle;
typedef struct s_square		t_square;
typedef struct s_value		t_value;
typedef struct s_obj		t_obj;

typedef t_bool	(*t_hit_fp)(const t_obj *, const t_ray *, t_intvl, t_hit *rec);

struct s_circle
{
	t_point	center;
	t_scl	radius;
};

struct s_square
{
	t_point	point; // A point in palne 
	t_uvec	normal;
	t_vec	u;
	t_vec	v;
	t_scl	d;
	t_vec	w;
};

struct s_value
{
	t_circle	cir;
	t_square	sqr;
	t_uvec		axis;
	t_scl		height;
};

struct s_obj
{
	t_name			name;
	t_value			val;
	t_hit_fp		hit;
	const t_mtral	*mtral;
};

#endif