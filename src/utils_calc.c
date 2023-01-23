/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_calc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsordo <lsordo@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 17:08:52 by lsordo            #+#    #+#             */
/*   Updated: 2023/01/18 10:14:31 by lsordo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	ft_world(t_map *map)
{
	float	mat[4][4];
	int		i;

	ft_mident(mat);
	ft_mscale(mat, map->par->wsx, map->par->wsy, map->par->wsz);
	ft_mrotate(mat, map->par->wax, map->par->way, map->par->waz);
	ft_mtraslate(mat, map->par->wtx, map->par->wty, map->par->wtz);
	i = 0;
	while (i < map->rows * map->cols)
	{
		ft_vmmult(&map->v[i].local, mat, &map->v[i].world);
		i++;
	}
}

void	ft_align(t_map *map)
{
	float	mat[4][4];
	int		i;

	ft_mident(mat);
	ft_mscale(mat, map->par->asx, map->par->asy, map->par->asz);
	ft_mrotate(mat, map->par->aax, map->par->aay, map->par->aaz);
	ft_mtraslate(mat, map->par->atx, map->par->aty, map->par->atz);
	i = 0;
	while (i < map->rows * map->cols)
	{
		ft_vmmult(&map->v[i].world, mat, &map->v[i].aligned);
		i++;
	}
}

void	ft_extpx(t_map *m)
{
	ft_project(m);
	m->min_x = 0;
	m->min_y = 0;
	m->max_x = 0;
	m->max_y = 0;
	m->c = 0;
	while (m->c < m->rows * m->cols)
	{
		if (m->p[m->c].x < m->min_x)
			m->min_x = m->p[m->c].x;
		if (m->p[m->c].y < m->min_y)
			m->min_y = m->p[m->c].y;
		if (m->p[m->c].x > m->max_x)
			m->max_x = m->p[m->c].x;
		if (m->p[m->c].y > m->max_y)
			m->max_y = m->p[m->c].y;
		m->c++;
	}
}

void	ft_posadjust(t_map *m)
{
	int	dx;
	int	dy;

	dx = abs(m->max_x) + abs(m->min_x);
	dy = abs(m->max_y) + abs(m->min_y);
	m->xo = (WIDTH - dx) / 2 + abs(m->min_x);
	m->yo = (HEIGHT - dy) / 2 + abs(m->min_y);
}

void	ft_position(t_map *m)
{
	float	f;
	float	x;
	float	y;

	f = 0;
	ft_helpcalc(m);
	x = (abs(m->max_x) + abs(m->min_x));
	y = (abs(m->max_y) + abs(m->min_y));
	if (x > WIDTH || y > HEIGHT)
	{
		if (x / WIDTH > y / HEIGHT)
			f = x / WIDTH;
		else
			f = y / HEIGHT;
		m->par->wsx /= f;
		m->par->wsy /= f;
		m->par->wsz /= f;
		ft_helpcalc(m);
	}
	ft_posadjust(m);
	ft_helpcalc(m);
}
