/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_matrix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsordo <lsordo@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 16:24:51 by lsordo            #+#    #+#             */
/*   Updated: 2023/01/12 11:26:21 by lsordo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	ft_mident(float m[4][4])
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (i == j)
				m[i][j] = 1;
			else
				m[i][j] = 0;
			j++;
		}
		i++;
	}
}

void	ft_mnull(float m[4][4])
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			m[i][j] = 0;
			j++;
		}
		i++;
	}
}

void	ft_mcopy(float src[4][4], float dst[4][4])
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			dst[i][j] = src[i][j];
			j++;
		}
		i++;
	}
}

void	ft_mmult(float m1[4][4], float m2[4][4], float dst[4][4])
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			dst[i][j] \
				= m1[i][0] * m2[0][j] \
				+ m1[i][1] * m2[1][j] \
				+ m1[i][2] * m2[2][j] \
				+ m1[i][3] * m2[3][j];
			j++;
		}
		i++;
	}
}

void	ft_vmmult(t_vec	*src, float m[4][4], t_vec *dst)
{
	dst->x
		= src->x * m[0][0] \
		+ src->y * m[1][0] \
		+ src->z * m[2][0] \
		+ m[3][0];
	dst->y
		= src->x * m[0][1] \
		+ src->y * m[1][1] \
		+ src->z * m[2][1] \
		+ m[3][1];
	dst->z
		= src->x * m[0][2] \
		+ src->y * m[1][2] \
		+ src->z * m[2][2] \
		+ m[3][2];
}
