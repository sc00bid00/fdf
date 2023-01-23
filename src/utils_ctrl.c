/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_ctrl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsordo <lsordo@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 11:49:30 by lsordo            #+#    #+#             */
/*   Updated: 2023/01/18 15:14:06 by lsordo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	ft_rot(t_map *m)
{
	if (mlx_is_key_down(m->mlx, MLX_KEY_LEFT_SHIFT))
	{
		if (mlx_is_key_down(m->mlx, MLX_KEY_Z))
			ft_decrangle(&m->par->wax);
		else if (mlx_is_key_down(m->mlx, MLX_KEY_X))
			ft_decrangle(&m->par->way);
		else if (mlx_is_key_down(m->mlx, MLX_KEY_C))
			ft_decrangle(&m->par->waz);
	}
	else
	{
		if (mlx_is_key_down(m->mlx, MLX_KEY_Z))
			ft_incrangle(&m->par->wax);
		else if (mlx_is_key_down(m->mlx, MLX_KEY_X))
			ft_incrangle(&m->par->way);
		else if (mlx_is_key_down(m->mlx, MLX_KEY_C))
			ft_incrangle(&m->par->waz);
	}
}

void	ft_trasl(t_map *m)
{
	if (mlx_is_key_down(m->mlx, MLX_KEY_LEFT_SHIFT))
	{
		if (mlx_is_key_down(m->mlx, MLX_KEY_A))
			m->par->atx -= 10;
		else if (mlx_is_key_down(m->mlx, MLX_KEY_S))
			m->par->aty -= 10;
		else if (mlx_is_key_down(m->mlx, MLX_KEY_D))
			m->par->atz -= 10;
	}
	else
	{
		if (mlx_is_key_down(m->mlx, MLX_KEY_A))
			m->par->atx += 10;
		else if (mlx_is_key_down(m->mlx, MLX_KEY_S))
			m->par->aty += 10;
		else if (mlx_is_key_down(m->mlx, MLX_KEY_D))
			m->par->atz += 10;
	}
}

void	ft_scale(t_map *m)
{
	if (mlx_is_key_down(m->mlx, MLX_KEY_LEFT_SHIFT) && m->par->asx > 0)
	{
		m->par->asx -= .05;
		m->par->asy -= .05;
		m->par->asz -= .05;
	}
	else
	{
		m->par->asx += .05;
		m->par->asy += .05;
		m->par->asz += .05;
	}
}

void	ft_negctrl(t_map *m)
{
	if (mlx_is_key_down(m->mlx, MLX_KEY_Q))
		ft_scale(m);
	else if (mlx_is_key_down(m->mlx, MLX_KEY_A) \
		|| mlx_is_key_down(m->mlx, MLX_KEY_S) \
		|| mlx_is_key_down(m->mlx, MLX_KEY_D))
		ft_trasl(m);
	else if (mlx_is_key_down(m->mlx, MLX_KEY_Z) \
		|| mlx_is_key_down(m->mlx, MLX_KEY_X) \
		|| mlx_is_key_down(m->mlx, MLX_KEY_C))
		ft_rot(m);
	else if (mlx_is_key_down(m->mlx, MLX_KEY_P))
		ft_stretchz(m);
}

void	ft_posctrl(t_map *m)
{
	if (mlx_is_key_down(m->mlx, MLX_KEY_Q))
		ft_scale(m);
	else if (mlx_is_key_down(m->mlx, MLX_KEY_A) \
		|| mlx_is_key_down(m->mlx, MLX_KEY_S) \
		|| mlx_is_key_down(m->mlx, MLX_KEY_D))
		ft_trasl(m);
	else if (mlx_is_key_down(m->mlx, MLX_KEY_Z) \
		|| mlx_is_key_down(m->mlx, MLX_KEY_X) \
		|| mlx_is_key_down(m->mlx, MLX_KEY_C))
		ft_rot(m);
	else if (mlx_is_key_down(m->mlx, MLX_KEY_P))
		ft_stretchz(m);
	else
		return ;
	ft_newimage(m);
}
