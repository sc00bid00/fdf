/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_transf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsordo <lsordo@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 16:14:46 by lsordo            #+#    #+#             */
/*   Updated: 2023/01/16 15:32:27 by lsordo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	ft_mscale(float m[4][4], float sx, float sy, float sz)
{
	float	sm[4][4];
	float	m1[4][4];

	ft_mnull(sm);
	sm[0][0] = sx;
	sm[1][1] = sy;
	sm[2][2] = sz;
	sm[3][3] = 1;
	ft_mmult(m, sm, m1);
	ft_mcopy(m1, m);
}

void	ft_mrotate(float m[4][4], float ax, float ay, float az)
{
	float	xm[4][4];
	float	ym[4][4];
	float	zm[4][4];
	float	m1[4][4];
	float	m2[4][4];

	ft_mident(xm);
	ft_mident(ym);
	ft_mident(zm);
	xm[1][1] = cos(ft_rad(ax));
	xm[1][2] = sin(ft_rad(ax));
	xm[2][1] = -sin(ft_rad(ax));
	xm[2][2] = cos(ft_rad(ax));
	ym[0][0] = cos(ft_rad(ay));
	ym[0][2] = -sin(ft_rad(ay));
	ym[2][0] = sin(ft_rad(ay));
	ym[2][2] = cos(ft_rad(ay));
	zm[0][0] = cos(ft_rad(az));
	zm[0][1] = sin(ft_rad(az));
	zm[1][0] = -sin(ft_rad(az));
	zm[1][1] = cos(ft_rad(az));
	ft_mmult(m, ym, m1);
	ft_mmult(m1, xm, m2);
	ft_mmult(m2, zm, m);
}

void	ft_mtraslate(float m[4][4], float tx, float ty, float tz)
{
	float	tm[4][4];
	float	m1[4][4];

	ft_mident(tm);
	tm[3][0] = tx;
	tm[3][1] = ty;
	tm[3][2] = tz;
	ft_mmult(m, tm, m1);
	ft_mcopy(m1, m);
}

float	ft_rad(int d)
{
	float	r;

	r = d / 180.0 * M_PI;
	return (r);
}
