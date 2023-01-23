/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsordo <lsordo@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 11:11:18 by lsordo            #+#    #+#             */
/*   Updated: 2023/01/17 15:21:27 by lsordo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	ft_open(t_map *m)
{
	m->fd = open(m->fname, O_RDONLY, S_IRUSR);
	if (m->fd == -1)
	{
		ft_printf("Open() failed\n");
		free(m);
		exit(EXIT_FAILURE);
	}
}

void	ft_close(t_map *m)
{
	if (close(m->fd) == -1)
	{
		ft_printf("Close() failed\n");
		free(m);
		exit(EXIT_FAILURE);
	}
}

void	ft_checkname(char *s)
{
	char	*str;

	str = s + ft_strlen(s) - 4;
	if (ft_strncmp(str, ".fdf", 4))
	{
		ft_printf("Open failed()\n");
		exit(EXIT_FAILURE);
	}
}

void	ft_decrangle(float	*angle)
{
	if (*angle > 0)
		(*angle)--;
	else
		*angle = 360;
}

void	ft_incrangle(float	*angle)
{
	if (*angle < 360)
		(*angle)++;
	else
		*angle = 0;
}
