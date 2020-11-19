/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-amri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 06:19:54 by yel-amri          #+#    #+#             */
/*   Updated: 2018/11/16 06:21:38 by yel-amri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_count_tetriminos(char *s)
{
	int j;
	int i;

	j = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i + 1] == '\n' && s[i] == '\n')
			j++;
		i++;
	}
	return (j + 1);
}

char	get_letter(char *tetrisat)
{
	int i;

	i = 0;
	while (!ft_isalpha(tetrisat[i]))
	{
		i++;
	}
	return (tetrisat[i]);
}

void	set_helper(int initx, int i, char *tetrisat)
{
	while (*tetrisat == '.')
	{
		i++;
		tetrisat++;
		initx--;
	}
}

void	does(int *x, int *i)
{
	(*x)++;
	(*i)++;
}

char	**alph_tet(char **tetrisat)
{
	int i;
	int j;
	int k;

	k = 0;
	i = 0;
	while (tetrisat[i])
	{
		j = 0;
		while (tetrisat[i][j] != '\0')
		{
			if (tetrisat[i][j] == '#')
				tetrisat[i][j] = 'A' + k;
			j++;
		}
		i++;
		k++;
	}
	return (tetrisat);
}
