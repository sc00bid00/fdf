/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_project.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsordo <lsordo@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 15:31:51 by lsordo            #+#    #+#             */
/*   Updated: 2023/01/18 15:14:18 by lsordo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	ft_isometry(t_map *m)
{
	int		i;

	i = 0;
	while (i < m->rows * m->cols)
	{
		m->p[i].x = m->v[i].aligned.x * cos(ft_rad(m->par->a)) \
			+ m->v[i].aligned.y * cos(ft_rad(m->par->a + m->par->b)) \
			+ m->v[i].aligned.z * cos(ft_rad(m->par->a - m->par->b)) + m->xo;
		m->p[i].y = m->v[i].aligned.x * sin(ft_rad(m->par->a)) \
			+ m->v[i].aligned.y * sin(ft_rad(m->par->a + m->par->b)) \
			+ m->v[i].aligned.z * sin(ft_rad(m->par->a - m->par->b)) + m->yo;
		i++;
	}
}

void	ft_topdown(t_map *m)
{
	int		i;

	m->par->a = 0;
	m->par->b = 90;
	m->par->wax = 315;
	m->par->way = 0;
	m->par->waz = 0;
	i = 0;
	while (i < m->rows * m->cols)
	{
		m->p[i].x = m->v[i].aligned.x * cos(ft_rad(m->par->a)) \
			+ m->v[i].aligned.y * cos(ft_rad(m->par->a + m->par->b)) \
			+ m->v[i].aligned.z * cos(ft_rad(m->par->a - m->par->b)) + m->xo;
		m->p[i].y = m->v[i].aligned.x * sin(ft_rad(m->par->a)) \
			+ m->v[i].aligned.y * sin(ft_rad(m->par->a + m->par->b)) \
			+ m->v[i].aligned.z * sin(ft_rad(m->par->a - m->par->b)) + m->yo;
		i++;
	}
}

void	ft_project(t_map *m)
{
	if (m->ptype == 0)
		ft_isometry(m);
	else if (m->ptype == 1)
		ft_isometry_col(m);
	else if (m->ptype == 2)
		ft_topdown(m);
	else
		ft_perspective(m);
}
