/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsordo <lsordo@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 09:52:17 by lsordo            #+#    #+#             */
/*   Updated: 2023/01/18 14:17:30 by lsordo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

int	main(int argc, char **argv)
{
	t_map	*m;

	m = ft_initmap(argc, argv);
	ft_parse(m);
	ft_initpar(m);
	ft_position(m);
	ft_draw(m);
	ft_extpx(m);
	ft_exit(m);
	return (EXIT_SUCCESS);
}
