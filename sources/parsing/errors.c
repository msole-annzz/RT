/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msole <msole@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 19:23:15 by msole             #+#    #+#             */
/*   Updated: 2020/07/30 13:43:31 by msole            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rtv1.h"

void	read_error(void)
{
	write(1, "There are some problems with readding file\n", 45);
	exit(1);
}

void	memory_allocation_error(void)
{
	write(1, "There are some problems with memory allocation\n", 48);
	exit(1);
}

void	file_error(void)
{
	write(1, "Please, add one file: ./RTv1 <file_name>\n", 42);
	exit(1);
}

void	file_contents_error(void)
{
	write(1, "There is an error in the text of the file\n", 42);
	exit(1);
}

void	empty_file_error(char *str, char *buf)
{
	free(str);
	free(buf);
	write(1, "This file is empty\n", 20);
	exit(1);
}
