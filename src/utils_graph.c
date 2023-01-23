/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_graph.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsordo <lsordo@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 12:13:43 by lsordo            #+#    #+#             */
/*   Updated: 2023/01/18 10:07:25 by lsordo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// source: https://de.wikipedia.org/wiki/Bresenham-Algorithmus
#include <fdf.h>

int	sgn(int x)
{
	if (x > 0)
		return (1);
	if (x < 0)
		return (-1);
	return (0);
}

void	ft_direction(t_map *m)
{
	if (m->dx > m->dy)
	{
		m->pdx = m->incx;
		m->pdy = 0;
		m->ddx = m->incx;
		m->ddy = m->incy;
		m->deltaslowdirection = m->dy;
		m->deltafastdirection = m->dx;
	}
	else
	{
		m->pdx = 0;
		m->pdy = m->incy;
		m->ddx = m->incx;
		m->ddy = m->incy;
		m->deltaslowdirection = m->dx;
		m->deltafastdirection = m->dy;
	}
}

void	ft_drawinit(t_map *m)
{
	m->dx = m->p[m->c1].x - m->p[m->c].x;
	m->dy = m->p[m->c1].y - m->p[m->c].y;
	m->incx = sgn(m->dx);
	m->incy = sgn(m->dy);
	if (m->dx < 0)
		m->dx = -(m->dx);
	if (m->dy < 0)
		m->dy = -(m->dy);
}

void	ft_pxcalc(t_map *m)
{
	m->t = 0;
	while (m->t < m->deltafastdirection)
	{
		m->err -= m->deltaslowdirection;
		if (m->err < 0)
		{
			m->err += m->deltafastdirection;
			m->x += m->ddx;
			m->y += m->ddy;
		}
		else
		{
			m->x += m->pdx;
			m->y += m->pdy;
		}
		ft_mlx_put_pixel_b(m);
		m->t++;
	}
}

void	ft_line(t_map *m)
{
	ft_drawinit(m);
	ft_direction(m);
	m->x = m->p[m->c].x;
	m->y = m->p[m->c].y;
	m->err = m->deltafastdirection / 2;
	m->col = m->p[m->c].col;
	ft_mlx_put_pixel_b(m);
	ft_pxcalc(m);
}
