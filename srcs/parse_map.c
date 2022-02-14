/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: operculesanguinaire <operculesanguinair    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 15:15:40 by kcatrix           #+#    #+#             */
/*   Updated: 2022/02/14 16:08:55 by operculesan      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	stock_map(t_data *img)
{
	int fd;
	int i;
	int j;
	char **str;
	char *s;
	
	i = 0;
	fd = open("map/map.ber", O_RDONLY);
	while (get_next_line(fd, &s))
	{
		if (s != NULL)
			free(s);
		i++;
	}
	img->nombredeligne = i;
	close(fd);
	str = malloc(sizeof(char *) * i);
	j = 0;
	fd = open("map/map.ber", O_RDONLY);
	while(j < i)
	{
		str[j] = get_next_line(fd, &str[j]);
		j++;
	}
	j = 0;
	close(fd);
	if (verif_ligne_first(str, img) == 0)
		return(0);
	return (1);
}

int	verif_ligne_first(char **str, t_data *img)
{
	int i;
	
	i = 0;
	while(str[0][i] != '\n' && str[0][i])
	{
		if (str[0][i] != '1')
		{
			printf("erreur sur la premiere ligne");
			return(0);
		}
		i++;
	}
	img->nombredecarct = i;
	img->map = str;
	if (verif_ligne_last(str, img) == 0)
		return (0);
	return (1);
}

int	verif_ligne_last(char **str, t_data *img)
{
	int j;
	int i;

	i = 0;
	j = img->nombredeligne;
	while (str[j - 1][i])
	{
		if (str[j - 1][i] != '1')
		{
			printf("erreur sur la derniere ligne");
			return(0);
		}
		i++;
	}
	if (verif_wall(str, img) == 0)
		return (0);	
	return(1);
}

int	verif_wall(char **str, t_data *img)
{
	int i;
	int y;

	i = 0;
	y = 0;
	while(i < img->nombredeligne)
	{
		if (str[i][0] != '1')
		{
			printf("erreur de mur");
			return (0);
		}
		if (str[i][img->nombredecarct - 1] != '1')
		{
			printf("erreur de mur");
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
	int i;
	int y;

	i = 0;
	y = 0;
	while (i < img->nombredeligne)
	{
		while(str[i][y] != '\n' && str[i][y])
		{
			if (y >= img->nombredecarct)
			{
				printf("erreur nombre de caractere par ligne");
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