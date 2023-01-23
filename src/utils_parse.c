/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsordo <lsordo@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 10:05:31 by lsordo            #+#    #+#             */
/*   Updated: 2023/01/18 10:03:08 by lsordo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	ft_adjustcol(t_map *m, char *s)
{
	char	*tmp;

	if (ft_strlen(s) < 10)
		tmp = ft_strjoin(s, "FF");
	else
		tmp = ft_strdup(s);
	m->p[m->c].col = ft_atoi_base(tmp, 16);
	free(tmp);
}

void	ft_ctcols(t_map *m, char **arr)
{
	m->cols = 0;
	while (arr[m->cols])
		m->cols++;
}

void	ft_ctrows(t_map *m)
{
	char	*line;
	char	**arr;
	char	*tmp;

	ft_open(m);
	m->rows = 0;
	while (1)
	{
		line = get_next_line(m->fd);
		if (m->rows == 0)
		{
			tmp = ft_strtrim(line, " \n");
			arr = ft_split(tmp, ' ');
			ft_ctcols(m, arr);
			ft_freesplit(arr);
			free(tmp);
		}
		if (!line)
			break ;
		free (line);
		m->rows++;
	}
	ft_close(m);
}

void	ft_getdata(t_map *m, int row, char **arr)
{
	int		i;
	char	**tmp;

	i = 0;
	while (i < m->cols)
	{
		m->v[m->c].local.x = i;
		m->v[m->c].local.y = row;
		if (ft_strchr(arr[i], ','))
		{
			tmp = ft_split(arr[i], ',');
			m->v[m->c].local.z = ft_atoi(tmp[0]);
			ft_adjustcol(m, tmp[1]);
			ft_freesplit(tmp);
			m->c++;
		}
		else
		{
			m->v[m->c].local.z = ft_atoi(arr[i]);
			m->p[m->c].col = 0XFFFFFFFF;
			m->c++;
		}
		i++;
	}
}

void	ft_parse(t_map *m)
{
	int		i;
	char	*line;
	char	**arr;
	char	*tmp;

	ft_ctrows(m);
	ft_initvp(m);
	ft_open(m);
	m->c = 0;
	i = 0;
	while (i < m->rows)
	{
		line = get_next_line(m->fd);
		tmp = ft_strtrim(line, " \n");
		arr = ft_split(line, ' ');
		ft_getdata(m, i, arr);
		ft_freesplit(arr);
		free(line);
		free(tmp);
		i++;
	}
}
