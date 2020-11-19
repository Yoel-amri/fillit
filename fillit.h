/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-amri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 01:16:39 by yel-amri          #+#    #+#             */
/*   Updated: 2018/11/16 18:59:13 by yel-amri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <fcntl.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"
# include <time.h>
# define BUF_SIZE 700
# define ASCII_ESC 27

char	*reddit(char *filename);
int		ft_afe(char *s, int i, int dotcount, int hashcount);
char	*ft_peace(char *s);
int		is_safe(char **map, char *tetrisat, int x, int y);
void	place_tetri(char **map, char *tetrisat, int x, int y);
char	**new_map(int n);
void	free_map(char **map);
void	remove_t(char **map, char *tetrisat, int x, int y);
int		ft_count_tetriminos(char *s);
char	get_letter(char *tetrisat);
int		init_map(int nb_tetriminos);
int		lfanid(char **tetrisat, char **map, int x, int y);
int		solve(char **tetrisat, int nb_tetriminos);
char	*get_data(char *filename);
void	delete_map(char **map);
char	**alph_tet(char **tetrisat);
char	**function(char **tetrisat, int nb_tetriminos);
int		ft_mystrstr(char *tetrisat, char *valid);
void	valid(char tbl[20][15], int i);
char	*trimnl(char *tetrisat);
void	set_helper(int initx, int i, char *tetrisat);
void	does(int *x, int *i);
void	print_map(char **map, int size);
int		toto(char **tetrisat);

#endif
