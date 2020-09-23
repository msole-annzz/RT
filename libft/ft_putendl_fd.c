/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msole <msole@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 11:14:21 by msole             #+#    #+#             */
/*   Updated: 2019/09/24 13:15:13 by msole            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char const *str, int fd)
{
	int index;

	index = 0;
	if (str)
	{
		while (str[index] != '\0')
		{
			ft_putchar_fd(str[index], fd);
			++index;
		}
		ft_putchar_fd('\n', fd);
	}
}
