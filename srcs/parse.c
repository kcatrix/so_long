/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevyn <kevyn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 11:09:03 by kevyn             #+#    #+#             */
/*   Updated: 2022/02/08 13:28:58 by kevyn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	parse()
{
	int fd;
	int i;
	char *str;
	
	i = 0;
	
	fd = open("map/map.ber", O_RDONLY);
	while(ft_strncmp(get_next_line(fd), "(null)", 6) != 0)
		str = get_next_line(fd);

	printf("%s", str);
	
}