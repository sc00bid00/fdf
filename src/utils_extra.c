/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_extra.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsordo <lsordo@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 11:44:41 by lsordo            #+#    #+#             */
/*   Updated: 2023/01/18 14:59:17 by lsordo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	ft_perspective(t_map *m)
{
	int	i;

	i = 0;
	while (i < m->rows * m->cols)
	{
		if (!m->v[i].aligned.z)
			m->v[i].aligned.z = 1;
		m->p[i].x = FOCAL_DISTANCE * m->v[i].aligned.x \
			/ m->v[i].aligned.z;
		m->p[i].y = FOCAL_DISTANCE * m->v[i].aligned.y \
			/ m->v[i].aligned.z;
		i++;
	}
}

void	ft_stretchz(t_map *m)
{
	if (mlx_is_key_down(m->mlx, MLX_KEY_LEFT_SHIFT))
	{
		if (mlx_is_key_down(m->mlx, MLX_KEY_P))
			m->par->wsz -= 0.05;
	}
	else
		m->par->wsz += 0.05;
}

void	ft_isometry_col(t_map *m)
{
	int			i;
	uint32_t	n;
	int			dz;

	ft_extz(m);
	dz = (m->max_z - m->min_z);
	if (dz == 0)
		dz = 1;
	i = 0;
	while (i < m->rows * m->cols)
	{
		m->p[i].x = m->v[i].aligned.x * cos(ft_rad(m->par->a)) \
			+ m->v[i].aligned.y * cos(ft_rad(m->par->a + 120)) \
			+ m->v[i].aligned.z * cos(ft_rad(m->par->a - 120)) + m->xo;
		m->p[i].y = m->v[i].aligned.x * sin(ft_rad(m->par->a)) \
			+ m->v[i].aligned.y * sin(ft_rad(m->par->a + 120)) \
			+ m->v[i].aligned.z * sin(ft_rad(m->par->a - 120)) + m->yo;
		n = 0XFF * (m->v[i].local.z - m->min_z) / dz;
		n = n << 16;
		m->p[i].col = 0XFF0000FF | n;
		i++;
	}
}

void	ft_extz(t_map *m)
{
	m->min_z = 0;
	m->max_z = 0;
	m->c = 0;
	while (m->c < m->rows * m->cols)
	{
		if (m->min_z > m->v[m->c].local.z)
			m->min_z = m->v[m->c].local.z;
		if (m->max_z < m->v[m->c].local.z)
			m->max_z = m->v[m->c].local.z;
		m->c++;
	}
}

void	ft_helpcalc(t_map *m)
{
	ft_world(m);
	ft_align(m);
	ft_extpx(m);
}
