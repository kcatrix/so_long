/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcatrix <kcatrix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 11:09:03 by kevyn             #+#    #+#             */
/*   Updated: 2022/02/09 11:40:04 by kcatrix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	parse(t_data *img, char *arg)
{
	if(avance(img , arg) == 0)
	{
		write(1, "erreur dans le nom de la map", 28);
		return(0);
	}
	return(1);
}

int	avance(t_data *img, char *arg)
{
	int i;

	i = 0;
	while(arg[i])
	{
		if(arg[i] == '.')
		{
			if (verif_ber(arg, i) == 0)
				return 0;
		}
		i++;
	}
	return 1;
}

int	verif_ber(char *arg, int i)
{
	int j;
	int f;

	f = 0;
	j = i;
	while(arg[i])
	{
		i++;
		f++;
	}
	if(f > 4)
		return 0;
	if (arg[++j] != 'b')
		return 0;
	if (arg[++j] != 'e')
		return 0;
	if (arg[++j] != 'r')
		return 0;
	return(1);
}


/*void	stock_map(t_data *img)
{
	int fd;
	int i;
	int j;
	char **str;
	
	i = 0;
	
	fd = open("map/map.ber", O_RDONLY);
	while(get_next_line(fd))
		i++;
	i = img->nombredeligne;
	close(fd);
	str = malloc(sizeof(char *) * i);
	j = 0;
	fd = open("map/map.ber", O_RDONLY);
	while(j < i)
	{
		str[j] = get_next_line(fd);
		j++;
	}
	printf("%s", str[0]);
	printf("%s", str[1]);
}*/