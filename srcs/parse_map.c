/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevyn <kevyn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 15:15:40 by kcatrix           #+#    #+#             */
/*   Updated: 2022/02/21 18:17:12 by kevyn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	stock_map(t_data *img, char *arg)
{
	int		fd;
	int		i;
	char	*s;

	i = 0;
	fd = 0;
	if (test_directory(fd, arg) == 0)
		return (0);
	fd = open(arg, O_RDONLY);
	if (fd == -1)
	{
		printf("map introuvable\n");
		return (0);
	}
	while (get_next_line(fd, &s))
	{
		if (s != NULL)
			free(s);
		i++;
	}
	img->nombredeligne = i;
	close(fd);
	if (stock_map2(i, fd, img, arg) == 0)
		return (0);
	return (1);
}

int	verif_ligne_first(char **str, t_data *img)
{
	int	i;

	i = 0;
	while (str[0][i] != '\n' && str[0][i])
	{
		if (str[0][i] != '1')
		{
			printf("erreur sur la premiere ligne\n");
			return (0);
		}
		i++;
	}
	img->nombredecarct = i;
	img->map = str;
	img->size_img = 32;
	img->x = 0;
	img->z = 0;
	if (verif_ligne_last(str, img) == 0)
		return (0);
	return (1);
}

int	verif_ligne_last(char **str, t_data *img)
{
	int	j;
	int	i;

	i = 0;
	j = img->nombredeligne;
	while (str[j - 1][i])
	{
		if (str[j - 1][i] != '1')
		{
			printf("erreur sur la derniere ligne\n");
			return (0);
		}
		i++;
	}
	if (verif_wall(str, img) == 0)
		return (0);
	return (1);
}

int	verif_wall(char **str, t_data *img)
{
	int	i;
	int	y;

	i = 0;
	y = 0;
	while (i < img->nombredeligne)
	{
		if (str[i][0] != '1')
		{
			printf("erreur de mur\n");
			return (0);
		}
		if (str[i][img->nombredecarct - 1] != '1')
		{
			printf("erreur de mur\n");
			return (0);
		}
		i++;
	}
	if (verif_nbcaract(str, img) == 0)
		return (0);
	return (1);
}

int	verif_nbcaract(char **str, t_data *img)
{
	int	i;
	int	y;

	i = 0;
	y = 0;
	while (i < img->nombredeligne)
	{
		while (str[i][y] != '\n' && str[i][y])
		{
			if (y >= img->nombredecarct)
			{
				printf("erreur nombre de caractere par ligne\n");
				return (0);
			}
			y++;
		}
		y = 0;
		i++;
	}
	if (verif_item(str, img) == 0)
		return (0);
	return (1);
}
