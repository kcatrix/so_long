/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm_extend.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevyn <kevyn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 16:33:35 by kevyn             #+#    #+#             */
/*   Updated: 2022/02/21 17:21:02 by kevyn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	test_directory(int fd, char *arg)
{
	fd = open(arg, O_DIRECTORY);
	if (fd != -1)
	{
		printf("la map est un dossier\n");
		close (fd);
		return (0);
	}
	return (1);
}

int	stock_map2(int i, int fd, t_data *img)
{
	char	**str;
	int		j;

	str = malloc(sizeof(char *) * i);
	j = 0;
	fd = open("map/map.ber", O_RDONLY);
	while (j < i)
	{
		str[j] = get_next_line(fd, &str[j]);
		j++;
	}
	j = 0;
	close(fd);
	if (verif_ligne_first(str, img) == 0)
		return (0);
	return (1);
}

int	verif_item2(t_data *img, char **str)
{
	while (img->i < img->nombredeligne)
	{
		while (str[img->i][img->y] != '\n' && str[img->i][img->y])
		{
			if (verif_item_3(img, str) == 0)
				return (0);
			img->y++;
		}
		img->y = 0;
		img->i++;
	}
	return (1);
}

int	verif_item_3(t_data *img, char **str)
{
	if (str[img->i][img->y] == 'C')
		img->c++;
	if (str[img->i][img->y] == 'E')
		img->e++;
	if (str[img->i][img->y] == 'P')
	{
		img->p++;
		img->fake++;
		img->p_l = img->i;
		img->p_c = img->y;
	}
	if (str[img->i][img->y] != '1' && str[img->i][img->y] != '0'
		&& str[img->i][img->y] != 'P' && str[img->i][img->y] != 'E'
		&& str[img->i][img->y] != 'C')
	{
		printf("caractère non reconnue\n");
		return (0);
	}
	return (1);
}
