/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsordo <lsordo@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 16:17:29 by lsordo            #+#    #+#             */
/*   Updated: 2023/01/18 15:11:29 by lsordo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	ft_helphook_2(t_map *m)
{
	m->ptype = 0;
	ft_initpar(m);
	ft_position(m);
}

void	ft_helphook(t_map *m)
{
	ft_initpar(m);
	m->ptype = 2;
	ft_position(m);
}

void	ft_hook(void *param)
{
	t_map	*m;

	m = param;
	if (mlx_is_key_down(m->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(m->mlx);
	else if (mlx_is_key_down(m->mlx, MLX_KEY_0))
		ft_helphook_2(m);
	else if (mlx_is_key_down(m->mlx, MLX_KEY_9))
	{
		ft_initpar(m);
		m->ptype = 1;
		ft_position(m);
	}
	else if (mlx_is_key_down(m->mlx, MLX_KEY_LEFT_SHIFT))
		ft_negctrl(m);
	else if (mlx_is_key_down(m->mlx, MLX_KEY_5))
		ft_helphook(m);
	else
	{
		ft_posctrl(m);
		return ;
	}
	ft_newimage(m);
}

void	ft_newimage(t_map *m)
{
	ft_memset(m->img->pixels, 0, WIDTH * HEIGHT * 4);
	ft_world(m);
	ft_align(m);
	ft_project(m);
	ft_drawrows(m);
	ft_drawcols(m);
	mlx_image_to_window(m->mlx, m->img, 0, 0);
}
