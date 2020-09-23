/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msole <msole@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 16:41:03 by msole             #+#    #+#             */
/*   Updated: 2019/09/24 13:14:31 by msole            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl(char const *str)
{
	int index;

	index = 0;
	if (str)
	{
		while (str[index] != '\0')
		{
			ft_putchar(str[index]);
			++index;
		}
		ft_putchar('\n');
	}
}
