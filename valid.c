/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-amri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 01:08:04 by yel-amri          #+#    #+#             */
/*   Updated: 2018/11/16 18:55:15 by yel-amri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**function(char **tetrisat, int nb_tetriminos)
{
	int		i;
	int		j;
	char	tbl[20][15];

	j = 0;
	i = 0;
	valid(tbl, 0);
	while (i < nb_tetriminos)
	{
		j = 0;
		while (j < 19)
		{
			if (ft_mystrstr(tetrisat[i], tbl[j]) == 1)
			{
				ft_strcpy(tetrisat[i], tbl[j]);
				break ;
			}
			j++;
		}
		i++;
	}
	return (tetrisat);
}

void	valid(char tbl[20][15], int i)
{
	while (++i < 20)
	{
		ft_bzero(tbl[i], sizeof(tbl[i]));
	}
	ft_strcpy(tbl[0], "###...#");
	ft_strcpy(tbl[1], "####");
	ft_strcpy(tbl[2], ".#..##..#");
	ft_strcpy(tbl[3], "##...##");
	ft_strcpy(tbl[4], ".#...#..##");
	ft_strcpy(tbl[5], "#...###");
	ft_strcpy(tbl[6], "##..#...#");
	ft_strcpy(tbl[7], ".##.##");
	ft_strcpy(tbl[8], "###.#");
	ft_strcpy(tbl[9], "#...##...#");
	ft_strcpy(tbl[10], "##...#...#");
	ft_strcpy(tbl[11], "..#.###");
	ft_strcpy(tbl[12], "#...#...##");
	ft_strcpy(tbl[13], ".#..###");
	ft_strcpy(tbl[14], "#...##..#");
	ft_strcpy(tbl[15], "###..#");
	ft_strcpy(tbl[16], ".#..##...#");
	ft_strcpy(tbl[17], "##..##");
	ft_strcpy(tbl[18], "#...#...#...#");
}

int		ft_mystrstr(char *tetrisat, char *valid)
{
	int	i;
	int	j;

	i = 0;
	while (tetrisat[i] != '\0')
	{
		j = 0;
		while (tetrisat[i + j] == valid[j])
		{
			if (valid[j + 1] == '\0')
			{
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int		toto(char **tetrisat)
{
	int		i;
	int		j;
	int		count;
	char	tbl[20][15];

	i = 0;
	j = 0;
	count = 0;
	valid(tbl, 0);
	while (tetrisat[i])
	{
		j = 0;
		count = 0;
		while (j < 19)
		{
			if (ft_mystrstr(tetrisat[i], tbl[j]) == 1)
				count++;
			j++;
		}
		if (count != 1)
			return (0);
		i++;
	}
	return (1);
}
