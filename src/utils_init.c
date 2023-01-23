/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsordo <lsordo@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 11:36:47 by lsordo            #+#    #+#             */
/*   Updated: 2023/01/18 14:29:54 by lsordo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

t_map	*ft_initmap(int argc, char **argv)
{
	t_map	*m;

	if (argc != 2)
		exit (EXIT_FAILURE);
	ft_checkname(argv[1]);
	m = malloc(sizeof(t_map));
	if (!m)
		exit(EXIT_FAILURE);
	m->fname = argv[1];
	return (m);
}

void	ft_initvp(t_map *m)
{
	m->v = malloc((m->rows * m->cols) * sizeof(t_vec) * 3);
	if (!m->v)
	{
		free(m);
		exit(EXIT_FAILURE);
	}
	m->p = malloc((m->rows * m->cols) * sizeof(t_pix));
	if (!m->p)
	{
		free(m->v);
		free(m);
		exit(EXIT_FAILURE);
	}
	m->par = malloc(sizeof(t_par));
	if (!m->par)
	{
		free(m->par);
		free(m->v);
		free(m);
		exit(EXIT_FAILURE);
	}
}

void	ft_initpar(t_map *m)
{
	m->par->wsx = 10;
	m->par->wsy = 10;
	m->par->wsz = 2;
	m->par->wtx = 0;
	m->par->wty = 0;
	m->par->wtz = 0;
	m->par->wax = 0;
	m->par->way = 0;
	m->par->waz = 0;
	m->par->asx = 5;
	m->par->asy = 5;
	m->par->asz = 5;
	m->par->atx = 0;
	m->par->aty = 0;
	m->par->atz = 0;
	m->par->aax = m->par->wax;
	m->par->aay = m->par->way;
	m->par->aaz = m->par->waz;
	m->ptype = 0;
	m->xo = 0;
	m->yo = 0;
	m->par->a = 30;
	m->par->b = 120;
}
