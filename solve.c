/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-amri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 01:08:04 by yel-amri          #+#    #+#             */
/*   Updated: 2018/11/16 18:58:17 by yel-amri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		is_safe(char **map, char *tetrisat, int x, int y)
{
	int i;
	int initx;

	initx = x;
	i = 0;
	set_helper(initx, i, tetrisat);
	while (*tetrisat != '\0')
	{
		if (i > 3)
		{
			i = 0;
			x = initx;
			y++;
		}
		if (ft_isalpha(*tetrisat) && ft_isalpha(map[y][x]))
			return (0);
		if (map[y][x] != '.' && map[y][x] && *tetrisat != '.')
			return (0);
		if (map[y][x] == '\0' && *tetrisat != '.')
			return (0);
		i++;
		x++;
		tetrisat++;
	}
	return (1);
}

void	set_tetri(char **map, char *tetrisat, int x, int y)
{
	int i;
	int initx;

	initx = x;
	i = 0;
	set_helper(initx, i, tetrisat);
	while (*tetrisat != '\0')
	{
		if (i > 3)
		{
			i = 0;
			y++;
			x = initx;
		}
		if (*tetrisat == '.')
		{
			does(&x, &i);
		}
		if (map[y][x] == '.' && *tetrisat != '.')
		{
			map[y][x] = *tetrisat;
			does(&x, &i);
		}
		tetrisat++;
	}
}

void	remove_t(char **map, char *tetrisat, int x, int y)
{
	char	alph;
	int		i;

	alph = get_letter(tetrisat);
	i = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (i == 4)
				return ;
			if (map[y][x] == alph)
			{
				i++;
				map[y][x] = '.';
			}
			x++;
		}
		y++;
	}
}

int		solve(char **tetrisat, int nb_tetriminos)
{
	char	**map;
	int		map_initsize;

	map_initsize = init_map(nb_tetriminos);
	map = new_map(map_initsize);
	while (lfanid(tetrisat, map, 0, 0) == 0)
	{
		map_initsize++;
		delete_map(map);
		map = new_map(map_initsize);
	}
	print_map(map, map_initsize);
	return (0);
}

int		lfanid(char **tetrisat, char **map, int x, int y)
{
	if (!*tetrisat)
		return (1);
	while (map[y])
	{
		while (map[y][x])
		{
			if (is_safe(map, *tetrisat, x, y) == 1)
			{
				set_tetri(map, *tetrisat, x, y);
				if (lfanid(tetrisat + 1, map, 0, 0) == 1)
					return (1);
				else
					remove_t(map, *tetrisat, x, y);
			}
			x++;
		}
		y++;
		x = 0;
	}
	return (0);
}
