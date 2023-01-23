/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsordo <lsordo@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 09:53:04 by lsordo            #+#    #+#             */
/*   Updated: 2023/01/18 14:34:48 by lsordo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <fcntl.h>
# include <stdlib.h>
# include <stdint.h>
# include <unistd.h>
# include <libft.h>
# include <get_next_line.h>
# include <math.h>
# include <stdio.h>
# include <glfw3.h>
# include <MLX42.h>

# define WIDTH 1000
# define HEIGHT 500
# define FOCAL_DISTANCE 80

typedef struct s_pix
{
	int			x;
	int			y;
	uint32_t	col;
}				t_pix;

typedef struct s_vec
{
	float		x;
	float		y;
	float		z;
}				t_vec;

typedef struct s_vrt
{
	t_vec	local;
	t_vec	world;
	t_vec	aligned;
}			t_vrt;

typedef struct s_par
{
	float	asx;
	float	asy;
	float	asz;
	float	atx;
	float	aty;
	float	atz;
	float	aax;
	float	aay;
	float	aaz;
	float	wsx;
	float	wsy;
	float	wsz;
	float	wtx;
	float	wty;
	float	wtz;
	float	wax;
	float	way;
	float	waz;
	int		xo;
	int		yo;
	float	a;
	float	b;
}		t_par;

typedef struct s_map
{
	int			c;
	int			c1;
	int			fd;
	char		*fname;
	int			cols;
	int			rows;
	int			min_x;
	int			min_y;
	int			max_x;
	int			max_y;
	int			min_z;
	int			max_z;
	int			xo;
	int			yo;
	t_vrt		*v;
	t_pix		*p;
	int			x;
	int			y;
	int			t;
	int			dx;
	int			dy;
	int			incx;
	int			incy;
	int			pdx;
	int			pdy;
	int			ddx;
	int			ddy;
	int			deltaslowdirection;
	int			deltafastdirection;
	int			err;
	int			col;
	int			ptype;
	mlx_t		*mlx;
	mlx_image_t	*img;
	t_par		*par;
}				t_map;

void	ft_adjustcol(t_map *m, char *s);
void	ft_align(t_map *map);
void	ft_checkname(char *s);
void	ft_close(t_map *m);
void	ft_decrangle(float	*angle);
void	ft_direction(t_map *m);
int		ft_draw(t_map *m);
void	ft_drawcols(t_map *m);
void	ft_drawinit(t_map *m);
void	ft_drawrows(t_map *m);
void	ft_exit(t_map *m);
void	ft_extpx(t_map *m);
void	ft_extz(t_map *m);
void	ft_freesplit(char **arr);
void	ft_helpcalc(t_map *m);
void	ft_hook(void *param);
void	ft_incrangle(float	*angle);
t_map	*ft_initmap(int argc, char **argv);
void	ft_initpar(t_map *m);
void	ft_initvp(t_map *m);
void	ft_isometry_col(t_map *m);
void	ft_line(t_map *m);
void	ft_mcopy(float src[4][4], float dst[4][4]);
void	ft_mident(float m[4][4]);
void	ft_mlx_put_pixel_b(t_map *m);
void	ft_mmult(float m1[4][4], float m2[4][4], float dst[4][4]);
void	ft_mnull(float m[4][4]);
void	ft_mrotate(float m[4][4], float ax, float ay, float az);
void	ft_mscale(float m[4][4], float sx, float sy, float sz);
void	ft_mtraslate(float m[4][4], float tx, float ty, float tz);
void	ft_negctrl(t_map *m);
void	ft_newimage(t_map *m);
void	ft_open(t_map *m);
void	ft_parse(t_map *m);
void	ft_perspective(t_map *m);
void	ft_posadjust(t_map *m);
void	ft_posctrl(t_map *m);
void	ft_position(t_map *m);
void	ft_project(t_map *m);
void	ft_pxcalc(t_map *m);
float	ft_rad(int d);
void	ft_rot(t_map *m);
void	ft_scale(t_map *m);
void	ft_stretchz(t_map *m);
void	ft_trasl(t_map *m);
void	ft_vmmult(t_vec	*src, float m[4][4], t_vec *dst);
void	ft_world(t_map *map);
int		sgn(int x);
void	ft_topdown(t_map *m);

#endif
