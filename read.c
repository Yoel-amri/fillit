/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-amri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 01:08:04 by yel-amri          #+#    #+#             */
/*   Updated: 2018/11/16 18:56:59 by yel-amri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_afe(char *s, int i, int dotcount, int hashcount)
{
	int	nlcount;

	if (s[i] != '.' && s[i] != '#')
		return (1);
	while (s[i])
	{
		dotcount = 0;
		hashcount = 0;
		nlcount = 0;
		while (!(s[i] == '\n' && s[i + 1] == '\n'))
		{
			if (s[i] == '\n' && s[i + 1] == '\0')
				break ;
			dotcount = (s[i] == '.') ? dotcount + 1 : dotcount;
			hashcount = (s[i] == '#') ? hashcount + 1 : hashcount;
			nlcount = (s[i] == '\n') ? nlcount + 1 : nlcount;
			if (s[i] != '.' && s[i] != '#' && s[i] != '\n')
				return (1);
			i++;
		}
		if (dotcount != 12 || hashcount != 4 || nlcount != 3)
			return (1);
		i = (s[i] && s[i + 1] && s[i + 2]) ? i + 2 : i + 1;
	}
	return (0);
}

char	*get_data(char *filename)
{
	char	*s;

	s = reddit(filename);
	if (ft_afe(s, 0, 0, 0) != 0)
	{
		ft_putstr("error\n");
		return (NULL);
	}
	s = ft_peace(s);
	return (s);
}

char	*reddit(char *filename)
{
	int		fd;
	int		i;
	int		ret;
	char	*s;
	char	buffer[BUF_SIZE];

	s = (char *)malloc(sizeof(char) * (BUF_SIZE + 1));
	i = 0;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr("error file/n");
		return (0);
	}
	while ((ret = read(fd, buffer, 1)))
	{
		s[i] = buffer[0];
		i++;
	}
	s[i] = '\0';
	close(fd);
	return (s);
}

char	*ft_peace(char *s)
{
	int		i;
	int		j;
	int		k;
	int		nb_tetriminos;
	char	*tmp;

	i = 0;
	k = ft_strlen(s);
	j = 0;
	nb_tetriminos = ft_count_tetriminos(s);
	tmp = ft_strnew(k);
	while (i < k)
	{
		if (s[i] == '\n')
			i++;
		tmp[j] = s[i];
		i++;
		j++;
	}
	tmp[j] = '\0';
	return (tmp);
}
