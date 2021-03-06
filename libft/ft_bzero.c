/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bzero.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-amri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 03:06:54 by yel-amri          #+#    #+#             */
/*   Updated: 2018/10/21 08:31:55 by yel-amri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*p;

	p = (unsigned char*)s;
	i = 0;
	if (n != 0)
	{
		while (i < n)
		{
			p[i] = 0;
			i++;
		}
	}
}
