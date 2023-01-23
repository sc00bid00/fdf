/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_draw.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsordo <lsordo@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 11:18:00 by lsordo            #+#    #+#             */
/*   Updated: 2023/01/18 10:08:42 by lsordo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

int	ft_draw(t_map *m)
{
	m->mlx = mlx_init(WIDTH, HEIGHT, "fdf lsordo 42 Heilbronn", true);
	if (!m->mlx)
		exit(EXIT_FAILURE);
	m->img = mlx_new_image(m->mlx, WIDTH, HEIGHT);
	ft_drawrows(m);
	ft_drawcols(m);
	mlx_image_to_window(m->mlx, m->img, 0, 0);
	mlx_loop_hook(m->mlx, ft_hook, m);
	mlx_loop(m->mlx);
	mlx_delete_image(m->mlx, m->img);
	mlx_terminate(m->mlx);
	return (EXIT_SUCCESS);
}

void	ft_drawrows(t_map *m)
{
	int	r;
	int	c;

	r = 0;
	m->c = 0;
	while (r < m->rows)
	{
		c = 0;
		while (c < m->cols - 1)
		{
			m->c1 = m->c + 1;
			ft_line(m);
			c++;
			m->c++;
		}
		r++;
		m->c++;
		m->c1++;
	}
}

void	ft_drawcols(t_map *m)
{
	int	i;
	int	j;

	i = 0;
	while (i < m->cols)
	{
		j = 0;
		while (j < m->rows - 1)
		{
			m->c = j * m->cols + i;
			m->c1 = (j + 1) * m->cols + i;
			ft_line(m);
			j++;
		}
		i++;
	}
}

void	ft_mlx_put_pixel_b(t_map *m)
{
	if ((m->x >= 0 && m->x < WIDTH) \
		&& (m->y >= 0 && m->y < HEIGHT))
	{
		mlx_put_pixel(m->img, m->x, m->y, m->col);
	}
}
