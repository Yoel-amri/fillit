/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-amri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 03:49:37 by yel-amri          #+#    #+#             */
/*   Updated: 2018/11/16 18:57:35 by yel-amri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	char	**tetrisat;
	char	*src;
	int		nb_tetriminos;

	if (argc != 2)
	{
		ft_putstr("usage = ./fillit filename\n");
		return (0);
	}
	nb_tetriminos = ft_count_tetriminos(reddit(argv[1]));
	src = get_data(argv[1]);
	if (src == NULL)
		return (0);
	tetrisat = ft_strsplit(src, '\n');
	if (toto(tetrisat) != 1)
	{
		ft_putstr("error\n");
		return (0);
	}
	tetrisat = function(tetrisat, nb_tetriminos);
	tetrisat = alph_tet(tetrisat);
	solve(tetrisat, nb_tetriminos);
	return (0);
}
