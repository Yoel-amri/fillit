/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-amri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 01:08:04 by yel-amri          #+#    #+#             */
/*   Updated: 2018/11/16 05:57:20 by yel-amri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**new_map(int size)
{
	int		i;
	int		j;
	int		sizeii;
	char	**map;

	sizeii = size + 3;
	map = (char **)malloc(sizeof(char*) * (sizeii + 1));
	ft_bzero(map, sizeii);
	i = -1;
	while (++i < size)
	{
		map[i] = ft_strnew(sizeii);
		j = -1;
		while (++j < size)
			map[i][j] = '.';
	}
	while (i < sizeii)
	{
		map[i] = ft_strnew(sizeii);
		++i;
	}
	map[i] = 0;
	return (map);
}

void	free_map(char **map)
{
	int i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	print_map(char **map, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		ft_putstr(map[i]);
		ft_putchar('\n');
		i++;
	}
}

int		init_map(int nb_tetriminos)
{
	int i;
	int blocks;

	i = 0;
	blocks = nb_tetriminos * 4;
	while (i * i < blocks)
	{
		i++;
	}
	return (i);
}

void	delete_map(char **map)
{
	size_t	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		++i;
	}
	free(map);
}
